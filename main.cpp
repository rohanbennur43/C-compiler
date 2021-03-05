#include <iostream>
#include "lexer.h"
#include "parser.h"

int main() {
    std::string code = "int main() { int x = 5; return x; }";

    Lexer lexer(code);
    Parser parser(lexer);

    try {
        ASTNode* root = parser.parse();
        std::cout << "AST created successfully.\n";
        // Additional steps for semantic analysis and code generation can be added here.
        delete root; // Clean up the AST.
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}

