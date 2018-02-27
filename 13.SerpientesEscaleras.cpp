//3º DG. Manuel Sánchez Torrón. DG22
#include <iostream>
#include <vector>
#include "GrafoDirigido.h"



int menorCamino(GrafoDirigido & grafo, int ini, int fin){ //Camino mas corto de ini a fin BFS
    std::queue<int> queue;
    std::vector<bool> marcas(grafo.V(), false);
    std::vector<int> distDeIniA(grafo.V()); //Vector de distancias


    queue.push(ini); //metemos ini en la fifo
    marcas[ini] = true; //marcamos ini

    while (!queue.empty() && !marcas[fin]){  //mientras no lleguemos a fin

        int v = queue.front();

        queue.pop();//sacamos el utltimo vertice visitado

        for (int w: grafo.adj(v)) {
            if (!marcas[w]) {
                marcas[w] = true;
                queue.push(w);
                distDeIniA[w]=distDeIniA[v]+1;

            }
        }
    }

    return distDeIniA[fin];
}

bool resuelve(){

    int n, k, s, e, c1, c2;

    std::cin >> n >> k >> s >> e;

    if (n==0) return false;

    GrafoDirigido grafo(n*n);
    std::vector<int> SoE(grafo.V(), -1); //Posiciones de escalreas y serpientes con sus llegadas

    for (int i=0; i<s+e; i++) {
        std::cin >> c1 >> c2;
        SoE[c1-1]=c2-1;
    }

    for (int i=0; i<grafo.V(); i++) { //A donde podemos llegar en cada casilla de origen
        if (SoE[i] == -1) { //SI no es inicio de serpiente o escalera
            for (int j = i + 1; j <= i + k && j < grafo.V(); j++) {
                if (SoE[j] == -1) grafo.ponArista(i, j); //No hay serpiente o escalera en j (con el dado solo)
                else grafo.ponArista(i, SoE[j]); //Hay serpiente o escalera en j
            }
        }
    }

    std::cout << menorCamino(grafo, 0, grafo.V()-1) << "\n";

    return true;
}





int main() {

   while(resuelve());

    return 0;
}