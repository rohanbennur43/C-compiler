// lexer.h
#pragma once
#include <string>
#include <vector>

enum TokenType {
    KEYWORD,
    IDENTIFIER,
    OPERATOR,
    LITERAL,
    PUNCTUATION,
    COMMENT
};

struct Token {
    TokenType type;
    std::string value;
};

class Lexer {
public:
    Lexer(const std::string& code);
    Token getNextToken();

private:
    std::string code_;
    size_t currentPos_;

    char peekChar() const;
    void skipWhitespace();
    Token scanIdentifier();
    Token scanLiteral();
    Token scanPunctuation();
};

