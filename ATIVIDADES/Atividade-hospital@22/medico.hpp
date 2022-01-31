#pragma once
#include <iostream>
#include <map>
#include <vector>
#include "iMedico.hpp"
#include "iPaciente.hpp"
#include "auxiliar.hpp"

class Medico : public IMedico {
    string nome;
    string classe;
    map<string, IPaciente*> pacientes;

public:

    Medico(string nome, string classe) : nome{nome}, classe{classe} {}

    virtual ~Medico() {}

    virtual string getId() {
        return this->nome;
    }

    virtual void addPaciente(IPaciente* paciente) override{
        auto key = paciente->getId();
        if (this->pacientes.find(key) == this->pacientes.end()) {
            this->pacientes[key] = paciente;
            paciente->addMedico(this);
            return;
        }
    }

    virtual void removerPaciente(string idPaciente) override{
        auto it = this->pacientes.find(idPaciente);
        if (it != this->pacientes.end()) {
            auto paciente = it->second;
            this->pacientes.erase(it);
            paciente->removerMedico(this->nome);
        }

    }

    virtual vector<IPaciente*> getPacientes() override{
        vector<IPaciente*> result;
        for (auto& pacient : pacientes) {
            result.push_back(pacient.second);
        }
        return result; 
    }
    
    virtual string getClasse() override{
        return this->classe;
    }

    friend ostream& operator<<(ostream& os, const Medico& m) {
        os << "Med:" << m.nome << ":" << m.classe;
        os << " Pacs" << '[';
        if((int)m.pacientes.size() != 0) {
            for (auto &paciente : m.pacientes) {
                os << paciente.first << ',';
            }
        }
        os << ']';
        return os;
    }

};
