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
    groupD = c1.MinTransbordos(s, t);
    c1.getPath(&path, t);

    cout << "Mínimo de transbordos entre " << s << " para " << t << ": " << path.size()-1 << endl;
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
    return 0;

}
