//
// Created by benja on 18.12.2025.
//

#ifndef NODE_H
#define NODE_H

class Node {
public:
    virtual ~Node() = default;
    virtual double evaluate() = 0;
};

class BinaryOpNode : public Node {
protected:
    Node* rhs;
    Node* lhs;
public:
    BinaryOpNode(Node* lhs, Node* rhs): lhs(lhs), rhs(rhs) {};
};

class AddNode final: public BinaryOpNode {
public:
    using BinaryOpNode::BinaryOpNode;
    double evaluate() override;
};

class SubtractNode final: public BinaryOpNode {
public:
    using BinaryOpNode::BinaryOpNode;
    double evaluate() override;
};

class MultiplyNode final: public BinaryOpNode {
public:
    using BinaryOpNode::BinaryOpNode;
    double evaluate() override;
};

class DivideNode final: public BinaryOpNode {
public:
    using BinaryOpNode::BinaryOpNode;
    double evaluate() override;
};

class ExponentNode final: public BinaryOpNode {
public:
    using BinaryOpNode::BinaryOpNode;
    double evaluate() override;
};




#endif //NODE_H
