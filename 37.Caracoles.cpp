//3º DG. Manuel Sánchez Torrón. DG22
#include <iostream>
//#include "Matriz.h"
#include<vector>

using namespace std;

bool resuelve(vector<int> & resultados, vector<int> & C){
    int n;
    cin >> n;
    if (!cin) return false;

    if (n<resultados.size()){
        cout << resultados[n] << endl;
        return true;
    }

    //vector<int> C(n+1,1);
    //vector<int> N(n+1,1);
    for (int i=resultados.size(); i<=n; i++) {
        resultados.push_back(1);
        C.push_back(1);
        for (int k = i - 1; k >= 1; k--) {
            C[k] = (C[k] + C[k - 1]) % 46337;
            resultados[i] = (resultados[i] + C[k] * resultados[i - k]) % 46337;
        }
    }
    cout << resultados[n] << endl;
    return true;
}



int main() {

    vector<int> resultados;
    resultados.push_back(0);
    vector<int> C;

    while (resuelve(resultados, C)){}

    return 0;
}