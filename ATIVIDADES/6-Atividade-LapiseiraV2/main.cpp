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