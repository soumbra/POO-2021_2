#pragma once
#include "fone.hpp"
#include <vector>

class Contact{
protected:
    string prefix = "-";
private:
    vector<Fone> fones;
    string name;

    bool validarIndice(int indice) {
        if (indice < 0 || indice >= (int) this->fones.size()) {
            cout << "Fone inexistente\n";
            return false;
        }
        return true;
    }

    bool foneDuplicado(Fone fone) {
        for (int i = 0; i < (int) this->fones.size(); i++) {
            if ((this->fones[i].getId() == fone.getId()) && ( this->fones[i].getNumber() == fone.getNumber())) {
                return true;
            }
        }
        return false;
    }

public:
    Contact(string name = "") : name{name} {};

    vector<Fone> getFones() {
        return this->fones;
    }

    string getName() {
        return this->name;
    }

    bool addFone(Fone fone) {
        if (!fone.validate(fone.getNumber())) {
            return false;
        }
        
        if (foneDuplicado(fone) == true) {
            cout << "Fone duplicado" << '\n';
            return false;
        }

        this->fones.push_back(fone);
        cout << "Fone adicionado" << '\n';
        return true;
    }

    bool rmFone(int index){
        if(!validarIndice(index)){
            return false;
        }
        this->fones.erase(fones.begin() + index);
        cout << "Fone apagado" << '\n';
        return true;
    }

    friend std::ostream& operator<<(std::ostream& os, const Contact& c) {
        os << c.prefix << " ";
        os << c.name << " ";
        for (int i = 0; i < (int) c.fones.size(); i++) {
            auto fone = c.fones[i];
            os << "[" << i << ":" ;
            os << fone << "] ";
        }
        return os;
    }
    
};