//3º DG. Manuel Sánchez Torrón. DG22
#include <iostream>
#include <vector>
#include "GrafoDirigidoValorado.h"
#include "IndexPQ.h"

/*void relax(AristaDirigida<int> & a, std::vector<int> & distTo,
           std::vector<AristaDirigida<int>> & edgeTo, IndexPQ<int> & pq){

    int v=a.from(), w=a.to();
    if (distTo[w]>distTo[v]+a.valor()){
        distTo[w]=distTo[v]+a.valor();
        edgeTo[w]=a;
        pq.update(w, distTo[w]);
    }
}*/

void Dijkstra(const GrafoDirigidoValorado<int> & g, int prim, std::vector<int> & distTo){

    std::vector<AristaDirigida<int>> edgeTo(g.V());
    distTo[prim]=0;
    IndexPQ<int> pq(g.V());

    pq.push(prim, 0);

    while (!pq.empty()){
        int v=pq.top().elem;
        pq.pop();
        for (AristaDirigida<int> a : g.adj(v)) {
            int w = a.to();
            if (distTo[w] > distTo[v] + a.valor()) {
                distTo[w] = distTo[v] + a.valor();
                edgeTo[w] = a;
                pq.update(w, distTo[w]);
            }
        }
    }
}



bool resuelve(){
    int n;
    int c;
    std::cin >> n >> c;

    if(!std::cin) return false;

    GrafoDirigidoValorado<int> grafo(n);
    int coste=0;

    int i1, i2, v;

    for (int j=0; j<c; j++){
        std::cin >> i1 >> i2 >> v;
        AristaDirigida<int> a(i1-1, i2-1, v);
        grafo.ponArista(a);
    }

    GrafoDirigidoValorado<int> grafoInverso = grafo.reverse();

    std::vector<int> distFromOficeTo(grafo.V(), 2147483647);
    std::vector<int> distTo(grafo.V(), 2147483647);

    int o,p,d;
    std::cin >> o >> p;

    Dijkstra (grafo, o-1, distFromOficeTo);
    Dijkstra (grafoInverso, o-1, distTo);

    bool imposible=false;
    for (int i=0; i<p; i++) {
        std::cin>>d;
        if (!imposible) {
            imposible = distFromOficeTo[d-1]==2147483647 || distTo[d-1]==2147483647;
            coste+=distFromOficeTo[d-1]+distTo[d-1];
        }

    }

    if (!imposible) std::cout<<coste<<std::endl;
    else std::cout << "Imposible\n";

    return true;

}

int main() {
    while(resuelve());

    return 0;
}