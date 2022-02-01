#pragma once
#include "contact.hpp"
#include <algorithm>
#include <sstream>
#include <map>

template <typename T>
std::string to_string(T t) {
    std::stringstream ss;
    ss << t;
    return ss.str();
}

class Agenda{
    map<string, Contact> contacts;

public:
    Agenda(){};

    Contact* getContact(string name) {
        auto it = contacts.find(name);
        if (it != contacts.end()) {
            return nullptr;
        }
        return &it->second;
    } 

    void addContact(Contact contact) {
        auto it = contacts.find(contact.getName());
        if (it == contacts.end()) {
            contacts[contact.getName()] = contact;
            return;
        } else {
            vector<Fone> novos = contact.getFones();
            for (int i = 0; i < (int) novos.size(); i++) {
                it->second.addFone(novos[i]);
            }
        }
        return;
    }

    void rmContact(string name) {
        auto it = contacts.find(name);
        if (it == contacts.end()) {
            cout << "Contato nao encontrado" << '\n';
        } else {
            contacts.erase(it);
            cout << "Contato Apagado" << '\n';
        }
    }

    void rmFone(string name, int index) {
        auto it = contacts.find(name);
        if (it == contacts.end()) {
            cout << "Contato nao encontrado" << '\n';
        } else {
            it->second.rmFone(index);
        }
    }

    vector<Contact> search(string pattern){
        vector<Contact> contadosEncontrados;
        for (auto contato : this->contacts) {
            auto texto = to_string(contato.second);
            if (texto.find(pattern) != string::npos) {
                contadosEncontrados.push_back(contato.second);
            }
        }
        
        if ((int)contadosEncontrados.size() == 0) {
            cout << "Nada encontrado" << '\n';
        } else {
            for (int i = 0; i < (int) contadosEncontrados.size(); i++) {
                cout << contadosEncontrados[i] << '\n';
            }
        }

        return contadosEncontrados;        
    }

    friend std::ostream& operator<<(std::ostream& os, const Agenda& a) {
        if ((int) a.contacts.size() == 0) {
            os << "Agenda vazia ";
        } else {
            for (auto it = a.contacts.begin(); it != a.contacts.end(); ++it) {
                os << it->second << endl;
            }
        }
        
        return os;
    }

};