#include "empresa.h"

void Empresa::one1(int s, int t) {
    // Maior capacidade
    rede.MaxCapWays(s);

    vector<int> path;
    vector<int> d = rede.getDistances();
    int groupD = d[t];

    rede.getPath(&path, t);

    cout << "1.1) Dimensão do grupo (sem se separar) máxima entre " << s << " para " << t << ": " << groupD << endl;
    cout << "Número de transbordos: " << path.size()-1 << endl;
    cout << path[0];
    for (int i = 1; i < path.size(); i++) {
        cout << " -> "<< path[i];
    }
    cout << endl;
}

void Empresa::one2(int s, int t) {
    // Menos transbordos
    rede.distance(s, t);

    vector<int> path;
    vector<int> d = rede.getDistances();
    int transbordos = d[t];

    rede.getPath(&path, t);
    int groupD = rede.pathCapacity(path);

    cout << "1.2) Mínimo de transbordos entre " << s << " para " << t << ": " << transbordos << endl;
    cout << "Dimensão máxima do grupo (sem se separar): " << groupD << endl;
    cout << path[0];
    for (int i = 1; i < path.size(); i++) {
        cout << " -> "<< path[i];
    }
    cout << endl;
}

void Empresa::two1(int s, int t) {
    int dimension, plus;
    cout << "2.1) Size of the group : \n";
    cin >> dimension;

    // after algorithm

    cout << "2.2) Resize the group in x unities : x -> ";
    cin >> plus;

    // algorithm
}

void Empresa::two3(int s, int t) {
    Graph residual = this->rede.createResidual();
    vector<vector<int>> paths;

    int max_flow = Graph::fordFulkerson(residual, s, t, &paths);
    cout << "2.3) Ford-Fulkerson max_flow : " << max_flow << endl;

    int max_time = 0;
    for (auto path : paths) {
        int time = this->rede.getTime(path);
        max_time = max(max_time, time);

        cout << path[0];
        for (int i = 1; i < path.size(); i++) {
            cout << " -> "<< path[i];

        }
        cout << endl;
    }
    cout << "The group will be reunited after : " << max_time << endl;
}

void Empresa::two4(int s, int t) {
    int max_time = -1;

    // algorithm

    cout << "2.4) The group will be reunited after : " << max_time << endl;

    // algorithm

    cout << "2.5) \n";

}
