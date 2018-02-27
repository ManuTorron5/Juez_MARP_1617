//3º DG. Manuel Sánchez Torrón. DG22
#include <iostream>
#include <vector>
#include "Matriz.h"

using namespace std;

bool resuelve(){

    string palabra;

    cin >> palabra;

    if (!cin) return false;

    int tam = palabra.length();

    Matriz<int> M(tam, tam);

    for (int i = 0; i < tam; ++i) {
        M[i][i] = 1;
    }


    int j;
    for (int d = 1; d < tam; ++d) {
        for (int i = 0; i < tam - d; ++i) {
            j = i + d;

            if (palabra[i] == palabra[j]) {
                M[i][j] = M[i + 1][j - 1] + 2;
            }
            else {
                M[i][j] = max(M[i + 1][j], M[i][j - 1]);
            }
        }
    }

    int i = 0;
    j = tam - 1;
    string sol1 = "";
    string sol2="";
    while (i < j) {
        if (palabra[i] != palabra[j]) {
            if (M[i][j] == M[i + 1][j]) {
                ++i;
            }
            else if (M[i][j] == M[i][j - 1]) {
                --j;
            }
        }
        else if (M[i][j] == M[i + 1][j - 1] + 2) {
            sol1 = palabra[j] + sol1;
            sol2 = sol2 + palabra[j];
            ++i;
            --j;
        }
    }

    string sol;
    int n = tam - 1;
    if ((M[0][n] % 2) == 0) {
        sol = sol2 + sol1;
        cout << sol << endl;
    }
    else {
        sol = sol2 + palabra[j] + sol1;
        cout << sol << endl;
    }
    return true;
}



int main() {

    while (resuelve()){}

    return 0;
}