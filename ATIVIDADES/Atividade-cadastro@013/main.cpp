#include "account.hpp"
#include "savingsAccount.hpp"
#include "checkingAccount.hpp"
#include "client.hpp"
#include "bank.hpp"
#include <sstream>

int main()
{
    BankAgency agency;

    while(true) {
        try{
            string line;
            getline(cin, line);
            stringstream ss(line);
            string cmd;
            ss >> cmd;
            if (cmd == "exit") {
                break;
            } else if (cmd == "show") {
                cout << agency << endl;
            } else if (cmd == "addCli") {
                string clientId {};
                ss >> clientId;
                agency.addAccount(clientId);
            } else if (cmd == "saque") {
                int id{};
                float value{};
                ss >> id >> value;
                agency.withdraw(id, value);
            } else if (cmd == "deposito") {
                int id{};
                float value{};
                ss >> id >> value;
                agency.deposit(id, value);
            } else if (cmd == "transferencia") {
                int contaDe{};
                int contaPara{};
                float value{};
                ss >> contaDe >> contaPara >> value;
                agency.transfer(contaDe, contaPara, value);    
            } else if (cmd == "update") {
                agency.monthlyUpdate();
            } else {
                cout << "fail: comando invalido" << '\n';
            }
        } catch(const char* e) {
            cout << "fail: " << e << '\n';
        }
    }

}