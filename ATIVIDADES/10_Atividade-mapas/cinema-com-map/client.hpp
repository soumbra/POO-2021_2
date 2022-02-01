#pragma once
#include<iostream>

using namespace std;

class Client{
    string fone;
    string id;

public:
    Client(string fone = "", string id = "") : 
    fone{fone} ,id{id} {
    }
    
    string getFone(){
        return this->fone;
    }

    string getId(){
        return this->id;
    }

    friend std::ostream& operator<<(std::ostream& os, Client cliente) {
        os << "Telefone:" << cliente.fone << " Id:" << cliente.id;
        return os;
    }

    
};