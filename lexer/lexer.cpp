// lexer.cpp
#include "lexer.h"
#include <cctype>

Lexer::Lexer(const std::string& code) : code_(code), currentPos_(0) {}

char Lexer::peekChar() const {
    return code_[currentPos_];
}

void Lexer::skipWhitespace() {
    while (currentPos_ < code_.size() && isspace(peekChar())) {
        currentPos_++;
    }
}

Token Lexer::scanIdentifier() {
    std::string identifier;
    while (currentPos_ < code_.size() && (isalnum(peekChar()) || peekChar() == '_')) {
        identifier += peekChar();
        currentPos_++;
    }
    return {TokenType::IDENTIFIER, identifier};
}

Token Lexer::scanLiteral() {
    std::string literal;
    while (currentPos_ < code_.size() && isdigit(peekChar())) {
        literal += peekChar();
        currentPos_++;
    }
    return {TokenType::LITERAL, literal};
}

Token Lexer::scanPunctuation() {
    std::string punctuation;
    punctuation += peekChar();
    currentPos_++;
    return {TokenType::PUNCTUATION, punctuation};
}

Token Lexer::getNextToken() {
    skipWhitespace();

    if (currentPos_ >= code_.size()) {
        return {TokenType::PUNCTUATION, "EOF"};
    }

    if (isalpha(peekChar())) {
        return scanIdentifier();
    } else if (isdigit(peekChar())) {
        return scanLiteral();
    } else {
        return scanPunctuation();
    }
}

