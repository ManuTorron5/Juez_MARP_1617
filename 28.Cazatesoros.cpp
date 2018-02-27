//Manuel Sánchez Torrón. DG22
#include <iostream>
#include <vector>
#include <algorithm>
#include "Matriz.h"
typedef struct{
    int oro;
    int profundidad;
} cofre;

bool resuelve(){

    int t,n;
    std::cin >> t >> n;

    if (!std::cin) return false;

    std::vector<cofre> cofres;

    cofre c={0, 0};
    cofres.push_back(c);
    for (int i=1; i<=n; i++){
        std::cin >> c.profundidad >> c.oro;
        cofres.push_back(c);
    }

    Matriz<int> maxOro(n+1,t+1,0);//maxOro[i][j] = maximo oro posible considerando los i primeros cofres y teniendo j segundos de oxígeno
   // Matriz<int> numCofres(n+1,t+1,0);

    //CASOS BASE
   /* int i=0, j=0;
    while(i <= n || j <= t){
        if(i <= n) {
            maxOro[i][0] = 0;
            numCofres[i][0]=0;
            i++;
        }
        if (j <= t){
            maxOro[0][j]=0;
            numCofres[0][j]=0;
            j++;
        }
    }*/

    //CASOS RECURSIVOS
    for(int i=1;i<=n;i++){
        for(int j=1; j<=t; j++){
           if (cofres[i].profundidad*3 > j){
               maxOro[i][j]=maxOro[i-1][j];
             //  numCofres[i][j]=numCofres[i-1][j];
           } else {
              maxOro[i][j]=std::max(maxOro[i-1][j],
                                    maxOro[i-1][j-cofres[i].profundidad*3]+cofres[i].oro);
           }
        }
    }

    std::vector<cofre> cogidos;
   // int k=numCofres[n][t];
    int j=t;
    for (int i=n; i>=1; i--){
            if (j>=0 && maxOro[i][j]!=maxOro[i-1][j]){//Hemos cogido el cofre i
                cogidos.push_back(cofres[i]);
                j-=cofres[i].profundidad*3;
            }
    }

    std::cout<<maxOro[n][t]<<std::endl<< cogidos.size()<<std::endl;

    auto it = cogidos.rbegin();
    auto end = cogidos.rend();

    while (it!=end){
        std::cout << it->profundidad << " " << it->oro << std::endl;
        it++;
    }

    std::cout<<"----\n";

    return true;
}
int main() {
    while(resuelve());
    return 0;
}