# Builds the Python binding by compiling C sources into a Python extension module.

from os.path import isdir, join
from platform import system
from subprocess import check_call

from setuptools import Extension, find_packages, setup
from setuptools.command.build import build
from wheel.bdist_wheel import bdist_wheel


class Build(build):
    def run(self):
        # Generate parser from grammar.js (same logic and rationale as build.rs)
        check_call(["tree-sitter", "generate", "--abi", "15"])
        if isdir("queries"):
            dest = join(self.build_lib, "tree_sitter_htmldjango", "queries")
            self.copy_tree("queries", dest)
        super().run()


class BdistWheel(bdist_wheel):
    def get_tag(self):
        python, abi, platform = super().get_tag()
        if python.startswith("cp"):
            python, abi = "cp312", "abi3"
        return python, abi, platform


setup(
    packages=find_packages("bindings/python"),
    package_dir={"": "bindings/python"},
    package_data={
        "tree_sitter_htmldjango": ["*.pyi", "py.typed"],
    },
    ext_package="tree_sitter_htmldjango",
    ext_modules=[
        Extension(
            name="_binding",
            sources=[
                "bindings/python/tree_sitter_htmldjango/binding.c",
                "src/parser.c",
                "src/scanner.c",
            ],
            extra_compile_args=[
                "-std=c11",
                "-fvisibility=hidden",
            ] if system() != "Windows" else [
                "/std:c11",
                "/utf-8",
            ],
            define_macros=[
                ("Py_LIMITED_API", "0x030C0000"),
                ("PY_SSIZE_T_CLEAN", None),
                ("TREE_SITTER_HIDE_SYMBOLS", None),
            ],
            include_dirs=["src"],
            py_limited_api=True,
        )
    ],
    cmdclass={
        "build": Build,
        "bdist_wheel": BdistWheel
    },
)
