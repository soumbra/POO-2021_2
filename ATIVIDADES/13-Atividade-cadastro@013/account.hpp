#pragma once
#include <iostream>
#include <memory>

using namespace std;

class Account{
protected:
    int id;
    float balance {0};
    string clientId;
    string type;

public:
    Account(int id, string clientId) : id(id), clientId(clientId) {};

    virtual ~Account() {};

    virtual void monthlyUpdate() = 0;

    virtual void withdraw(float value) {
        if (value <= 0) {
            throw "Valor invalido";
        }

        if (this->balance < value) {
            throw "Saldo insuficiente";
        }

        this->balance -= value;
    }

    virtual void deposit(float value) {
        if (value <= 0) {
            throw "Valor invalido";
        }
    
        this->balance += value;

    }

    virtual void transfer(shared_ptr<Account> other, float value) {
        this->withdraw(value);
        other->deposit(value);
    }

    virtual int getId() const {
        return this->id;
    }

    virtual float getBalance() const {
        return this->balance;
    }
    
    virtual string getClientId() const {
        return this->clientId;
    }
    
    virtual string getType() const {
        return this->type;
    }

    friend std::ostream& operator<<(std::ostream& os, const Account& a) {
        os << a.id << ':' << a.clientId << ':' << a.balance << ':' << a.type << '\n';
        return os;
    }
};