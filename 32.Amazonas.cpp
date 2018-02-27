//3º DG. Manuel Sánchez Torrón. DG22
#include <iostream>
#include <vector>
#include "Matriz.h"

bool resuelve(){

    int n;
    std::cin >> n;

    if (!std::cin) return false;

    Matriz<int> minCoste(n+1,n+1, 0);

    for(int i = 1;i<=n;i++){
        for (int j = i+1; j<=n;j++){
            std::cin >> minCoste[i][j];
        }
    }

    for(int i = 1; i <= n;i++){
        for(int j = i+1;j<=n;j++){
            for(int k = i+1; k <=j; k++){
                minCoste[i][j] = std::min(minCoste[i][j],
                                        minCoste[i][k] + minCoste[k][j]);
            }//El coste minimo de i a j es el minimo de todos los posibles
        }    //ir de i a un poblado intermedio k y de k a j
    }        //El caso k=j es no usar ningun intermedio


    for(int i=1;i<=n;i++){
        for(int j=i+1; j<=n; j++){

            std::cout << minCoste[i][j]<< " ";

        }
        std::cout << std::endl;
    }

    return true;
}


int main() {

    while (resuelve()){}

    return 0;
}