//3º DG. Manuel Sánchez Torrón. DG22
#include <iostream>
#include "Matriz.h"

using namespace std;

bool resuelve(){

    int n;
    cin >> n;

    if (n==0) return false;

    vector<string> codigos(n);

    for (int i = 0; i < n; i++) {
        cin >> codigos[i];
    }

    string codificado;
    cin >> codificado;
    int t = codificado.size();

    vector <int> v(t + 1, 0);
    v[0] = 1;

    for (int i = 1; i <= t; i++) {
        if (codificado[i-1] == '0') {
            v[i] = v[i-1];
        }
        else {
            for (int j = 0; j < n; j++) {
                if (codigos[j].size() <= i && codificado.compare(i-codigos[j].size(), codigos[j].size(), codigos[j])==0) {
                    v[i] += v[i-codigos[j].size()];
                    v[i] %= 1000000007;
                }
            }

        }
    }
    cout << v[t] << endl;
    return true;
}



int main() {

    while (resuelve()){}

    return 0;
}