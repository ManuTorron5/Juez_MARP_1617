//Manuel Sánchez Torrón. DG22
#include <iostream>
#include <vector>
#include <algorithm>
#include "Matriz.h"

bool resuelve(){

    int v, s;
    std::cin >> v >> s;

    if (!std::cin) return false;

    std::vector<int> valorSectores;

    valorSectores.push_back(0);

    for (int i=1; i<=s; i++){
        int n;
        std::cin >> n;
        valorSectores.push_back(n);
    }

    Matriz <int> minDardos(s+1, v+1, 0);

    //CASOS BASE
    for (int p=0; p<=v; p++){
        minDardos[0][p]=INT16_MAX;
    }

    minDardos[0][0]=0;


    //CASOS RECURSIVOS

    for (int i=1; i<=s; i++) {
        for (int j = 1; j <= v; j++) {
            if (valorSectores[i]>j){
                minDardos[i][j]=minDardos[i-1][j];
            }
            else {
                minDardos[i][j]=std::min(minDardos[i-1][j],
                                         minDardos[i][j-valorSectores[i]]+1);
            }
        }
    }

    if (minDardos[s][v]==INT16_MAX) {
        std::cout << "Imposible" << std::endl;
        return true;
    }

    std::vector<int> cogidos;

    int i=s;
    int j=v;

    while (i>0 && j>0){
        if (valorSectores[i]<=j && minDardos[i][j]==minDardos[i][j-valorSectores[i]]+1){
            cogidos.push_back(valorSectores[i]);
            j-=valorSectores[i];
        } //Usamos el sector i

        else i--; //No usamos el sector i
    }

    std::cout << minDardos[s][v] << ":";

    auto it = cogidos.begin();
    auto end = cogidos.end();

    while (it!=end){
        std::cout << " " << *it;
        it++;
    }

    std::cout << std::endl;

    return true;
}
int main() {
    while(resuelve());
    return 0;
}