#include <iostream>
#include <vector>
#include <algorithm>
#include "Matriz.h"
typedef struct{
    int coste;
    int longitud;
} varilla;

bool resuelve(){

    int n, l;
    std::cin >> n >> l;

    if (!std::cin) return false;

    std::vector<varilla> varillas;

    varilla v={0, 0};
    varillas.push_back(v);
    for (int i=0; i<n; i++){
        std::cin >> v.longitud >> v.coste;
        varillas.push_back(v);
    }

    Matriz<int> formas(n+1,l+1); //formas[i][j]=formas de hacer varilla de longitud j usando las i primeras
    Matriz<int> minCoste(n+1,l+1);//minCoste[i][j] = coste minimo de hacer varilla de longitud j usando las i primeras
    Matriz<int> minVarillas(n+1,l+1); //minVarillas[i][j]= minimo nº de varillas necesarias para hacer varilla de longitud j usando las i primeras

    //CASOS BASE
    int k=0, j=0;
    while(k <= l || j <= n){
        if(k <= l) {
            minVarillas[0][k] = INT32_MAX;
            formas[0][k] = 0;
            minCoste[0][k] = INT32_MAX;
            k++;
        }
        if (j <= n){
            minVarillas[j][0] = 0;
            formas[j][0] = 1;
            minCoste[j][0] = 0;
            j++;
        }
    }

    //CASOS RECURSIVOS
    for(int i=1;i<=n;i++){
        for(int j=1; j<=l; j++){
            if (varillas[i].longitud > j ){//Con estas no podemos hacer nada
                formas[i][j] = formas[i-1][j];
                minCoste[i][j] = minCoste[i-1][j];
                minVarillas[i][j] = minVarillas[i - 1][j];

            } else {
                if (minVarillas[i - 1][j - varillas[i].longitud] == INT32_MAX){
                    minVarillas[i][j] = minVarillas[i - 1][j];
                } else {
                    minVarillas[i][j] = std::min(minVarillas[i - 1][j], minVarillas[i - 1][j - varillas[i].longitud] + 1);
                }
                if ( minCoste[i-1][j - varillas[i].longitud] == INT32_MAX){
                    minCoste[i][j] = minCoste[i-1][j];
                } else{
                    minCoste[i][j] = std::min(minCoste[i-1][j], minCoste[i-1][j-varillas[i].longitud] + varillas[i].coste);
                }

                formas[i][j] = formas[i-1][j] + formas[i-1][j - varillas[i].longitud];
            }
        }
    }

    int f = formas[n][l];

    if (f != 0){
        std::cout << "SI " << f << " " << minVarillas[n][l] <<" "<< minCoste[n][l] <<std::endl;
    } else{
        std::cout << "NO" << std::endl;
    }
    return true;
}
int main() {
    while(resuelve());
    return 0;
}