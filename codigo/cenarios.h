#ifndef DA_T6_G62_CENARIOS_H
#define DA_T6_G62_CENARIOS_H

#include "graph/graph.h"
#include "empresa.h"

class Cenario1 {
private:
    Graph g;
public:
    explicit Cenario1(Empresa *e): g(e->getGraph()){}
    int MaxCapWays(int s, int t);
    int getPath(vector<int> *path, int t);

    int MinTransbordos(int s, int t);

    int pathCap(vector<int> vector1);
};

class Cenario2 {
private:
    Graph g;
public:
    explicit Cenario2(Empresa *e): g(e->getGraph()){}

    int maxFlow(int s, int t);
};

#endif //DA_T6_G62_CENARIOS_H
