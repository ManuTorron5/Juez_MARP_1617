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

int Dijkstra(const GrafoDirigidoValorado<int> & g, int prim){

    std::vector<AristaDirigida<int>> edgeTo(g.V());
    std::vector<int> distTo(g.V(), 2147483647);
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

    return distTo[g.V()-1];
}



bool resuelve(){
    int n;
    std::cin >> n;

    if(n==0) return false;

    GrafoDirigidoValorado<int> grafo(n);
    int coste=0;
    std::vector<int> costePag(grafo.V());

    int v;

    for(int i=0; i<grafo.V(); i++){
        std::cin >> v;
        costePag[i]=v;
    }

    int m;
    std::cin >> m;
    int i1, i2;

    for (int j=0; j<m; j++){
        std::cin >> i1 >> i2 >> v;
        AristaDirigida<int> a(i1-1, i2-1, v+costePag[i2-1]);
        //La arista tendrá como coste el coste de ir de una pagina a otra mas el coste de cargar la 2a
        grafo.ponArista(a);
    }

    coste=Dijkstra(grafo,0);

    if (coste<2147483647) std::cout<<coste+costePag[0]<<std::endl;
    else std::cout << "IMPOSIBLE\n";

    return true;

}

int main() {

    while(resuelve());

    return 0;
}