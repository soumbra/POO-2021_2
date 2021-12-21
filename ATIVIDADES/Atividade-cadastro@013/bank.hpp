#pragma once
#include "client.hpp"
#include "savingsAccount.hpp"
#include "checkingAccount.hpp"
#include <map>

class BankAgency{
    map<string, shared_ptr<Client>> clients;
    map<int, shared_ptr<Account>> accounts;
    int nextAccountId {0};

    shared_ptr<Account> getAccount(int id) {
        auto it = this->accounts.find(id);
        if (it == this->accounts.end()) {
            throw "Conta nao encontrada";
        }

        return it->second;
    }

public:
    BankAgency() {};

    void addAccount(string clientId) {
        auto it = this->clients.find(clientId);
        if(it != this->clients.end()) {
            throw "Voce ja e nosso client";
        }

        Client c{clientId};

        SavingsAccounts sa{this->nextAccountId, clientId};
        c.addAccount(make_shared<SavingsAccounts>(sa));
        this->accounts[this->nextAccountId] = make_shared<SavingsAccounts>(sa);

        this->nextAccountId++;

        CheckingAccount cc{this->nextAccountId, clientId};
        c.addAccount(make_shared<CheckingAccount>(cc));
        this->accounts[this->nextAccountId] = make_shared<CheckingAccount>(cc);

        this->clients[clientId] = make_shared<Client>(c);
        this->nextAccountId++;

    }

    void withdraw(int idConta, float value) {
        shared_ptr<Account> conta {getAccount(idConta)};
        conta->withdraw(value);

    }

    void deposit(int idConta, float value) {
        shared_ptr<Account> conta {getAccount(idConta)};
        conta->deposit(value);

    }

    void transfer(int contaDe, int contaPara, float value) {
        shared_ptr<Account> conta {getAccount(contaDe)};
        shared_ptr<Account> conta2 {getAccount(contaPara)};

        conta->transfer(conta2, value);
    }

    void monthlyUpdate() {
        for (auto it = this->accounts.begin(); it != this->accounts.end(); ++it) {
            it->second->monthlyUpdate();
        }
    }

    friend std::ostream& operator<<(std::ostream& os, const BankAgency& ba) {
        os << "Clients:\n";
        for (auto it = ba.clients.begin(); it != ba.clients.end(); ++it) {
            os << *it->second;
        }
        os << "Accounts:\n";
        for (auto it = ba.accounts.begin(); it != ba.accounts.end(); ++it) {
            os << *it->second;
        }

        return os;
    }

};
