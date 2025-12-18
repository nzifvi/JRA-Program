//
// Created by benja on 18.12.2025.
//

#ifndef LEXER_H
#define LEXER_H

#include <string>
#include "DynamicArray.h"

enum class TokenClass {
    identifier,
    floatLit,
    intLit,
    add,
    subtract,
    multiply,
    divide,
    exponent,
    whitespace,
    lParen,
    rParen,
    comma,
    assign,
    eof
};

struct Token {
    TokenClass tokenClass;
    std::string lexeme;
};

class Lexer {
private:
    std::string input;
    int pos = 0;

    Token lexIdentifier();
    Token lexNumber();
    Token lexOperator(const int initialPos);
public:
    Lexer(const std::string& input);

    DynamicArray<Token> tokenise();
};

inline std::ostream& operator<<(std::ostream& os, const TokenClass& type) {
    switch (type) {
        case TokenClass::identifier:
            os << "identifier";
            break;
        case TokenClass::floatLit:
            os << "floatlit";
            break;
        case TokenClass::intLit:
            os << "intlit";
            break;
        case TokenClass::add:
            os << "add";
            break;
        case TokenClass::subtract:
            os << "subtract";
            break;
        case TokenClass::multiply:
            os << "multiply";
            break;
        case TokenClass::divide:
            os << "divide";
            break;
        case TokenClass::exponent:
            os << "exponent";
            break;
        case TokenClass::whitespace:
            os << "whitespace";
        case TokenClass::lParen:
            os << "lParen";
            break;
        case TokenClass::rParen:
            os << "rParen";
            break;
        case TokenClass::comma:
            os << "comma";
            break;
        case TokenClass::assign:
            os << "assign";
            break;
        case TokenClass::eof:
            os << "eof";
            break;
    }
    return os;
}

inline std::ostream& operator<<(std::ostream& os, const Token& token) {
    os << "(" << token.tokenClass << ", " << token.lexeme << ")";
    return os;
}


#endif //LEXER_H
