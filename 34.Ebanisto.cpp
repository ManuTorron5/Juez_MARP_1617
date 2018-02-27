//3º DG. Manuel Sánchez Torrón. DG22
#include <iostream>
#include <vector>
#include "Matriz.h"


bool resuelve(){

    int l, n;
    std::cin >> l >> n;

    if (l==0 && n==0) return false;

    std::vector<int> marcas(n+2);
    marcas[0]=0;

    int c;

    for(int i = 1;i<=n;i++) {
        std::cin >> c;
        marcas[i]=c;
    }
    marcas[n+1]=l;

    Matriz<int> EM(n+2, n+2,0);

    //CASOS RECURSIVOS
    for(int i = n+1; i>=0; i--){
        for(int j=0; j<=n+1; j++){
            if (i<j && j!=i+1)
                for (int k = i+1; k < j; k++) {
                    int v=EM[i][k]+EM[k][j]+2*(marcas[j]-marcas[i]);
                    if (v<EM[i][j] || EM[i][j]==0) EM[i][j] = v;
                }
        }
    }

    int res= EM[0][n+1];

    std::cout << res << std::endl;

    return true;
}


int main() {

    while (resuelve()){}

    return 0;
}