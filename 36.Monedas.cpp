//3º DG. Manuel Sánchez Torrón. DG22
#include <iostream>
#include <vector>
#include "Matriz.h"

struct moneda{
    int valor;
    int cantidad;
};


bool resuelve(){

    int n;
    std::cin >> n;

    if (!std::cin) return false;

    std::vector<moneda> monedas(n);

   moneda m;

    for(int i = 0; i<n; i++) {
        std::cin >> m.valor;
        monedas[i]=m;
    }

    for (int i=0; i<n; i++){
        std::cin >> monedas[i].cantidad;
    }

    int C;
    std::cin >> C;


    Matriz<int> M(n+1, C+1);


    //CASOS BASE
    for (int i=0; i<=n; i++){
        M[i][0]=0;
    }
    for (int j=1; j<=C; j++){
        M[0][j]=1000001;
    }



    //CASOS RECURSIVOS
    for(int i = 1; i <= n; i++){
        for(int j = 1;j<=C; j++){
            M[i][j]=M[i-1][j];
            for (int k = 1; k<=monedas[i-1].cantidad && k*monedas[i-1].valor<=j; k++) {
                M[i][j]=std::min(M[i][j], M[i-1][j-k*monedas[i-1].valor]+k);
            }
        }
    }

    int res = M[n][C];
    if (res < 1000001) {
        std::cout << "SI " << res << std::endl;
    }
    else std::cout<< "NO"<< std::endl;

    return true;
}


int main() {

    while (resuelve()){}

    return 0;
}