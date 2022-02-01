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

vector<int> remove(const vector<int>& vetor, int valor)
{
    vector<int> vetor_copia;

    for (int i = 0; i < (int)vetor.size(); i++) {
        if (vetor[i] != valor) {
            vetor_copia.push_back(vetor[i]);
        }
    }
    return vetor_copia;
}

vector<int> insert(const vector<int>& vetor, int valor, int posicao)
{
    vector<int> vetor_copia;

    for (int i = 0; i < (int)vetor.size(); i++) {
        vetor_copia.push_back(vetor[i]);
    }
    for (int i = 0; i < (int)vetor_copia.size(); i++) {
        if (i == posicao) {
            vetor_copia[i] = valor;
        }
    }

    return vetor_copia;
}

int main()
{
    cout << remove({10, -5, 76, 21, 30}, 76) << '\n';
    cout << insert({10, -5, 76, 21, 30}, 76, 4) << '\n';

    return 0;
}