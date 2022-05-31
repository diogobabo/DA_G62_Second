#include "menu.h"
#include "cenarios.h"

int Menu::start() {
    int option = -1;

    Graph g = e.getGraph();

    g.printDirections();

    cout << "Bem vindo\n";
    cout << "1) Cenário 1\n";
    cout << "2) Cenário 2\n";

    while (option) {
        cout << "\nInsere opção (0 para sair)\n";
        cin >> option;

        switch (option) {
            case 1:
                Cenario1();
                break;
            case 2:
                Cenario2();
                break;
            default:
                break;
        }
    }
    return 0;
}

int Menu::Cenario1() {
    class Cenario1 c1(&e);

    int s, t;
    cout << "Starting point: ";
    cin >> s;
    cout << "Ending point: ";
    cin >> t;

    // Maior capacidade

    int groupD = c1.MaxCapWays(s, t);
    vector<int> path;
    c1.getPath(&path, t);

    cout << "Dimensão do grupo (sem se separar) máxima entre " << s << " para " << t << ": " << groupD << endl;
    cout << "Número de transbordos: " << path.size()-1 << endl;
    cout << path[0];
    for (int i = 1; i < path.size(); i++) {
        cout << " -> "<< path[i];
    }
    cout << endl;

    path.clear();
    // Menos transbordos
    int transbordos = c1.MinTransbordos(s, t);
    c1.getPath(&path, t);
    groupD = c1.pathCap(path);

    cout << "Mínimo de transbordos entre " << s << " para " << t << ": " << transbordos << endl;
    cout << "Dimensão máxima do grupo (sem se separar): " << groupD << endl;
    cout << path[0];
    for (int i = 1; i < path.size(); i++) {
        cout << " -> "<< path[i];
    }
    cout << endl;

    return 0;

}

int Menu::Cenario2() {
    class Cenario2 c2(&e);

    int s, t;
    cout << "Starting point: ";
    cin >> s;
    cout << "Ending point: ";
    cin >> t;

    Graph residual = this->e.getGraph().createResidual();
    vector<vector<int>> paths;

    int max_flow = c2.fordFulkerson(residual, s, t, &paths);
    cout << "Ford-Fulkerson max_flow : " << max_flow << endl;

    int max_time = 0;
    for (auto path : paths) {
        int time = this->e.getGraph().getTime(path);
        max_time = max(max_time, time);

        cout << path[0];
        for (int i = 1; i < path.size(); i++) {
            cout << " -> "<< path[i];

        }
        cout << endl;
    }



    cout << "The group will be reunited after : " << max_time << endl;
    return 0;

}
