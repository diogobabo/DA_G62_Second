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

    vector<vector<int>> paths;
    Graph residual = rede.createResidual();
    int maxFlow = Graph::fordFulkerson(residual, s, t, &paths, dimension);

    if (maxFlow < dimension) cout << "Can only transport " << maxFlow << " persons;" << endl;

    for (auto path : paths) {
        cout << path[0];
        for (int i = 1; i < path.size(); i++) {
            cout << " -> "<< path[i];
        }
        cout << endl;
    }

    cout << "2.2) Add to the group x unities : x -> ";
    cin >> plus;

    int maxCap = rede.checkMaxCap(paths);
    paths.clear();
    if (maxCap < dimension + plus) {
        residual = rede.createResidual();
        Graph::fordFulkerson(residual, s, t, &paths, dimension + plus);
    }

    if(!paths.empty()) cout << "Correção de encaminhamento para maior dimensão do grupo: " << endl;
    else cout << "Não foi necessária correção de encaminhamento" << endl;
    for (auto path : paths) {
        cout << path[0];
        for (int i = 1; i < path.size(); i++) {
            cout << " -> "<< path[i];
        }
        cout << endl;
    }

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
    Graph residual = this->rede.createResidual();
    vector<vector<int>> paths;
    vector<pair<int,int>> waitTime;
    Graph::fordFulkerson(residual, s, t, &paths);

    for(int i = 0; i < paths.size(); i++) {
        for(int j = 1; j < paths[i].size(); j++) {
            int num = paths[i][j];
            for(int k = i + 1; k < paths.size(); k++){
                if(checkCommon(paths[k],num)) {
                    int temp = rede.getTime(paths[k],num);
                    int temp2 = rede.getTime(paths[i],num);
                    int res = abs(temp - temp2);
                    if(res != 0) {
                        bool flag = false;
                        for(auto x : waitTime)  {
                            if(x.first == num) {
                                x.second = max(res,x.second);
                                flag = true;
                            }
                        }
                        if(!flag){
                            waitTime.emplace_back(num,res);
                        }
                    }
                }
            }
        }
    }

}

bool Empresa::checkCommon(vector<int> path, int n) {
    for(auto x : path) {
        if(x == n) {
            return true;
        }
    }
    return false;
}