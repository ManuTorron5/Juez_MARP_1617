//3º DG. Manuel Sánchez Torrón. DG22
#include <iostream>
#include <vector>
#include "Grafo.h"


bool componenteBipartita(Grafo g, int v, std::vector<bool> & marcas, std::vector<bool> & colores, bool color){ //Basado en DFS

    marcas[v]=true; //Marcamos el vertice v
    colores[v]=color; //Pintamos el vertice de color color

    for (int w: g.adj(v)) {
        if (!marcas[w]) {
            return componenteBipartita(g, w, marcas, colores,
                                       !color); //Marcaremos los vertices adyacentes del color !color
        } else if (colores[v] == colores[w]) return false; //2 vertices adyacentes tienen el mismo color
    }

    return true; //Hemos recorrido la lista de adyacencia de v sin problemas

}

bool esBipartito(Grafo grafo){

    std::vector<bool> marcas (grafo.V(), false);
    std::vector<bool> colores (grafo.V(), -1);  //Color 0 y color 1

    bool resultado=true;

    for (int i=0; i<grafo.V() && resultado; i++)
        if(!marcas[i]) resultado=resultado && componenteBipartita(grafo, i, marcas, colores, 0);
        //Comprobamos todas las componentes conexas del grafo
    return resultado;

}

bool resuelve(){

    int v, a, v1, v2;

    std::cin >> v; //Numero de vertices

    if(!std::cin) return false;

    Grafo grafo(v);

    std::cin >> a; //Numero de aristas

    for (int i = 0; i < a; i++) {
        std::cin >> v1 >> v2;
        grafo.ponArista(v1, v2);
    }

    std::cout << (esBipartito(grafo) ? "SI\n" : "NO\n");

    return true;
}



int main() {

    while(resuelve());

    return 0;
}
