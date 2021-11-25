#pragma once
#include "contact.hpp"
#include <algorithm>
#include <sstream>

template <typename T>
std::string to_string(T t) {
    std::stringstream ss;
    ss << t;
    return ss.str();
}

class Agenda{
    vector<Contact> contacts;

    int findPos(string name) {
        for (int i = 0; i < (int) contacts.size(); i++) {
            if (this->contacts[i].getName() == name) {
                return i;
            }
        }
        return -1;
    }

public:
    Agenda(){};

    Contact* getContact(string name) {
        if (!findPos(name)) {
            return nullptr;
        }
        return &contacts[findPos(name)];
    } 

    void addContact(Contact contact) {
        if (findPos(contact.getName()) == -1) {
            this->contacts.push_back(contact);
            sort(contacts.begin(), contacts.end(), [] (auto a, auto b){ 
                return a.getName() < b.getName();
            }); 
            return;
        }
        
        int pos = findPos(contact.getName());
        vector<Fone> fones = contact.getFones();
        for (int i = 0; i < (int) fones.size(); i++) {
            this->contacts[pos].addFone(fones[i]);
        }

    }

    void rmContact(string name) {
        int pos = findPos(name);
        if (pos != -1) {
            this->contacts.erase(contacts.begin() + pos);
            cout << "Contato apagado" << '\n';
            return;
        }
        cout << "Contato nao existe" << '\n';
        return;
    }

    void rmContact(string name, int index) {
        int pos = findPos(name);
        if (pos != -1) {
            this->contacts[pos].rmFone(index);
            return;
        }
        cout << "Contato nao existe" << '\n';
        return;
    }

    vector<Contact> search(string pattern){
        vector<Contact> contadosEncontrados;
        for (auto contato : this->contacts) {
            auto texto = to_string(contato);
            if (texto.find(pattern) != std::string::npos) {
                contadosEncontrados.push_back(contato);
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
            for (int i = 0; i < (int) a.contacts.size(); i++) {
                auto contacts = a.contacts[i];
                os << i << ":" ;
                os << contacts << '\n';
            }
        }
        
        return os;
    }

};