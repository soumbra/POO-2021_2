#pragma once
#include <iostream>
#include <vector>
#include "auxiliar.hpp"

using namespace std;

class IMedico;

class IPaciente {
public:
    virtual ~IPaciente(){}
    virtual string getId() = 0;
    virtual void addMedico(IMedico* medico) = 0;
    virtual void removerMedico(string idMedico) = 0;
    virtual vector<IMedico*> getMedicos() = 0;
    virtual string getDiagnostico() = 0;
};
