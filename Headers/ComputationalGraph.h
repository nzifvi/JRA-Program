//
// Created by benja on 29/12/2025.
//

#ifndef COMPUTATIONALGRAPH_H
#define COMPUTATIONALGRAPH_H

#include "Graph.h"
#include <vector>

class ComputationalGraph final : public Graph {
private:
    void seedLocalGradients();

public:
    void executeForwardMode();

};



#endif //COMPUTATIONALGRAPH_H
