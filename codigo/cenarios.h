#ifndef DA_T6_G62_CENARIOS_H
#define DA_T6_G62_CENARIOS_H

#include "graph/graph.h"
#include "empresa.h"

class Cenario1 {
private:
    Graph g;
public:
    explicit Cenario1(Empresa *e): g(e->getGraph()){}
};

class Cenario2 {
private:
    Graph g;
public:
    explicit Cenario2(Empresa *e): g(e->getGraph()){}
};

#endif //DA_T6_G62_CENARIOS_H
