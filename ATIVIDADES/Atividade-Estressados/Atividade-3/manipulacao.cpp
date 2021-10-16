#include <iostream>
#include <vector>

using namespace std;

std::ostream& operator<<(std::ostream& os, const std::vector<int>& v) 
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
vector<int> diferentes(const vector<int>& vetor) 
{
    vector<int> vetor_copia;
    bool check {false};
    for (int j = 0; j < (int)vetor.size(); j++) {
        for (int i = 0; i < j; i++) {
            if (vetor[i] == vetor[j] || vetor[i] == -vetor[j]) {
                check = true;
                break;
            } else {
                check = false;
            }
        }
        if (check == false) {
            if (vetor[j] > 0) {
                vetor_copia.push_back(vetor[j]);
            } else {
                vetor_copia.push_back(-vetor[j]);
            }
        }
    }
    return vetor_copia; 
}

vector<int> sozinhos(const vector<int>& vetor)
{
    vector<int> vetor_copia;
    int contador {0};
    for (int j = 0; j < (int)vetor.size(); j++) {
        for (int i = 0; i < (int)vetor.size(); i++) {
            if (vetor[i] == vetor[j] || vetor[i] == -vetor[j]) {
                contador++;  
            }
        }
        if (contador == 1) {
            vetor_copia.push_back(vetor[j]);
        }
        contador = 0;
    }
    return vetor_copia;
}

int mais_ocorrencias(const vector<int>& vetor)
{
    int contador {0}, maior_ocorrencia{0};
    for (int j = 0; j < (int)vetor.size(); j++) {
        for (int i = 0; i < (int)vetor.size(); i++) {
            if (vetor[i] == vetor[j] || vetor[i] == -vetor[j]) {
                contador++;  
            }
        }
        if (contador > maior_ocorrencia) {
            maior_ocorrencia = contador;
        }
        contador = 0;
    }
    return maior_ocorrencia;
}

vector<int> mais_recorrentes(const vector<int>& vetor)
{
    vector<int> vetor_copia;
    int maior_ocorrencia {mais_ocorrencias(vetor)};
    int contador {0};
    for (int j = 0; j < (int)vetor.size(); j++) {
        for (int i = 0; i < (int)vetor.size(); i++) {
            if (vetor[i] == vetor[j] || vetor[i] == -vetor[j]) {
                contador++;  
            }
        }
        if (contador == maior_ocorrencia) {
            vetor_copia.push_back(vetor[j]);
        }
        contador = 0;
    }
    vector<int> vetor_copia_true {diferentes(vetor_copia)};
    return vetor_copia_true;
}

int main()
{
    cout << sozinhos({1, 3, 4, 3, -1, -3, -3}) << '\n';
    cout << mais_ocorrencias({1, 3, 4, 5, -1, -5, -5}) << '\n';
    cout << mais_recorrentes({1, 3, 4, 5, -1, -5, -5, 3, -3}) << '\n';
}