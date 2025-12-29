//
// Created by benja on 18.12.2025.
//

#include "Parser.h"
/*
Parser::Parser(const DynamicArray<Token> &tokens): tokens(tokens) {}

Token Parser::peek() {return tokens.get(pos);}

Token Parser::consume(TokenClass expectedTokenClass) {
    if (expectedTokenClass != peek().tokenClass) {

    }else {
        return tokens.get(pos++);
    }
}

Node *Parser::registerNode(Node *node) {
    parseTree.insert(parseTree.getSize(), node);
    return node;
}

Node *Parser::parseProgram() {
    return parseFunction();
}

Node* Parser::parseFunction() {
    consume(TokenClass::identifier);
    consume(TokenClass::lParen);
    parseParams();
    consume(TokenClass::rParen);
    consume(TokenClass::assign);

    return parseExpr();
}

Node* Parser::parseParams() {

}

Node* Parser::parseExpr() {
    Node* newNode = parseTerm();

    while (peek().tokenClass == TokenClass::add || peek().tokenClass == TokenClass::subtract) {
        Token op = consume(peek().tokenClass);
        Node* rightNode = parseTerm();

        if (op.tokenClass == TokenClass::add) {
            newNode = registerNode(new AddNode(newNode, rightNode));
        }else {
            newNode = registerNode(new SubtractNode(newNode, rightNode));
        }
    }

    return newNode;
}

Node* Parser::parseTerm() {
    Node* newNode = parseFactor();

    while (peek().tokenClass == TokenClass::multiply || peek().tokenClass == TokenClass::divide) {
        Token op = consume(peek().tokenClass);
        Node* rightNode = parseFactor();

        if (op.tokenClass == TokenClass::multiply) {
            newNode = registerNode(new MultiplyNode(newNode, rightNode));
        }else {
            newNode = registerNode(new DivideNode(newNode, rightNode));
        }
    }

    return newNode;
}

Node* Parser::parseFactor() {
    Node* newNode = parsePrimary();

    if (peek().tokenClass == TokenClass::exponent) {
        consume(TokenClass::exponent);
        Node* rightNode = parseFactor();
        newNode = registerNode(new ExponentNode(newNode, rightNode));
    }

    return newNode;
}

Node* Parser::parsePrimary() {
    Token currentToken = peek();
    if (currentToken.tokenClass == TokenClass::lParen) {
        consume(TokenClass::lParen);
        Node* newNode = parseExpr();
        consume(TokenClass::rParen);
        return newNode;
    }else if (currentToken.tokenClass == TokenClass::identifier) {
        consume(TokenClass::identifier);

    }
}
*/