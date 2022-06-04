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

    vector<pair<vector<int>,int>> solutions;
    vector<int> pathAux;
    vector<int> capsAux;

    int transbordos = d[t];

    int maxCap;

    rede.getPath(&path, t);
    int pathCap = rede.pathCapacity(path);

    rede.setPath(path);
    solutions.push_back(pair<vector<int>,int>(path,pathCap));
    while(rede.unusedNodes()>1){
        rede.MaxCapWaysWithUse(s);
        pathAux.clear();
        rede.getPath(&pathAux, t);
        if(solutions.back().first != pathAux){
            vector<int> d1 = rede.getDistances();
            solutions.push_back(pair<vector<int>,int>(pathAux,d1[t]));
        }
        rede.setUseNode();
    }

    sort(solutions.begin(), solutions.end(), sortPair);

    solutions.pop_back();
    reverse(solutions.begin(), solutions.end());

    pair<vector<int>,int> top1,top2,top3;

    for(auto &sol: solutions){
        if(sol.second != 0 && top1.first.empty()){
            top1 = sol;
        }else if(!top1.first.empty() && sol.second != top1.second && top2.first.empty()){
            top2 = sol;
        } else if(!top1.first.empty() && !top2.first.empty() && sol.second != top2.second ){
            top3 = sol;
            break;
        }
    }

    solutions.clear();

    solutions.push_back(top1);
    if(top2.second>top1.second){
        solutions.push_back(top2);
    }
    if(solutions.back().second<top3.second){
        solutions.push_back(top3);
    }

    cout << "1.2) Mínimo de transbordos entre " << s << " para " << t << ": " << transbordos << endl;
    cout << "Dimensão máxima do grupo (sem se separar): " << pathCap << endl;
    cout << path[0];
    for (int i = 1; i < path.size(); i++) {
        cout << " -> "<< path[i];
    }
    cout << endl;
    for(int z = 1; z <solutions.size();z++){
        cout << "Outra parento-solução: "<< endl;
        cout << "Numero de trasnbordos : "<<solutions[z].first.size() << endl;
        cout << "Capacidade do grupo :"<< solutions[z].second << endl;
        cout << solutions[z].first[0];
        for (int i = 1; i < solutions[z].first.size(); i++) {
            cout << " -> "<< solutions[z].first[i];
        }
        cout << endl;
    }

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
}

void Empresa::two4(int s, int t) {
    cout << "Time after which the groups reunites: " << this->rede.minDuration(s,t) << endl;

}

void Empresa::two5(int s, int t) {
    this->rede.latestFinish(s,t);
}

void Empresa::two4All(int s, int t) {
    cout << "Time after which the groups reunites: " << this->rede.minDurationAll(s,t) << endl;
}

void Empresa::two5All(int s, int t) {
    this->rede.latestFinishAll(s,t);
}

bool Empresa::checkCommon(vector<int> path, int n) {
    for(auto x : path) {
        if(x == n) {
            return true;
        }
    }
    return false;
}

bool Empresa::sortPair(pair<vector<int>, int> &p1, pair<vector<int>, int> &p2) {
    if(p1.first.size() == p2.first.size()){
        return p1.second>p2.second;
    }
    return p1.first.size()>p2.first.size();
}
