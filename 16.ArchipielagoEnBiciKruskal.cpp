//3º DG. Manuel Sánchez Torrón. DG22
#include <iostream>
#include <vector>
#include "GrafoValorado.h"
#include "PriorityQueue.h"
#include "ConjuntosDisjuntos.h"

//Tenemos que encontrar un arbol de recubrimiento de coste minimo

void Kruskal(const GrafoValorado<int> & g, PriorityQueue<Arista<int>> & queue, PriorityQueue<Arista<int>> & mst, int & coste){

    Arista<int> a;
    ConjuntosDisjuntos cd(g.V());

    while (!queue.empty() && mst.size()<g.V()-1){
        a=queue.top();
        int v=a.uno(), w=a.otro(v);
        if (cd.buscar(v)!=cd.buscar(w)){ //No forman ciclo
            cd.unir(v,w);
            mst.push(a);
            coste+=a.valor();
        }

        queue.pop();
    }
}


bool resuelve(){
    int i, p;
    std::cin >> i >> p;

    if(!std::cin) return false;

    GrafoValorado<int> grafo(i);
    PriorityQueue<Arista<int>> queue;
    PriorityQueue<Arista<int>> mst;
    int coste=0;

    int i1, i2, v;

    for (int j=0; j<p; j++){
        std::cin >> i1 >> i2 >> v;
        Arista<int> a(i1-1, i2-1, v);
        grafo.ponArista(a);
        queue.push(a);
    }

    Kruskal(grafo, queue, mst, coste);

    if (mst.size() == grafo.V()-1) std::cout << coste << std::endl;
    else std::cout << "No hay puentes suficientes\n";

    return true;

}

int main() {

    while(resuelve());

    return 0;
}