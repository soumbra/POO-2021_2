#pragma once
#include <list>
#include <memory>
#include "kid.hpp"

class Trampoline{
    list <shared_ptr<Kid>> waiting;
    list <shared_ptr<Kid>> playing;
public:
    Trampoline(){}

    void arrive(const shared_ptr<Kid>& kid) {
        this->waiting.push_back(kid);
        cout << "Entrou na fila de espera" << '\n';
    }

    void in() {
        if (waiting.size() == 0) {
            cout << "Lista de espera vazia" << '\n';
        }
        else{
            this->playing.push_back(this->waiting.front());
            this->waiting.pop_front();
            cout << "Entrou no pula pula" << '\n';
        }
    }

    void out() {
        if (playing.size() == 0) {
            cout << "Lista dos que estão brincando está vazia" << '\n';
        }else {
            this->waiting.push_back(this->playing.front());
            this->playing.pop_front();
        }
    }

    bool papaiChegou(string name) {
        for (auto kid : this->waiting) {
            if(kid->getName() == name){
                this->waiting.remove(kid);
                return true;
            }
        }

        for (auto kid : this->playing) {
            if(kid->getName() == name){
                this->playing.remove(kid);
                return true;
            }
        }
        return false;
    }
    
    friend ostream& operator<<(ostream& os, const Trampoline& t) {
        os << "\nEspera: ";
        for (auto kid : t.waiting) {
            os << *kid << " ";
        }

        os << "\nBrincando: ";
        for (auto kid: t.playing) {
            os << *kid << "";
        }

        return os;
    }
};