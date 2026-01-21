//! Builds the static library of the grammar to link to the rust binding

fn main() {
    //runs `tree-sitter generate --abi 15` to produce src/parser.c from grammar.js
    //previously, all artifacts were committed to the repository, so this step was unnecessary
    //we choose not to commit artifacts to the repository to ensure mismatches between
    //grammar.js and src/parser.c can't happen and to have smaller diffs
    let status = std::process::Command::new("tree-sitter")
        .args(["generate", "--abi", "15"])
        .status()
        .expect("Failed to run `tree-sitter generate` (is tree-sitter-cli installed?)");
    assert!(status.success(), "`tree-sitter generate` failed");

    //https://doc.rust-lang.org/cargo/reference/build-scripts.html#rerun-if-changed
    //Cargo collects all the rerun-if-changed directives after the build
    //script finishes, then uses them for future builds, not the current one
    println!("cargo:rerun-if-changed=grammar.js");
    println!("cargo:rerun-if-changed=src/scanner.c");
    println!("cargo:rerun-if-changed=src/tag.h");

    let mut c_config = cc::Build::new();
    c_config
        .std("c11")
        .include("src")
        .flag_if_supported("-Wno-sign-compare")
        .flag_if_supported("-Wno-implicit-fallthrough");

    #[cfg(target_env = "msvc")]
    c_config.flag("-utf-8");

    c_config.file("src/parser.c");
    c_config.file("src/scanner.c");
    c_config.compile("tree-sitter-htmldjango");
}
