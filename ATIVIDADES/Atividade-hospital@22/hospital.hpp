#pragma once
#include <iostream>
#include <map>
#include <vector>
#include "iMedico.hpp"
#include "iPaciente.hpp"
#include "medico.hpp"
#include "auxiliar.hpp"
#include <memory>

using namespace std;

class Hospital {
    map<string, shared_ptr<IMedico>> medicos;
    map<string, shared_ptr<IPaciente>> pacientes;

    //Checka se ja ha um medico com a mesma classe cuidando do paciente
    bool medicoNaoRepetido(IPaciente* p, IMedico* m) {
        auto medicos = p->getMedicos();
        for (auto medico : medicos) {
            if (medico->getClasse() == m->getClasse()) {
                return false;
            }
        }
        return true;
    }

public:
    Hospital() {}
    
    IPaciente* getPaciente(string nome) {
        auto it = this->pacientes.find(nome);
        if (it == this->pacientes.end()) {
            throw "Erro ao buscar objeto";
        }
        return it->second.get();
    }

    IMedico* getMedico(string nome) {
        auto it = this->medicos.find(nome);
        if (it == this->medicos.end()) {
            throw "Erro ao buscar objeto";
        }
        return it->second.get();
    }

    void addPaciente(shared_ptr<IPaciente> paciente) {
        auto key = paciente->getId();
        if (this->pacientes.find(key) == this->pacientes.end()) {
            this->pacientes[key] = paciente;
        } else {
            throw "Paciente ja existe";
        }
    }

    void addMedico(shared_ptr<IMedico> medico) {
        auto key = medico->getId();
        if (this->medicos.find(key) == this->medicos.end()) {
            this->medicos[key] = medico;
        } else {
            throw "Medico ja existe";
        }
    }

    void removerPaciente(string sender) {
        auto medicos = this->getPaciente(sender)->getMedicos();
        for (auto medico : medicos) {
            medico->removerPaciente(sender);
        }
        auto it = this->pacientes.find(sender);
        this->pacientes.erase(it);
    }

    void removerMedico(string sender) {
        auto pacientes = this->getMedico(sender)->getPacientes();
        for (auto paciente : pacientes) {
            paciente->removerMedico(sender);
        }
        auto it = this->medicos.find(sender);
        this->medicos.erase(it);
    }

    void vincular(string nomeMedico, string nomePaciente) {
        auto medico = this->getMedico(nomeMedico);
        auto paciente = this->getPaciente(nomePaciente);

        if(this->medicoNaoRepetido(paciente, medico) == true) {
            medico->addPaciente(paciente);
        } else {
            throw "Medico com esta função ja esta alocado neste paciente";
        }

    }

    friend ostream& operator<<(ostream& os, const Hospital& h) {
        os << "Manager";
        for (auto& medico : h.medicos){
            os << "\n" << *dynamic_cast<Medico*>(medico.second.get());
        }

        for (auto& pacientes : h.pacientes){
            os << "\n" << *dynamic_cast<Paciente*>(pacientes.second.get());
        }

        return os;
    }
};
