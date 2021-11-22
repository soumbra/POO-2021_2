#pragma once
#include "contact.hpp"
#include <algorithm>

class Agenda{
    vector<Contact> contacts;

    int findPos(string name) {
        for (int i = 0; i < (int) contacts.size(); i++) {
            if (contacts[i].getName() == name) {
                return i;
            }
        }
        return -1;
    }

    bool achouNome(string nome, string pattern) {
        if (nome.find(pattern) != string::npos) {
            return true;
        }
        return false;
    }

    bool achouFone(vector<Fone> fones, string pattern) {
        for(int i = 0; i < (int)fones.size(); i++){
            if (fones[i].getNumber().find(pattern) != string::npos) {
                return true;
            } 
        }
        return false;
    }

    bool achouId(vector<Fone> fones, string pattern) {
        for(int i = 0; i < (int)fones.size(); i++){
            if (fones[i].getId().find(pattern) != string::npos) {
                return true;
            } 
        }
        return false;
    }

    bool estaContido(string name, vector<Contact> contatos) {
        for(int i = 0; i < (int)contatos.size(); i++){
            if (name == contatos[i].getName()) {
                return true;
            }
        }
        return false;   
    }

public:
    Agenda(){};

    Contact getContact(string name) {
        return this->contacts[findPos(name)];
    } 

    void addContact(Contact contact) {
        if(findPos(contact.getName()) == -1){
            this->contacts.push_back(contact);
            return;
        }
        
        int pos = findPos(contact.getName());
        vector<Fone> fones = contact.getFones();
        for (int i = 0; i < (int) fones.size(); i++) {
            contacts[pos].addFone(fones[i]);
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
            contacts[pos].rmFone(index);
            return;
        }
        cout << "Contato nao existe" << '\n';
        return;
    }

    vector<Contact> search(string pattern){
        vector<Contact> contadosEncontrados;
        for (int i = 0; i < (int)contacts.size(); i++) {
            if (achouNome(contacts[i].getName(), pattern) == true) {
                contadosEncontrados.push_back(contacts[i]);
            }
        }

        for (int i = 0; i < (int)contacts.size(); i++) {
            if (achouId(contacts[i].getFones(), pattern) == true &&estaContido(contacts[i].getName(), contadosEncontrados) == false) {
                contadosEncontrados.push_back(contacts[i]);
            }
        }

        for (int i = 0; i < (int)contacts.size(); i++) {
            if (achouFone(contacts[i].getFones(), pattern) == true) {
                contadosEncontrados.push_back(contacts[i]);
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

    void ordenarContatos() {
        vector<string> nomes;
        for (int i = 0; i < (int) contacts.size(); i++) {
            string j = this->contacts[i].getName();
            nomes.push_back(j);
        }

        sort(nomes.begin(), nomes.end());

        vector<Contact> ordenados;

        for (int i = 0; i < (int) contacts.size(); i++) {
            int j = findPos(nomes[i]);
            ordenados.push_back(contacts[j]);
        }
        
        this->contacts = ordenados;
    }

    friend std::ostream& operator<<(std::ostream& os, const Agenda& a) {
        if((int) a.contacts.size() == 0){
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