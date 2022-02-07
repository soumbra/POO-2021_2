#pragma once
#include <iostream>

using namespace std;

class Grafite{
    float calibre;
    string dureza;
    int tamanho;

public:
    Grafite(float calibre = 0.0, string dureza = "" , int tamanho = 0) : calibre{calibre}, dureza{dureza}, tamanho{tamanho}  {};

    float getCalibre() {
        return this->calibre;
    }

    string getDureza() {
        return this->dureza;
    }

    int getTamanho() {
        return this->tamanho;
    }

    int desgastePorFolha() {
        if (this->dureza == "HB" || this->dureza == "hb") {
            return this->tamanho--;
        } else if(this->dureza == "2B" || this->dureza == "2b") {
            return this->tamanho-=2;
        } else if(this->dureza == "4B" || this->dureza == "4b") {
            return this->tamanho-=4;
        } else if (this->dureza == "6B" || this->dureza == "6b") {
            return this->tamanho-=6;
        }
        cout << "Possivelmente voce nao colocou uma dureza correta" << '\n';
        return 0;
    }

    friend ostream& operator<<(ostream& os, const Grafite& grafite) {
        os << "[Calibre: " << grafite.calibre << " mm, ";
        os << "Dureza: " << grafite.dureza << ", ";
        os << "Tamanho: " << grafite.tamanho << " mm] \n";
        return os;
    }

};
