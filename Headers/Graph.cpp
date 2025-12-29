//
// Created by benja on 18.12.2025.
//

#include "Graph.h"

#include <algorithm>

void Graph::fullDFS(const std::string &u, std::vector<std::string> &stack) {
    adjList[u].visitState = VisitState::VISITING;

    for (const std::string& v : adjList[u].outgoingEdges) {
        if (adjList[v].visitState == VisitState::VISITING) {
            // throw exception, loop detected.
        }
        if (adjList[v].visitState == VisitState::UNVISITED) {
            fullDFS(v, stack);
        }
    }

    adjList[u].visitState = VisitState::VISITED;
    stack.push_back(u);
}

std::vector<std::string> Graph::getTopologicalOrder() {
    std::vector<std::string> topologicalOrdering;

    resetStates();

    for (auto const& [id, vertex] : adjList) {
        if (vertex.visitState == VisitState::UNVISITED) {
            fullDFS(id, topologicalOrdering);
        }
    }

    std::reverse(topologicalOrdering.begin(), topologicalOrdering.end());
    return topologicalOrdering;
}

void Graph::resetStates() {
    for (auto& [id, vertex]: adjList) {
        vertex.visitState = VisitState::UNVISITED;
    }
}


void Graph::addVertex(const Vertex& v) {
    if (!adjList.contains(v.vertexID)) {
        adjList.insert({v.vertexID, v});
    }else {
        // program to throw exception due to attempting to insert an already existing vertex.
        // - should use updateVertex instead.
    }
}

void Graph::removeVertex(const Vertex& v) {
    auto vIterator = adjList.find(v.vertexID);
    if (vIterator == adjList.end()) {
        // throw exception, vertex does not exist.
        // - or just do nothing and return.
    }else {
        for (const std::string& parentVertexID : vIterator->second.incomingEdges) {
            auto parentVertexIterator = adjList.find(parentVertexID);
            if (parentVertexIterator != adjList.end()) {
                parentVertexIterator->second.outgoingEdges.remove(v.vertexID);
            }
        }

        for (const std::string& childID : vIterator->second.outgoingEdges) {
            auto childIt = adjList.find(childID);
            if (childIt != adjList.end()) {
                childIt->second.incomingEdges.remove(v.vertexID);
            }
        }

        adjList.erase(vIterator);
    }
}

void Graph::addEdge(const Vertex& source, const Vertex& sink) {
    const auto sourceVertexIterator = adjList.find(source.vertexID);
    const auto sinkVertexIterator = adjList.find(sink.vertexID);

    if (sourceVertexIterator != adjList.end() && sinkVertexIterator != adjList.end()) {
        sourceVertexIterator->second.outgoingEdges.push_back(sink.vertexID);
        sinkVertexIterator->second.incomingEdges.push_back(source.vertexID);
    }else {
        // throw exception, one of the vertices do not exist in the graph.
    }
}

void Graph::removeEdge(const Vertex& source, const Vertex& sink) {
    const auto sourceVertexIterator = adjList.find(source.vertexID);
    const auto sinkVertexIterator = adjList.find(sink.vertexID);

    if (sourceVertexIterator != adjList.end() && sinkVertexIterator != adjList.end()) {
        sourceVertexIterator->second.outgoingEdges.remove(sink.vertexID);
        sinkVertexIterator->second.incomingEdges.remove(source.vertexID);
    }else {
        // throw exception, one of the vertices do not exist in the graph.
    }
}

std::ostream& operator<<(std::ostream& os, const Graph& graph) {
    for (const auto& [id, vertex] : graph.adjList) {
        os << "Vertex: " << vertex.vertexID  << "\n"  << "  OpType: " + vertex.convertOpTypeToString() << "\n" << "  Outgoing Edges:\n";
        for (const auto& sinkVertex : vertex.outgoingEdges) {
            os << "    " + id + " -> " + sinkVertex + "\n";
        }
        std::cout << "\n";
    }
    return os;
}

