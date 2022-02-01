#pragma once
#include <iostream>
#include <vector>
#include "auxiliar.hpp"

using namespace std;

class IPaciente;

class IMedico{
public:
    virtual ~IMedico(){}
    virtual string getId() = 0;
    virtual void addPaciente(IPaciente* paciente) = 0;
    virtual void removerPaciente(string idPaciente) = 0;
    virtual vector<IPaciente*> getPacientes() = 0;
    virtual string getClasse() = 0;
};