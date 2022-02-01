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

vector <int> sequencia(vector<int> vetor, int posicao) 
{   
    vector<int> vetor_copia;
    for (int i = posicao; i < (int) vetor.size(); i++) {
        if (vetor[i] > 0) {
            vetor_copia.push_back(vetor[i]);
        }
        if (vetor[i] > 0 && vetor[i+1] < 0) {
            break;
        }
        if (vetor[i] < 0){
            vetor_copia.push_back(vetor[i]);
        }
        if (vetor[i] < 0 && vetor[i+1] > 0) {
            break;
        }
    }
    return vetor_copia;
}

int quantos_times(const vector<int>& vetor)
{
    int conta_times{0}, contador{0};
    bool check{false};
    for (int i = 0; i < (int)vetor.size(); i++) {
        if ((vetor[i] > 0 && vetor[i+1] > 0) || (vetor[i] < 0 && vetor[i+1] < 0)) {
            check = true;
            contador++;
            if (check == true && contador == 1 && i != (int) vetor.size()-1){
                conta_times++;
            }
        } else {
            check = false;
            contador = 0;
        }

    }
    return conta_times;
}

vector<int> maior_time(const vector<int>& vetor)
{   
    vector<int> vetor_copia;
    int maior = 0;
    for (int i = 0; i < (int) vetor.size(); i++) {
        vector<int> passagem = sequencia(vetor, i);
        if ((int) passagem.size() > maior){
            maior = (int) passagem.size();
            vetor_copia = passagem;
        }
    }
    
    if ((int)vetor_copia.size() == 1) {
        vetor_copia = {};
    }

    return vetor_copia;
}

int sem_time(vector<int> vetor) 
{
    int contador = 0;

    for (int i = 0; i < (int) vetor.size(); i++) {
        if ((vetor[i] > 0 && vetor[i+1] <= 0 && vetor[i-1] <= 0)) {
           contador++;
        }
        if ((vetor[i] < 0 && vetor[i+1] >= 0 && vetor[i-1] >= 0)) {
           contador++;
        }
    }

    return contador;
}

int main()
{
    cout << quantos_times({5, 3, 1, -11, 1, 99, -11, -1, -2, 44}) << '\n';
    cout << maior_time({-5, 3, -1, 15, 1, -99, 11, 1 }) << '\n';
    cout << sem_time({-5, 3, 1, -15, -1, 99, -11, -1, -7 }) << '\n';
    return 0;
}