#pragma once
#include "account.hpp"

class CheckingAccount : public Account {

public:
    CheckingAccount(int id, string clientId) : Account{id, clientId} {
        this->type = "CC";
    };

    virtual void monthlyUpdate() override {
        this->balance -= 20;
    }
};