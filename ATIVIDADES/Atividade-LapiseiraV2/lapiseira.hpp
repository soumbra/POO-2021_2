#pragma once
#include "grafite.hpp"
#include <memory>
#include <vector>
#include <algorithm>

class Lapiseira{
    shared_ptr<Grafite> bico = nullptr;
    float calibre;
    vector<std::shared_ptr<Grafite>> tambor;

public:
    Lapiseira(float calibre) : calibre{calibre} {};

    bool inserirGrafite(const shared_ptr<Grafite>& grafite) {
        if (this->calibre == grafite->getCalibre()) {
            this->tambor.push_back(grafite);
            cout << "Adicionado ao tambor" << '\n';
            return true;
        }

        cout << "Calibre incompativel" << '\n';

        return false;
    }

    bool pull() {
        if(this->bico != nullptr){
            cout << "Já existe um grafite no bico" << '\n';
            return false;
        }
        if((int)this->tambor.size() == 0){
            cout << "Tambor vazio" << '\n';
            return false;
        }

        this->bico = this->tambor[0];
        tambor.erase(tambor.begin());
        cout << "Grafite puxado" << '\n';

        return true;
    }

    shared_ptr<Grafite> remover() {
        if(this->bico == nullptr) {
            return nullptr;
        }

        cout << "Grafite removido" << '\n';
        return exchange(this->bico, nullptr);

    }

    void escreverFolha() {
        if (this->bico == nullptr) {
            cout << "Impossivel escrever, sem grafite no bico" << '\n';
        } else if(this->bico->getTamanho() <= 10) {
            cout << "Grafite deve ser retirado, apenas 10 mm ou menos sobrando" << '\n';
        } else {
            bico->desgastePorFolha();
            if(this->bico->getTamanho() >= 10){
                cout << "Folha escrita" << '\n';
            } else {
            cout << "Folha incompleta" << '\n';
            }
        }
    }

    friend std::ostream& operator<<(std::ostream& os, Lapiseira& l) {
        os << "Calibre: " << l.calibre << " ";

        os << "Bico: " ;
        if (l.bico != nullptr) {
            os << *l.bico;
        } else {
            os << "";
        }

        os << "Tambor: ";
        for (int i = 0; i < (int) l.tambor.size(); i++) {
            auto& grafite = l.tambor[i];
            os << i << ":" ;
            os << *grafite;
        }
        return os;
    }
};