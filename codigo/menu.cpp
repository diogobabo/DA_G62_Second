#include "menu.h"
#include "cenarios.h"

int Menu::start() {
    int option = -1;

    cout << "Bem vindo\n";
    cout << "1) Cenário 1\n";
    cout << "2) Cenário 2\n";

    Graph g = e.getGraph();

    g.printDirections();

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
    return 0;

}

int Menu::Cenario2() {
    class Cenario2 c2(&e);
    return 0;

}
