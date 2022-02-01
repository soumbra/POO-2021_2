#include "client.hpp"
#include "sala.hpp"
#include <sstream>

int main()
{
    Sala cineminha;
    while(true) {
        string line;
        getline(cin, line);
        stringstream ss(line);
        string cmd;
        ss >> cmd;
        if (cmd == "exit") {
            break;
        } else if (cmd == "show") {
            cout << cineminha << endl;
        } else if (cmd == "reservar") {
            string fone{};
            string id{};
            int indice{};
            ss >> fone >> id >> indice;
            cineminha.reservar(make_shared<Client>(fone, id), indice);
        } else if (cmd == "cancelar") {
            string id{};
            ss >> id;
            cineminha.cancelar(id);
        }
    }
}