#ifndef DA_T6_G62_EMPRESA_H
#define DA_T6_G62_EMPRESA_H

#include <string>

#include "graph/graph.h"


class Empresa {
private:
    Graph rede;
public:
    /**
     * Construtor
     * @param g Grafo com rede de transportes da empresa
     */
    explicit Empresa(Graph *g): rede(*g){};

    Graph getGraph() {return rede;};
};


#endif //DA_T6_G62_EMPRESA_H
