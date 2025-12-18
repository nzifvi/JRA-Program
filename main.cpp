#include "Headers/DynamicArray.h"
#include <iostream>
#include "Headers/Lexer.h"

int main() {
    const std::string func = "f(x,y) = x + y";

    Lexer lexer(func);
    DynamicArray<Token> tokenStream = lexer.tokenise();
    std::cout << tokenStream << std::endl;

}