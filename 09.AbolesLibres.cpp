//3º DG. Manuel Sánchez Torrón. DG22
#include <iostream>
#include <vector>
#include "Grafo.h"


bool componenteAciclica(const Grafo & g, int v, std::vector<bool> & marcas, std::vector<int> & anterior){ //Devuelve true si el vertice v no forma parte de un ciclo. Comprueba reursivamente los vertices adyacentes a v

    marcas[v]=true; //Marcamos el vertice v

    for (int w: g.adj(v)) { //Comprobamos que ningun vertice de la lista de adyacencia de v esta conectado a un vertice w ya visitado anteriormente (salvo v (el anterior))
        if (!marcas[w]) { //Si no hemos pasado por w comprobamos la lista de adyacencia de w, marcando que hemos llegado a w a traves de v
            anterior[w] = v;
            if (!componenteAciclica(g, w, marcas, anterior))
                return false;
        }

        else if (anterior[v]!=w) return false; //Si ya habiamos pasado por w y no hemos llegado a v a traves de él => hemos encontrado un ciclo
    }

    return true;

}

bool esLibre(const Grafo & grafo){

    std::vector<bool> marcas (grafo.V(), false);
    std::vector<int> anterior (grafo.V(), -1); //anterior[w]=v significa que hemos llegado a w a traves de v


    //Primero veremos si la componente del vertice 0 es aciclica, marcamos los vertices por donde pasamos
    //Y luego comprobamos que hemos pasado por todos (conexo)
    bool aciclico=componenteAciclica(grafo, 0, marcas, anterior);
    bool conexo=true;

    for (int i=0; (i<grafo.V())&&conexo; i++)
        conexo=marcas[i];// Si hemos pasado por todos los vertices, el grafo es conexo

    return conexo && aciclico;

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

    std::cout << (esLibre(grafo) ? "SI\n" : "NO\n");

    return true;
}



int main() {

    while(resuelve());

    return 0;
}
