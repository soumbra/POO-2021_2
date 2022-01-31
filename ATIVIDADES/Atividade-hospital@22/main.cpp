#include "iMedico.hpp"
#include "iPaciente.hpp"
#include "medico.hpp"
#include "paciente.hpp"
#include "hospital.hpp"
#include "auxiliar.hpp"
#include <iostream>

vector<string> getcmd() {
    string line;
    getline(cin, line);
    cout << "$" << line << "\n";
    return aux::split(line, ' ');
}

int main()
{
    Hospital h;

    while(true) {
        auto param = getcmd();
        auto cmd = param[0];
        try {
            if (cmd == "exit") {
                break;
            } else if (cmd == "addMedico") {
                h.addMedico(make_shared<Medico>(param[1], param[2]));
            } else if (cmd == "addPaciente") {
                h.addPaciente(make_shared<Paciente>(param[1], param[2]));
            }  else if (cmd == "show") {
                cout << h << '\n';
            } else if (cmd == "rmMedico") {
                h.removerMedico(param[1]);
            } else if (cmd == "rmPaciente") {
                h.removerPaciente(param[1]);
            } else if (cmd == "vincular") {
                h.vincular(param[1], param[2]);
            } else {
                cout << "fail: comando invalido" << '\n';
            }
        } catch(const char* e) {
            cout << "fail: " << e << '\n';
        }
    }
}
