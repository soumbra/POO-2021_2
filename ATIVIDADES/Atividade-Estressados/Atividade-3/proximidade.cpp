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

vector<int> transforma_valores(const vector<int>& vetor)
{
    vector<int> vetor_copia;
    for (int valor : vetor) {
        if (valor > 0) {
            vetor_copia.push_back(valor);
        } else {
            vetor_copia.push_back(-valor);
        }
    }
    return vetor_copia;   
}

int briga(const vector<int>& vetor) 
{
    vector<int> vetor_copia{transforma_valores(vetor)};
    
    int contador {0};
    for (int i = 0; i < (int)vetor.size() - 1; i++) {
        if (vetor_copia[i] > 50 && vetor_copia[i -1] > 30 && vetor_copia[i+1] > 30) {
            contador++;
        }
    }

    return contador;
}

vector<int> apaziguado(const vector<int>& vetor)
{
    vector<int> vetor_passagem{transforma_valores(vetor)};
    vector<int> vetor_copia;
    int tamanho {(int)vetor_passagem.size()};
    
    for (int i = 0; i < tamanho; i++) {
        if (i == 0 && (vetor_passagem[i] > 80 && vetor_passagem[i + 1] < 10)) {
            vetor_copia.push_back(i);
        } else if (i == tamanho - 1 && (vetor_passagem[i] > 80 && vetor_passagem[i - 1] < 10)) {
            vetor_copia.push_back(i);
        } else if ((i != 0 && i != tamanho - 1) && ((vetor_passagem[i] > 80 && vetor_passagem[i - 1] < 10) || (vetor_passagem[i] > 80 && vetor_passagem[i + 1] < 10))) {
            vetor_copia.push_back(i);
        }
    }

    return vetor_copia;
}

int main()
{
    cout << briga({20, 56, -36, 54, 56, -66, -50}) << '\n';
    cout << apaziguado({82, 6, -86, -3, -88}) << '\n';

    return 0;
}