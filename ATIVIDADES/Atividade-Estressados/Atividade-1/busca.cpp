#include <iostream>
#include <vector>

using namespace std;

int procura_valor_apartir(vector<int> vetor , int valor, int posicao)
{
    for (int i = posicao; i < (int) vetor.size(); i++) {
        if (vetor[i] == valor) {
            return i;
        }
    }
    return -1;
}

int procura_valor(vector<int> vetor, int valor)
{
    for (int i = 0; i < (int) vetor.size(); i++) {
        if (vetor[i] == valor) {
            return i;
        }
    }
    return -1;
}

int contar(vector<int> vetor, int valor)
{
    int contador = 0;
    for (int i = 0; i < (int) vetor.size(); i++) {
        if (vetor[i] == valor) {
            contador++;
        }
    }
    return contador;
}

bool existe(vector<int> vetor, int valor)
{
    for (int i = 0; i < (int) vetor.size(); i++) {
        if (vetor[i] == valor) {
            return true;
        }
    }

    return false;
}

int main()
{
    vector<int> lista{1, 5, -2, -1, 5};
    cout << existe(lista, 10) << '\n';
    cout << contar(lista, 2) << '\n';
    cout << procura_valor(lista, 2) << '\n';
    cout << procura_valor_apartir(lista, 2, 5) << '\n';
}