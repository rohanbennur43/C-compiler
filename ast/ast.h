// ast.h
#pragma once
#include <string>
#include <iostream>

class ASTNode {
public:
    virtual ~ASTNode() = default;
    virtual void execute() const = 0;
};

class DeclarationNode : public ASTNode {
public:
    DeclarationNode(const std::string& identifier, int value)
        : identifier_(identifier), value_(value) {}

    void execute() const override {
        // For simplicity, just print the declaration.
        std::cout << "Declaration: int " << identifier_ << " = " << value_ << std::endl;
    }

private:
    std::string identifier_;
    int value_;
};

class ForLoopNode : public ASTNode {
public:
    void execute() const override {
        // For simplicity, just print the for loop.
        std::cout << "For Loop: for (...) { ... }" << std::endl;
    }
};

