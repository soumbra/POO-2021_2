#pragma once
#include "account.hpp"
#include <vector>
#include <memory>

class Client{
    string clientId;
    vector<shared_ptr<Account>> accounts;

public:
    Client(string clientId) : clientId{clientId} {};

    virtual void addAccount(const shared_ptr<Account>& account) {
        this->accounts.push_back(account);
    }

    virtual string getClientId() const {
        return this->clientId;
    }

    virtual vector<shared_ptr<Account>> getAccounts() const {
        return this->accounts;
    }

    virtual void setClientId(string newClientId) {
        this->clientId = newClientId;
    }

    virtual void setAccounts(vector<shared_ptr<Account>> accounts) {
        this->accounts = accounts;
    }

    friend std::ostream& operator<<(std::ostream& os, const Client& a) {
        os << a.clientId << '[';
        for(int i = 0; i < (int)a.accounts.size(); i++){
            os << a.accounts[i]->getId() << ((i+1 < (int)a.accounts.size()) ? "," : ""); 
        }
        os << ']' << '\n';

        return os;
    }

};