#pragma once
#include "account.hpp"

class SavingsAccounts : public Account {

public:
    SavingsAccounts(int id, string clientId) : Account{id, clientId} {
        this->type = "CP";
    };

    virtual void monthlyUpdate() override {
        this->balance += this->balance * 0.01;
    }
};