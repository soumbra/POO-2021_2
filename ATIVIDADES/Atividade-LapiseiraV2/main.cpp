#include "grafite.hpp"
#include "lapiseira.hpp"

int main()
{
    Lapiseira biMundial(0.5);
    while(true) {
        string cmd;
        cin >> cmd;
        if (cmd == "exit") {
            break;
        } else if (cmd == "show") {
            cout << biMundial << endl;
        } else if (cmd == "inserir") {
            float calibre{};
            string dureza{};
            int tamanho{};
            cin >> calibre >> dureza >> tamanho;
            biMundial.inserirGrafite(make_shared<Grafite>(calibre, dureza, tamanho));
        } else if (cmd == "puxar") {
            biMundial.pull();
        } else if (cmd == "remover") {
            biMundial.remover();
        } else if (cmd == "escrever") {
            biMundial.escreverFolha();
        }
    }

}
/*
    Grafite ui(0.5, "4B", 14);
    cout << ui << '\n';

    Lapiseira lata{0.5};
    cout << lata << '\n';

    lata.inserirGrafite(make_shared<Grafite>(ui));
    lata.inserirGrafite(make_shared<Grafite>(0.5, "6B", 17));
    cout << lata << '\n';
    lata.pull();
    lata.escreverFolha();
    lata.escreverFolha();
    cout << lata << '\n';
    lata.remover();
    lata.pull();
    lata.escreverFolha();
    lata.escreverFolha();
    cout << lata << '\n';
*/