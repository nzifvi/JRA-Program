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

inline std::ostream& operator<<(std::ostream& os, const Token& token) {
    os << "(" << token.lexeme << ", " << token.lexeme << ")";
    return os;
}


#endif //LEXER_H
