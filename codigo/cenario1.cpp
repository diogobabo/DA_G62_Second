#include "cenarios.h"

int Cenario1::MaxCapWays(int s, int t) {
    g.MaxCapWays(s);
    vector<int> d = g.getDistances();
    return d[t];
}