#include <iostream>
#include <vector>

using namespace std; 

float calcular_stress_medio(vector<int> vetor)
{
    int homens {0}, mulheres{0};
    for (int i = 0; i < (int) vetor.size(); i++) {
        if (vetor[i] > 0) {
            homens += vetor[i];
        } else {
            mulheres += -vetor[i];
        }
    }
    float media_stress {(float) (homens + mulheres)/vetor.size()};
    return media_stress;
}

string mais_homens_ou_mulheres(vector<int> vetor) 
{
    int homens {0}, mulheres{0};
    for (int i = 0; i < (int) vetor.size(); i++) {
        if (vetor[i] > 0) {
            homens++;
        } else {
            mulheres++;
        }
    }
    if (homens > mulheres) {
        return "homens";
    } else if (mulheres > homens) {
        return "mulheres";
    }
    return "empate";
}

string qual_metade_eh_mais_estressada(vector<int> vetor) 
{
    float primeira_metade {0}, segunda_metade{0};
    int contador {(int) vetor.size()/2};
    for (int i = 0; i < (int) vetor.size() /2; i++) {
        if (vetor[i] > 0) {
            primeira_metade += vetor[i];
        } else {
            primeira_metade += -vetor[i];
        }
    }
    if (vetor.size() % 2 == 1) {
        contador++;
    }
    for (int i = contador; i < (int) vetor.size(); i++) {
        if (vetor[i] > 0) {
            segunda_metade += vetor[i];
        } else {
            segunda_metade += -vetor[i];
        }
    }
    if (primeira_metade > segunda_metade) {
        return "Primeira";
    } else if(primeira_metade < segunda_metade) {
        return "Segunda";
    }
    return "Empate";
}

bool homens_sao_mais_estressados_que_mulheres(vector<int> vetor)
{
    int homens {0}, mulheres {0}, conta_homens {0}, conta_mulheres{0};
    for (int i = 0; i < (int) vetor.size(); i++) {
        if (vetor[i] > 0) {
            homens += vetor[i];
            conta_homens++;
        } else {
            mulheres += -vetor[i];
            conta_mulheres++;
        }
    }
    float media_stress_homens {(float) homens/conta_homens};
    float media_stress_mulheres {(float) mulheres/conta_mulheres};
    if(media_stress_homens > media_stress_mulheres){
        return true;
    }
    return false;
}

int main()
{
    vector<int> fila {91, 9, -80, 19};
    cout << calcular_stress_medio(fila) << '\n';
    cout << mais_homens_ou_mulheres(fila) << '\n';
    cout << qual_metade_eh_mais_estressada(fila) << '\n';
    cout << homens_sao_mais_estressados_que_mulheres(fila) << '\n';
}