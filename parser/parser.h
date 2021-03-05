// parser.h
#pragma once
#include "lexer.h"
#include "ast.h"

class Parser {
public:
    Parser(Lexer& lexer);
    ASTNode* parse();

private:
    Lexer& lexer_;

    ASTNode* parseStatement();
    ASTNode* parseDeclaration();
    ASTNode* parseAssignment();
    ASTNode* parseForLoop();  // New function for for loops.
};

