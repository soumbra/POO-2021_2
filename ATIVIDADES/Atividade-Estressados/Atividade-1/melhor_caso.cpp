#include <iostream>
#include <vector>

using namespace std;

int procurar_melhor_se(vector<int> vetor)
{
    int contador {-1}, mais_calmo{100};
    for (int i = 0; i < (int) vetor.size(); i++) {
        if (vetor[i] > 0 && vetor[i] < mais_calmo) {
            contador = i;
            mais_calmo = vetor[i];
        }
    }
    return contador;
}

int procurar_menor_pos_apartir(vector<int> vetor, int inicio)
{
    int contador {inicio}, menor{vetor[inicio]};
    for (int i = inicio; i < (int) vetor.size(); i++) {
        if (vetor[i] < menor) {
            menor = vetor[i];
            contador = i;
        }
    }
    return contador;
}

int procurar_menor_pos(vector<int> vetor)
{
    int contador {0}, menor {vetor[0]};
    for (int i = 0; i < (int) vetor.size(); i++) {
        if (vetor[i] < menor) {
            menor = vetor[i];
            contador = i;
        }
    }
    return contador;
}

int procurar_menor(vector<int> vetor)
{
    int menor {vetor[0]};
    for (int i = 0; i < (int) vetor.size(); i++) {
        if (vetor[i] < menor) {
            menor = vetor[i];
        }
    }
    return menor;
}

int main()
{
    vector<int> fila {10, 7, -2, -6, -3};
    cout << procurar_menor(fila) << '\n';
    cout << procurar_menor_pos(fila) << '\n';
    cout << procurar_menor_pos_apartir(fila, 2) << '\n';
    cout << procurar_melhor_se(fila) << '\n';
}