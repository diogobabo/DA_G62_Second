#include "cenarios.h"

int Cenario1::MaxCapWays(int s, int t) {
    g.MaxCapWays(s);
    vector<int> d = g.getDistances();
    return d[t];
}

int Cenario1::getPath(vector<int> *path, int t) {
    g.getPath(path, t);
    return 0;
}

int Cenario1::MinTransbordos(int s, int t) {
    g.minTransbordos(s, t);
    vector<int> d = g.getDistances();
    return d[t];
}
