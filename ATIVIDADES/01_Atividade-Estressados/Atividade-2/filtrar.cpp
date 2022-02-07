#include <iostream>
#include <vector>

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

vector<int> clone(const vector<int>& vetor)
{
    vector<int> vetor_copia;
    for (int valor : vetor) {
        vetor_copia.push_back(valor);
    }
    return vetor_copia;
}

vector<int> pegar_homens(const vector<int>& vetor)
{
    vector<int> vetor_copia;
    for (int valor : vetor) {
        if (valor > 0) {
            vetor_copia.push_back(valor);
        }
    }
    return vetor_copia;
}

vector<int> pegar_calmos(const vector<int>& vetor)
{
    vector<int> vetor_copia;
    for (int valor : vetor) {
        if ((valor < 10 && valor > 0) || (valor > -10 && valor < 0)) {
            vetor_copia.push_back(valor);
        }
    }
    return vetor_copia;   
}

vector<int> pegar_mulheres_calmas(const vector<int>& vetor)
{
    vector<int> vetor_copia;
    for (int valor : vetor) {
        if (valor > -10 && valor < 0) {
            vetor_copia.push_back(valor);
        }
    }
    return vetor_copia;   
}

int main(){
    vector<int> fila{2, -2, -2, -8};
    cout << clone({10, -3, 7}) << '\n';
    cout << pegar_homens({12, -3, 7}) << '\n';
    cout << pegar_calmos({-11, 3, 7}) << '\n';
    cout << pegar_mulheres_calmas({-21, -3, 7}) << '\n';
    return 0;
}