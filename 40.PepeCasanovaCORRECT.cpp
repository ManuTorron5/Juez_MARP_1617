//3º DG. Manuel Sánchez Torrón. DG22
#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include "PriorityQueue.h"

struct cancion {
    float p;
    float d;
};

bool operator < (const cancion & c1, const cancion & c2){
    return (c1.p/c1.d)>(c2.p/c2.d);
}

struct Nodo {
    int k;
    int beneficio;
    float beneficio_opt;
    std::vector<float> ocupada;
};

bool operator < (const Nodo & n1,const Nodo & n2){
    return n1.beneficio_opt > n2.beneficio_opt;
}

float calculo_optimista(int n, const std::vector<cancion> & C, int T, int k, int beneficio,
                      const std::vector<float> & ocupada){
    float hueco=T-(ocupada[0]+ocupada[1]);
    float opt=beneficio;
    int j=k+1;

    while (j<=n && C[j-1].d<=hueco){
        hueco-=C[j-1].d;
        opt+=C[j-1].p;
        j++;
    }
    if (j<=n){
        opt+=(hueco/C[j-1].d)* C[j-1].p;
    }

    return opt;

}

int calculo_pesimista (int n, const std::vector<cancion> & C, int T, int k, int beneficio,
                       const std::vector<float> & ocupada){
    std::vector<float> ocupada_aux=ocupada;
    int pes=beneficio;
    int j=k+1;

    while (j<=n && (ocupada_aux[0]<=T/2 || ocupada_aux[1]<=T/2)){
        if (ocupada_aux[0]+C[j-1].d<=T/2){
            ocupada_aux[0]+=C[j-1].d;
            pes+=C[j-1].p;
        }
        else if (ocupada_aux[1]+C[j-1].d<=T/2){
            ocupada_aux[1]+=C[j-1].d;
            pes+=C[j-1].p;
        }
        j++;
    }

    return pes;
}


void maximaPuntuacion(int n, int T, const std::vector<cancion> & C, int & beneficio_mejor){

    Nodo X,Y;
    PriorityQueue<Nodo> pq;
    Y.k=0;
    Y.ocupada=std::vector<float>(2,0);
    Y.beneficio=0;
    Y.beneficio_opt=calculo_optimista(n, C, T, Y.k, Y.beneficio, Y.ocupada);
    pq.push(Y);
    beneficio_mejor=calculo_pesimista(n, C, T, Y.k, Y.beneficio, Y.ocupada);
    while (!pq.empty() && pq.top().beneficio_opt>beneficio_mejor){
        pq.pop(Y);
        X.k=Y.k+1;
        X.ocupada={0.0,0.0};
        if (Y.ocupada[0]+C[X.k-1].d<=T/2){
            X.ocupada[0]=Y.ocupada[0]+C[X.k-1].d;
            X.ocupada[1]=Y.ocupada[1];
            X.beneficio=Y.beneficio+C[X.k-1].p;
            X.beneficio_opt=Y.beneficio_opt;
            if (X.k==n){
                beneficio_mejor=X.beneficio;
            }
            else {
                pq.push(X);
            }
        }

        if (Y.ocupada[0]!=Y.ocupada[1]){
            if (Y.ocupada[1]+C[X.k-1].d <= T/2){
                X.ocupada[0]=Y.ocupada[0];
                X.ocupada[1]=Y.ocupada[1]+C[X.k-1].d;
                X.beneficio=Y.beneficio+C[X.k-1].p;
                X.beneficio_opt=Y.beneficio_opt;
                if (X.k==n){
                    beneficio_mejor=X.beneficio;
                }
                else {
                    pq.push(X);
                    int pes=calculo_pesimista(n, C, T, X.k, X.beneficio, X.ocupada);
                    beneficio_mejor=std::max(beneficio_mejor, pes);
                }
            }
        }
        X.ocupada=Y.ocupada;
        X.beneficio=Y.beneficio;
        X.beneficio_opt=calculo_optimista(n, C, T, X.k, X.beneficio, X.ocupada);
        if (X.beneficio_opt>=beneficio_mejor) {
            if (X.k == n) {
                beneficio_mejor = X.beneficio;
            } else {
                pq.push(X);
                int pes = calculo_pesimista(n, C, T, X.k, X.beneficio, X.ocupada);
                beneficio_mejor = std::max(beneficio_mejor, pes);
            }
        }
    }
}


bool resuelve(){

    int n, T;

    std::cin >> n;

    if(n==0) return false;

    std::cin >> T;

    std::vector<cancion> canciones;

    cancion c;

    for (int i=0; i<n; i++) {
        std::cin >> c.d  >> c.p;
        canciones.push_back(c);
    }

    std::sort(canciones.begin(), canciones.end());

    int maxPunt;

    maximaPuntuacion(n, 2*T, canciones, maxPunt);

    std::cout << maxPunt << std::endl;

    return true;
}


int main() {

    while (resuelve()){}

    return 0;
}