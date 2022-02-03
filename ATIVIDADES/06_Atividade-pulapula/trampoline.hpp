#pragma once
#include <list>
#include <memory>
#include "kid.hpp"

class Trampoline{
    list <shared_ptr<Kid>> waiting;
    list <shared_ptr<Kid>> playing;

    shared_ptr<Kid> remove_kid(string name, list<shared_ptr<Kid>>& list) {
        for (auto& kid : list) {
            if(kid->getName() == name){
                shared_ptr<Kid> k = kid;
                list.remove(kid);
                return k;
            }
        }
        return nullptr;
    }

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

    shared_ptr<Kid> papaiChegou(string name) {
        auto k = remove_kid(name, this->waiting);
        if (k != nullptr) {
            return k;
        }

        auto k2 = remove_kid(name, this->playing);
        if (k2 != nullptr) {
            return k2;
        }

        return nullptr;
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