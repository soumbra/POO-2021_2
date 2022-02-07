#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

ostream& operator<<(ostream& os, const vector<int>& v) 
{
    os << "[ ";
    for (int i = 0; i < (int) v.size(); i++) {
        os << v[i];
        if (i != (int) v.size() -1) {
            os << ", ";
        }
    }  
    os << " ]";
    return os;
}

vector<int> inverter_com_copia(const vector<int>& vetor) 
{
    vector<int> vetor_copia;
    for (int i = (int) vetor.size() - 1; i >= 0; i--) {
            vetor_copia.push_back(-vetor[i]);
    }
    return vetor_copia; 
}

void reverter_inplace(vector<int>& vetor) 
{
    int tamanho{(int) vetor.size()}, contador{1};
    for (int i = 0; i < (int) vetor.size()/2 ; i++) {
        int auxilio_emergencial {-vetor[i]};
        vetor[i] = -vetor[(tamanho - contador)];
        vetor[(tamanho - contador)] = auxilio_emergencial;
        contador++;
    }    
    return;
}

int sortear(const vector<int>& vetor) 
{
    unsigned seed = time(0);
    srand(seed);
    int tamanho {(int) vetor.size()};
    int sorteio {rand()%tamanho};
    return vetor[sorteio];
}

void embaralhar(vector<int>& vetor)
{
    unsigned seed = time(0);
    srand(seed);
    random_shuffle(vetor.begin(), vetor.end());
    return;
}

void ordenar(vector<int>& vetor)
{
    for (int j = 0; j < (int) vetor.size()-1; j++) {
        for (int i = 0; i < (int) vetor.size()-1; i++) {
            if (vetor[i] > vetor[i+1]) {
                int auxiliar {vetor[i+1]};
                vetor[i+1] = vetor[i];
                vetor[i] = auxiliar;
            }
        }
    }
    return;
}

int main()
{
    vector<int> fila {1, 2, -33, 10, 23, -14};
    vector<int> fila2 {1, 10, -24, 30, -1};
    cout << inverter_com_copia({1, 2, -10, -2}) << '\n';
    reverter_inplace(fila);
    cout << fila << '\n';
    cout << sortear({10, 2, 3, 30, -10, 24, 56}) << '\n';
    embaralhar(fila);
    cout << fila << '\n';
    ordenar(fila2);
    cout << fila2 << '\n';
}