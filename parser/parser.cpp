// parser.cpp
#include "parser.h"
#include <stdexcept>

Parser::Parser(Lexer& lexer) : lexer_(lexer) {}

ASTNode* Parser::parse() {
    // For simplicity, let's assume the entire code is a single statement.
    return parseStatement();
}

ASTNode* Parser::parseStatement() {
    Token token = lexer_.getNextToken();

    if (token.type == TokenType::KEYWORD) {
        if (token.value == "int") {
            return parseDeclaration();
        } else if (token.value == "for") {
            return parseForLoop();
        }
    } else {
        throw std::runtime_error("Invalid statement");
    }
}

ASTNode* Parser::parseDeclaration() {
    Token identifier = lexer_.getNextToken();
    if (identifier.type == TokenType::IDENTIFIER) {
        Token assignment = lexer_.getNextToken();
        if (assignment.type == TokenType::OPERATOR && assignment.value == "=") {
            Token literal = lexer_.getNextToken();
            if (literal.type == TokenType::LITERAL) {
                // Create an ASTNode for the declaration.
                return new DeclarationNode(identifier.value, std::stoi(literal.value));
            } else {
                throw std::runtime_error("Expected literal after '='");
            }
        } else {
            throw std::runtime_error("Expected '=' after identifier");
        }
    } else {
        throw std::runtime_error("Expected identifier in declaration");
    }
}

ASTNode* Parser::parseForLoop() {
    // Implement the parsing of for loop here.
    // For simplicity, let's just return a placeholder node.
    return new ForLoopNode();
}

