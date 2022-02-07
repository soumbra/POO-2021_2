#pragma once
#include "client.hpp"
#include <vector>
#include <memory>

class Sala{
    vector<shared_ptr<Client>> cadeiras;

    bool validarIndice(int indice) {
        if (indice < 0 || indice >= (int) this->cadeiras.size()) {
            cout << "cadeira inexistente\n";
            return false;
        }
        return true;
    }

    bool validarClient(string id) {
        for (int i = 0; i < (int) this->cadeiras.size(); i++) {
            if(this->cadeiras[i] != nullptr && this->cadeiras[i]->getId() == id){
                return false;
            }
        }
        return true;
    }

public:
    Sala(int qtdCadeiras) : cadeiras(qtdCadeiras, nullptr){}

    bool reservar(const shared_ptr<Client>& client, int indice) {
        if (!this->validarIndice(indice)) {
            return false;
        }

        if(this->cadeiras[indice] != nullptr) {
            cout << "cadeira ocupada" << '\n';
            return false;
        }

        if(!this->validarClient(client->getId())) {
            cout << "Voce ja reservou uma cadeiras, deixe de xafurdo!" << '\n';
            return false;
        }
       
        this->cadeiras[indice] = client;
        return true;

    } 

    bool cancelar(string id) {
        for (int i = 0; i < (int) this->cadeiras.size(); i++) {
            if(this->cadeiras[i] != nullptr && this->cadeiras[i]->getId() == id){
                cadeiras[i] = nullptr;
                cout << "Reserva cancelada" << '\n';
                return true;
            }
        }
        return false;
       
    }

    vector<shared_ptr<Client>> getCadeiras() {
        return this->cadeiras;
    }

    friend ostream& operator<<(std::ostream& os, const Sala& s) {
        for (int i = 0; i < (int) s.cadeiras.size(); i++) {
            auto& cadeira = s.cadeiras[i];
            os << i << ":" ;
            if (cadeira != nullptr)
                os << *cadeira;
            else
                os << "----";
            os << " | ";
        }
        return os;
    }    

};