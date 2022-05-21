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

    cout << "Caminhos de capacidade máxima entre s para t: " << c1.MaxCapWays(s, t);

    return 0;

}

int Menu::Cenario2() {
    class Cenario2 c2(&e);
    return 0;

}
