#include "client.hpp"
#include "sala.hpp"

int main()
{
    Sala cineminha(10);
    while(true) {
        string cmd;
        cin >> cmd;
        if (cmd == "exit") {
            break;
        } else if (cmd == "show") {
            cout << cineminha << endl;
        } else if (cmd == "reservar") {
            string fone{};
            string id{};
            int indice{};
            cin >> fone >> id >> indice;
            cineminha.reservar(make_shared<Client>(fone, id), indice);
        } else if (cmd == "cancelar") {
            string id{};
            cin >> id;
            cineminha.cancelar(id);
        }
    }
}