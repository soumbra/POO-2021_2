#pragma once
#include "client.hpp"
#include <vector>
#include <memory>
#include <map>

class Sala{
    map<int, shared_ptr<Client>> cadeiras;

    bool clientExist(string id) {
        for (auto it = this->cadeiras.begin(); it != this->cadeiras.end(); ++it) {
            if (it->second->getId() == id){
                return true;
            }
        }
        return false;
    }

public:
    Sala(){};

    bool reservar(const shared_ptr<Client>& client, int indice) {
        auto it = cadeiras.find(indice);

        if (it != cadeiras.end()) {
            cout << "Cadeira ocupada" << '\n';
            return false;
        }

        if (clientExist(client->getId())) {
            cout << "Voce ja reservou uma cadeira, deixe de xafurdo!" << '\n';
            return false;
        }

        cadeiras[indice] = client;
        cout << "cadeira reservada" << '\n';
        return true;
    } 

    bool cancelar(string id) {

       for (auto it = this->cadeiras.begin(); it != this->cadeiras.end(); ++it) {
            if (it->second->getId() == id){
                cadeiras.erase(it);
                cout << "Contato removido" << '\n';
                return true;
            }
        }

        return false;
    }

    friend std::ostream& operator<<(std::ostream& os, const Sala& s) {
        os << '[' ;
        for (auto it = s.cadeiras.begin(); it != s.cadeiras.end(); ++it) {         
            os << it->first << ":" << *it->second;
            os << " | ";
        }
        os << ']';
        return os;
    }    

};