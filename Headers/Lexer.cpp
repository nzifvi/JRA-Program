//
// Created by benja on 18.12.2025.
//

#include "Lexer.h"

Lexer::Lexer(const std::string &input): input(input) {

}

DynamicArray<Token> Lexer::tokenise() {
    DynamicArray<Token> tokens;
    pos = 0;

    while (pos < input.length()) {
        if (isspace(input[pos])) {
            pos++;
            continue;
        }

        if (isdigit(input[pos]) || input[pos] == '.') {
            //tokens.insert(tokens.getSize() - 1, " ");
        }else if (isalpha(input[pos])) {
            //tokens.insert(tokens.getSize() - 1, " ");
        }else {
            tokens.insert(tokens.getSize() - 1, lexOperator(pos));
            pos++;
        }
    }
    tokens.insert(
        tokens.getSize() - 1,
        Token(TokenClass::eof, "")
        );
    return tokens;
}

Token Lexer::lexIdentifier(const int initialPos) {

}

Token Lexer::lexNumber(const int initialPos) {

}

Token Lexer::lexOperator(const int initialPos) {
    switch (input[initialPos]) {
        case '+':
            return Token(TokenClass::add, "+");
        case '-':
            return Token(TokenClass::subtract, "-");
        case '*':
            return Token(TokenClass::multiply, "*");
        case '/':
            return Token(TokenClass::divide, "/");
        case '^':
            return Token(TokenClass::exponent, "^");
        case '(':
            return Token(TokenClass::lParen, "(");
        case ')':
            return Token(TokenClass::rParen, ")");
        case '=':
            return Token(TokenClass::assign, "=");
        case ',':
            return Token(TokenClass::comma, ",");
        default:
            exit(1);
    }
}


