#include <iostream>

using namespace std;

class Veiculo{
    string tipo;

protected:
    bool funcionando{true};

public:
    Veiculo(string tipo = "Motorizado") : tipo{tipo}{};

    virtual ~Veiculo() {};

    virtual void dirigir() const {
        if (this->funcionando) {
            cout << "Dirigindo.." << '\n';
            cout << "Chegou ao destino" << '\n';
        } else {
            cout << "Veiculo com defeito" << '\n';
        }
    }

    virtual void acidente() {
        cout << "Foi um acidente :(" << '\n';
        this->funcionando = false;
    }

    virtual void concertar() {
        this->funcionando = true;
        cout << "Veiculo concertado" << '\n';
    }

    virtual string getTipo() const {
        return this->tipo;
    }

    virtual bool estaFuncionando() const {
        return this->funcionando;
    }

    friend ostream& operator<<(ostream& os, const Veiculo& v) {
        os << "Veiculo " << v.tipo << ":" << (v.funcionando ? "Funcionando" : "Com defeito");
        return os;
    }

};

class VeiculoMotorizado : public Veiculo{
    string motor;
protected:
    float tanque{3};
    int tamanhoTanque;

public:
    VeiculoMotorizado(string motor = "Aspirado", int tamanhoTanque = 40) : 
    Veiculo{"Motorizado"}, motor{motor}, tamanhoTanque{tamanhoTanque}  {};

    virtual ~VeiculoMotorizado() {};

    virtual void comprarCombustivel(float litros) {
        float total{litros + tanque};
        if (total > this->tamanhoTanque) {
            total = this->tamanhoTanque;
        } 
        this->tanque = total;
        cout << "Combustivel adicionado ao tanque" << '\n';
    }

    virtual void dirigir(float distancia, float kmLitro) {
        float q = (distancia/kmLitro);
        if (this->funcionando && tanque > 1) {
            cout << "Dirigindo." << '\n';
            this->tanque -= q;
            if (this->tanque <= 0) {
                cout << "Nao foi possivel concluir o trajeto, ligue para um reboque." << '\n';
                this->tanque = 0;
                return;
            } else {
                cout << "Chegou ao destino" << '\n'; 
            }         
        } else {
            cout << "Veiculo com defeito nao ha como dirigir ou falta de combustivel" << '\n';
        }
    }

    virtual string getMotor() const {
        return this->motor;
    }

    virtual float getQtdCombustivel() const {
        return this->tanque;
    }

    friend ostream& operator<<(ostream& os, const VeiculoMotorizado& v) {
        const Veiculo& veiculo = v;
        os << veiculo << ":" << v.motor << ":" << v.tamanhoTanque;
        return os;
    }

};

class Carro : public VeiculoMotorizado{
    string modelo;
    string nome;

public:
    Carro(string motor, int tamanhoTanque, string modelo = "Muscle car", string nome = "Charger 1968") : 
    VeiculoMotorizado{motor, tamanhoTanque}, modelo{modelo}, nome{nome} {};

    virtual ~Carro() {};
    
    virtual void guardarCoisas() const {
        cout << "Guardando suas coisas no porta-malas." << '\n';
    }

    virtual void ligarSom() const {
        cout << "Agora o som esta ligado" << '\n';
    }

    virtual void desligarSom() const {
        cout << "Agora o som esta desligado" << '\n';
    }

    virtual void buzinar() const {
        cout << "biiiiiiiiiiiiiiiiii" << '\n';
    }

    virtual string getModelo() const {
        return this->modelo;
    }

    virtual string getNome() const {
        return this->nome;
    }

    friend ostream& operator<<(ostream& os, const Carro& c) {
        const VeiculoMotorizado& veiculo = c;
        os << veiculo << ":" << c.modelo << ":" << c.nome;
        return os;
    }

};

int main()
{
    Veiculo biri{"Carro"};
    cout << biri << '\n';

    VeiculoMotorizado carro{"Hibrido"};
    cout << carro << '\n';
    carro.dirigir(30, 10);
    carro.acidente();
    carro.dirigir(30, 10);

    Carro gol{"Aspirado", 50, "Hatchback", "Gol G4"};
    cout << gol << '\n';
    gol.dirigir(40, 10);
    cout << gol.getQtdCombustivel() << '\n';
    gol.comprarCombustivel(1.5);
    gol.dirigir(12.7, 10);
    cout << gol.getQtdCombustivel() << '\n';
    gol.ligarSom();
    gol.buzinar();
    gol.guardarCoisas();
    gol.desligarSom();

}