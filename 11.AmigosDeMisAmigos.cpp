//3º DG. Manuel Sánchez Torrón. DG22
#include <iostream>
#include <vector>
#include "Grafo.h"

//Se trata de dar el tamaño de la mayor componente conexa del grafo

void tamComponente(Grafo g, int v, std::vector<bool> & marcas, int & tam) { //Tamaño componente conexa vertice v

    if (!marcas[v]) tam++; //Si no hemos pasado, es un vertice más
    marcas[v] = true; //Marcamos el vertice

    for (int w: g.adj(v)) {
        if (!marcas[w]) {
            tamComponente(g, w, marcas, tam);
        }
    }
}

int mayorComponente(Grafo grafo){

    std::vector<bool> marcas (grafo.V(), false);
    int tam=0;

    tamComponente(grafo, 0, marcas, tam); //tam=tamaño de la componente del vertice 0
    int resultado = tam;

    for (int i=1; i< grafo.V(); i++){
        if (!marcas[i]) {
            tam=0;
            tamComponente(grafo, i, marcas, tam);
            resultado=std::max(resultado, tam);
        }
    }
    return resultado;
}

void resuelve(){

    int v, a, v1, v2;

    std::cin >> v; //Numero de vertices

    Grafo grafo(v);

    std::cin >> a; //Numero de aristas

    for (int i = 0; i < a; i++) {
        std::cin >> v1 >> v2;
        grafo.ponArista(v1-1, v2-1);
    }

    std::cout << mayorComponente(grafo) << "\n";

}



int main() {

    int nCasos;

    std::cin >> nCasos;

    for (int i=0; i < nCasos; i++)
        resuelve();

    return 0;
}