//3º DG. Manuel Sánchez Torrón. DG22
#include <iostream>
#include <vector>
#include <algorithm>
#include "Matriz.h"
#include "PriorityQueue.h"


struct Nodo {
    int k;
    int tiempo;
    int tiempo_opt;
    std::vector<bool> asignado;
};

bool operator < (const Nodo & n1,const Nodo & n2){
    return n1.tiempo_opt<n2.tiempo_opt;
}

void tiempoMinimo(int n, const Matriz<int> & T, std::vector<int> & opt, std::vector<int> & pes, int & mejorTiempo){

    Nodo X,Y;
    PriorityQueue<Nodo> pq;
    Y.k=0;
    Y.asignado=std::vector<bool>(n,false);
    Y.tiempo=0;
    Y.tiempo_opt=opt[0];
    pq.push(Y);
    mejorTiempo=pes[0];
    while (!pq.empty() && pq.top().tiempo_opt<=mejorTiempo){
        pq.pop(Y);
        X.k=Y.k+1;
        X.asignado=Y.asignado;

        for (int t=1; t<=n; t++){
            if(!X.asignado[t-1]){
                X.asignado[t-1]=true;
                X.tiempo=Y.tiempo+T[X.k-1][t-1];
                X.tiempo_opt=X.tiempo+opt[X.k];
                if (X.tiempo_opt<=mejorTiempo){
                    if (X.k==n){
                        mejorTiempo=X.tiempo;
                    }
                    else {
                        pq.push(X);
                        mejorTiempo=std::min(mejorTiempo, X.tiempo+pes[X.k]);
                    }
                }
                X.asignado[t-1]=false;
            }
        }
    }
}


bool resuelve(){

    int n;

    std::cin >> n;

    if(n==0) return false;

    Matriz<int> T(n,n);
    std::vector<int> rapido(n);
    std::vector<int> opt(n+1);
    std::vector<int> lento(n);
    std::vector<int> pes(n+1);

    int t, r, l;

    for (int i=0; i<n; i++) {
        r=10001;
        l=0;
        for (int j = 0; j < n; j++) {
            std::cin >> t;
            T[i][j] = t;
            r=std::min(r, t);
            l=std::max(l, t);
        }
        rapido[i]=r;
        lento[i]=l;
    }

    opt[n]=0;
    pes[n]=0;

    for (int i=n-1; i>=0; i--){
        opt[i]=opt[i+1]+rapido[i];
        pes[i]=pes[i+1]+lento[i];
    }

    int mejorTiempo;

    tiempoMinimo(n, T, opt, pes, mejorTiempo);

    std::cout << mejorTiempo << std::endl;

    return true;
}


int main() {

    while (resuelve()){}

    return 0;
}