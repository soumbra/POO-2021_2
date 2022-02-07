#include<iostream>

using namespace std;

struct Pessoa {
    string nome;
    int idade;

    Pessoa (string nome = "", int idade = 0) :
        nome{nome}, idade{idade} {
    }

    string getNome() {
        return this->nome;
    }

    int getAge() {
        return this->idade;
    }

    friend ostream& operator <<(ostream& os, const Pessoa& pessoa) {
        os << "Nome: " << pessoa.nome << " ";
        os << "Idade: " << pessoa.idade << " anos";

        return os;
    }
};

struct Motinha {
    Pessoa* pessoa = nullptr;
    int potencia;
    int tempo = 0;

    Motinha (int potencia = 1): potencia{potencia} {
    }

    int getPotencia() {
        return this->potencia;
    }

    int getTempo() {
        return this->tempo;
    }

    Pessoa* getPessoa() {
        return this->pessoa;
    }

    bool subir(Pessoa* pessoa) {
        if (this->pessoa != nullptr) {
            cout << "Ja tem alguem na motinha" << "\n";
            return false;
        }
        this->pessoa = pessoa;
        return true;
    }

    Pessoa* descer() {
        if (this->pessoa == nullptr) {
            cout << "Nao tem ninguem na motinha" << '\n';
            return nullptr;
        }

        Pessoa* pessoa = this->pessoa;
        this->pessoa = nullptr;
        cout << "Pessoa desceu" << '\n';
        return pessoa;
    }

    void comprarTempo(int tempoComprar) {
        tempo += tempoComprar;
    }

    void dirigirTempo(int tempo) {
        if (this->pessoa->idade <= 10 && this->tempo > 0 && this->pessoa != nullptr) {
            int res = this->tempo - tempo;
            if (res >= 0) {
                this->tempo -= tempo;
                cout << "Voce completou o trajeto" << '\n';
            } else {
                cout << "Tempo acabou antes do fim do trajeto, Voce andou por " << this->tempo << " minutos" << '\n';
                this->tempo = 0;
            }
        } else {
            cout << "Voce nao pode andar de motinha ou voce nao existe" << '\n';
        }
    }

    void buzinar() {
        cout << 'P';
        for (int i = 0; i < potencia; i++) {
            cout << 'e';
        }
        cout << 'm' << '\n';
    }

    friend ostream& operator <<(ostream& os, const Motinha& m) {
        os << "Potencia: " << m.potencia << ", Minutos: " << m.tempo << ", Pessoa: [" << *m.pessoa << ']';
        return os;
    }
    
};

int main() 
{
    Pessoa jorjin ("barbosinha", 10);
    Pessoa larouci ("larouci ", 12);
    cout << jorjin << '\n';
    
    Motinha moto(7);
    moto.subir(&jorjin);
    moto.subir(&larouci);
    moto.comprarTempo(10);
    moto.dirigirTempo(12);
    moto.buzinar();
    
    cout << moto << '\n';

    moto.descer();
    moto.subir(&larouci);
    moto.comprarTempo(9);
    moto.dirigirTempo(5);

    return 0;
}