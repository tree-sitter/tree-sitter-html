import XCTest
import SwiftTreeSitter
import TreeSitterHtml

final class TreeSitterHtmlTests: XCTestCase {
    func testCanLoadGrammar() throws {
        let parser = Parser()
        let language = Language(language: tree_sitter_html())
        XCTAssertNoThrow(try parser.setLanguage(language),
                         "Error loading Html grammar")
    }
}
