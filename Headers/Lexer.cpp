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
            tokens.insert(tokens.getSize(), lexNumber());
        }else if (isalpha(input[pos])) {
            tokens.insert(tokens.getSize(), lexIdentifier());
        }else {
            tokens.insert(tokens.getSize(), lexOperator(pos));
            pos++;
        }
    }
    tokens.insert(
        tokens.getSize(),
        Token(TokenClass::eof, "")
        );
    return tokens;
}

Token Lexer::lexIdentifier() {
    const size_t startingPos = pos;

    while (pos < input.length() && isalpha(input[pos])) {
        pos++;
    }

    const std::string lexeme = input.substr(startingPos, pos - startingPos);
    return Token(TokenClass::identifier, lexeme);
}

Token Lexer::lexNumber() {
    const size_t startingPos = pos;
    bool hasRadix = false;

    while (pos < input.length() && (isdigit(input[pos]) || input[pos] == '.')) {
        if (input[pos] == '.') {
            if (hasRadix) {break;}
            hasRadix = true;
        }
        pos++;
    }

    const std::string lexeme = input.substr(startingPos, pos - startingPos);
    TokenClass type;
    if (hasRadix) {
        type = TokenClass::floatLit;
    }else {
        type = TokenClass::intLit;
    }
    return Token(type, lexeme);
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


