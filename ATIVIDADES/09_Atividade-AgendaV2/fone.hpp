#pragma once
#include <iostream>

using namespace std;

class Fone{
    string id;
    string number;

public: 
    Fone(string id = "", string number = "") : id{id}, number{number}{};

    string getId() {
        return this->id;
    }

    string getNumber() {
        return this->number;
    }

    static bool validate(string number) {
        for (char c : number) {
            if (c == '0' || c == '1' || c == '2' || c == '3' || c == '4' || c == '5' || c == '6' || c == '7' || c == '8' || c == '9' || c == '.' || c == '(' || c == ')') {
                continue;
            } else {
                cout << "Fone invalido" << '\n';
                return false;
            }
        }
        cout << "Fone valido" << '\n';
        return true;
    }

    friend ostream& operator<<(ostream& os, const Fone& fone) {
        os << fone.id  << ":" << fone.number;
        return os;
    }
    
};