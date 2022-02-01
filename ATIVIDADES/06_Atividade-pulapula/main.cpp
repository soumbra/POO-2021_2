#include "kid.hpp"
#include "trampoline.hpp"

int main()
{
    Trampoline biri;
    while(true) {
        string cmd;
        cin >> cmd;
        if (cmd == "exit") {
            break;
        } else if (cmd == "show") {
            cout << biri << endl;
        } else if (cmd == "chegar") {
            int age{};
            string name{};
            cin >> age >> name;
            biri.arrive(make_shared<Kid>(age, name));
        } else if (cmd == "entrar") {
            biri.in();
        } else if(cmd == "sair") {
            biri.out();
        } else if(cmd == "papai") {
            string name{};
            cin >> name;
            biri.papaiChegou(name);
        }
    }
}