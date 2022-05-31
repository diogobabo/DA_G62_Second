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
                if (!Cenario1()) {
                    cout << endl;
                    cout << "1) Cenário 1\n";
                    cout << "2) Cenário 2\n";
                }
                break;
            case 2:
                if (!Cenario2()) {
                    cout << endl;
                    cout << "1) Cenário 1\n";
                    cout << "2) Cenário 2\n";
                }
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

    int option = -1;

    int groupD;
    vector<int> path;

    cout << "1) 1.1\n2) 1.2\n";
    while (option) {
        cout << "Insere opção (0 para sair)\n";
        cin >> option;

        switch (option) {
            case 1:
                // Maior capacidade
                groupD = c1.MaxCapWays(s, t);
                c1.getPath(&path, t);

                cout << "1.1) Dimensão do grupo (sem se separar) máxima entre " << s << " para " << t << ": " << groupD << endl;
                cout << "Número de transbordos: " << path.size()-1 << endl;
                cout << path[0];
                for (int i = 1; i < path.size(); i++) {
                    cout << " -> "<< path[i];
                }
                cout << endl;

                path.clear();
                break;
            case 2:
                cout << "1.2) " << endl;

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
                break;
            default:
                break;
        }
    }

    return 0;
}

int Menu::Cenario2() {
    class Cenario2 c2(&e);

    int s, t, option = -1;
    cout << "Starting point: ";
    cin >> s;
    cout << "Ending point: ";
    cin >> t;

    Graph residual = this->e.getGraph().createResidual();
    vector<vector<int>> paths;

    int max_flow;
    int max_time;
    int dimension, plus;
    cout << "1) 2.1-2.2\n2) 2.3\n3) 2.4-2.5\n";
    while (option) {
        cout << "Insere opção (0 para sair)\n";
        cin >> option;

        switch (option) {
            case 1:
                cout << "2.1) Size of the group : \n";
                cin >> dimension;

                // after algorithm

                cout << "2.2) Resize the group in x unities : x -> ";
                cin >> plus;

                // algorithm
                break;
            case 2:
                max_flow = c2.fordFulkerson(residual, s, t, &paths);
                cout << "2.3) Ford-Fulkerson max_flow : " << max_flow << endl;

                max_time = 0;
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

                break;
            case 3:
                cout << "2.4) The group will be reunited after : " << max_time << endl;

                cout << "2.5) \n";
                break;
            default:
                break;
        }
    }

    return 0;

}
