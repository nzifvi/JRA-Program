//
// Created by benja on 29/12/2025.
//

#include "ComputationalGraph.h"

void ComputationalGraph::seedLocalGradients() {
    for (auto& [vertexID, v1] : adjList) {
        if (v1.opType == OpType::CONSTANT || v1.opType == OpType::VARIABLE) {
            for (const auto& [withRespectsTo, v2] : adjList) {
                if (withRespectsTo == vertexID) {
                    v1.localGradients.insert({withRespectsTo, 1.0});
                }else {
                    v1.localGradients.insert({withRespectsTo, 0.0});
                }
            }
        }
    }
}


void ComputationalGraph::executeForwardMode() {
    const std::vector<std::string> topologicalOrdering = getTopologicalOrder();
    seedLocalGradients();

    for (const std::string& vertexID : topologicalOrdering) {
        Vertex& v = adjList[vertexID];

        if (v.opType == OpType::CONSTANT || v.opType == OpType::VARIABLE) {
            continue;
        }

        if (v.opType == OpType::ADD) {

        }else if (v.opType == OpType::SUB) {

        }else if (v.opType == OpType::MULT) {

        }else if (v.opType == OpType::DIV) {

        }
    }
}
