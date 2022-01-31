#pragma once
#include <iostream>
#include <map>
#include <vector>
#include "iMedico.hpp"
#include "iPaciente.hpp"
#include "medico.hpp"
#include "auxiliar.hpp"

using namespace std;

class Paciente : public IPaciente {
protected:
    string nome;
    string diagnostico;
    map<string, IMedico*> medicos;
public:
    Paciente(string nome, string diagnostico) : nome{nome}, diagnostico{diagnostico} {}

    virtual string getId() override{
        return this->nome;
    }

    virtual void addMedico(IMedico* medico) override{
        auto key = medico->getId();
        if (this->medicos.find(key) == this->medicos.end()) {
            this->medicos[key] = medico;
            medico->addPaciente(this);
        }
    }

    virtual void removerMedico(string idMedico) override{
        auto it = this->medicos.find(idMedico);
        if (it != this->medicos.end()) {
            auto medico = it->second;
            this->medicos.erase(it);
            medico->removerPaciente(this->nome);
        }
    }

    virtual vector<IMedico*> getMedicos() override{
        vector<IMedico*> result;
        for (auto& medico : medicos) {
            result.push_back(medico.second);
        }
        return result; 
    }

    virtual string getDiagnostico() override{
        return this->diagnostico;
    }

    friend ostream& operator<<(ostream& os, const Paciente& p) {
        os << "Pac:" << p.nome << ":" << p.diagnostico;
        os << " Med" << '[';
        if((int)p.medicos.size() != 0) {
            for (auto &medico : p.medicos) {
                os << medico.first << ", ";
            }
        }
        os << ']';
        return os;
    }

};