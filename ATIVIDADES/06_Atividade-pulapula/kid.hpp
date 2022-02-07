#pragma once
#include <iostream>

using namespace std;

class Kid{
    int age;
    string name;   

public:
    Kid(int age = 0, string name = "") :
        age{age}, name{name} {
    }

    friend ostream& operator <<(ostream& os, const Kid& kid) {
        os << "Nome: " << kid.name << " ";
        os << "Idade: " << kid.age << " anos";

        return os;
    }

    int getAge() {
        return this->age;
    }
    
    string getName() {
        return this->name;
    }

};