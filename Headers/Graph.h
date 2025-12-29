//
// Created by benja on 18.12.2025.
//

#ifndef GRAPH_H
#define GRAPH_H

#include <string>
//#include "ChainingHashMap.h"
#include <map>
#include <list>
#include <iostream>
#include <vector>

enum class VisitState {
    UNVISITED,
    VISITING,
    VISITED
};

enum class OpType {
    VARIABLE,
    CONSTANT,
    ADD,
    MULT,
    SUB,
    DIV
};

struct Vertex {
    std::string vertexID;
    VisitState visitState;
    OpType opType;

    double primal = 0;
    double globalGradient;
    std::map<std::string, double> localGradients;

    std::list<std::string> incomingEdges;
    std::list<std::string> outgoingEdges;

    Vertex() = default;

    Vertex(const std::string& vertexID, OpType opType):
    vertexID(vertexID),
    visitState(VisitState::UNVISITED),
    opType(opType){}

    Vertex(const std::string& vertexID, OpType opType, double primalValue):
    vertexID(vertexID),
    visitState(VisitState::UNVISITED),
    opType(opType),
    primal(primalValue){}

    std::string convertOpTypeToString() const {
        switch (opType) {
            case OpType::VARIABLE:
                return "VARIABLE";
            case OpType::CONSTANT:
                return "CONSTANT";
            case OpType::ADD:
                return "ADD";
            case OpType::SUB:
                return "SUB";
            case OpType::MULT:
                return "MULT";
            case OpType::DIV:
                return "DIV";
        }
    }
};

class Graph {
private:
    void fullDFS(const std::string& u, std::vector<std::string>& stack);
    void resetStates();
protected:
    std::map<std::string, Vertex> adjList;


public:
    Graph() = default;
    virtual ~Graph() = default;

    std::vector<std::string> getTopologicalOrder();

    void addVertex(const Vertex& v);
    void removeVertex(const Vertex& v);

    void addEdge(const Vertex& source, const Vertex& target);
    void removeEdge(const Vertex& source, const Vertex& target);

    friend std::ostream& operator<<(std::ostream& os, const Graph& graph);
};


#endif
