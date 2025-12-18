//
// Created by benja on 18.12.2025.
//

#ifndef PARSER_H
#define PARSER_H

#include "DynamicArray.h"
#include "Node.h"
#include "Lexer.h"
#include "ComputationalGraph.h"

class Parser {
private:
    DynamicArray<Token> tokens;
    int pos = 0;
    DynamicArray<Node*> parseTree;

    // HELPER FUNCTION MEMBERS:
    Token peek();
    Token consume(TokenClass expectedTokenClass);
    Node* registerNode(Node* node);

    // PARSE FUNCTION MEMBERS:
    Node* parseAssignment();
    Node* parseExpression();
    Node* parseTerm();
    Node* parseFactor();
    Node* parsePrimary();
    Node* parseParams();

public:
    Parser(DynamicArray<Token> tokens);

    ComputationalGraph* buildGraph();
};



#endif //PARSER_H
