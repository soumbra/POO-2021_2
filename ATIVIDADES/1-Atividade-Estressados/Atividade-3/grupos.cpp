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

void remove(vector <int> &vetor, int indice) {
    vetor.erase(vetor.begin() + indice);
}

int casais(vector<int> vetor)
{
    int casais{0};

    for (int j = 0; j < (int)vetor.size(); j++) {
        for (int i = j + 1; i < (int)vetor.size(); i++) {
            if (vetor[j] == -vetor[i] || -vetor[j] == vetor[i]) {
                casais++;
                remove(vetor, j);
                remove(vetor, i-1);
            }
        }
    }

    return casais;
}

int main()
{
    cout << casais({1, 10, -1, 1, -1, 1, -10, 5}) << '\n';

    return 0;
}