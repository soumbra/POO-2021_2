#include<iostream>

using namespace std;

struct Pessoa {
    string nome;
    int idade;

    Pessoa (string nome = "", int idade = 0) :
        nome{nome}, idade{idade} {
    }

    friend std::ostream& operator <<(std::ostream& os, const Pessoa& pessoa) {
        os << "Nome: " << pessoa.nome << " ";
        os << "Idade: " << pessoa.idade << " anos";

        return os;
    }
};

struct Motinha {
    Pessoa* pessoa;
    int potencia;
    int tempo;

    Motinha (Pessoa* pessoa = nullptr, int potencia = 1, int tempo = 0):
        pessoa{pessoa}, potencia{potencia}, tempo{tempo} {
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

    void dirigirTempo() {
        if (this->pessoa->idade <= 10 && tempo > 0){
            cout << "Voce pode andar de motinha" << '\n';
            int contador{0};
            while (tempo !=0) {
                tempo--;
                contador++;
            }
            cout << "Voce andou por " << contador << " minutos" << '\n';
        }    
    }

    void buzinar() {
        cout << 'P';
        for (int i = 0; i < potencia; i++) {
            cout << 'e';
        }
        cout << 'm' << '\n';
    }
    
};

int main() 
{
    Pessoa jorjin ("barbosinha", 10);
    cout << jorjin << '\n';
    
    Motinha moto(&jorjin, 7, 5);
    moto.comprarTempo(5);
    moto.dirigirTempo();
    moto.buzinar();
    
    Pessoa larouci ("larouci ", 4);
    moto.descer();
    moto.subir(&larouci);
    moto.comprarTempo(9);
    moto.dirigirTempo();

    return 0;
}