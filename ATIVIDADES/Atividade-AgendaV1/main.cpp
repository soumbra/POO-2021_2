#include "fone.hpp"
#include "contact.hpp"
#include <sstream>

int main() 
{
    Contact boca{"boca"};

    while(true) {
        string line;
        getline(cin, line);
        stringstream ss(line);
        string cmd;
        ss >> cmd;
        if (cmd == "exit") {
            break;
        } else if (cmd == "show") {
            cout << boca << endl;
        } else if (cmd == "add") {
            string id {};
            string number {};
            ss >> id >> number;
            boca.addFone(Fone(id, number));
        } else if (cmd == "remove") {
            int index{};
            ss >> index;
            boca.rmFone(index);
        }
    }


}
