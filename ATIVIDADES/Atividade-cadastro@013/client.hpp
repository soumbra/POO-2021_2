#pragma once
#include "account.hpp"
#include <vector>
#include <memory>

class Client{
    string clientId;
    vector<shared_ptr<Account>> accounts;

public:
    Client(string clientId) : clientId{clientId} {};

    void addAccount(const shared_ptr<Account>& account) {
        this->accounts.push_back(account);
    }

    string getClientId() const {
        return this->clientId;
    }

    vector<shared_ptr<Account>> getAccounts() const {
        return this->accounts;
    }

    void setClientId(string newClientId) {
        this->clientId = newClientId;
    }

    void setAccounts(vector<shared_ptr<Account>> accounts) {
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