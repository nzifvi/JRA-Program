#include "Headers/ComputationalGraph.h"
#include <iostream>

int main() {
    Graph graph;

    Vertex a("A", OpType::VARIABLE);
    Vertex b("B", OpType::VARIABLE);
    Vertex c("C", OpType::VARIABLE);
    Vertex d("D", OpType::VARIABLE);

    graph.addVertex(a);
    graph.addVertex(b);
    graph.addVertex(c);
    graph.addVertex(d);

    /*
     * A: A -> B, A -> C
     * B: B -> D
     * C: C -> D
     */
    graph.addEdge(a, b);
    graph.addEdge(a, c);
    graph.addEdge(b, d);
    graph.addEdge(c, d);

    std::cout << graph;
}