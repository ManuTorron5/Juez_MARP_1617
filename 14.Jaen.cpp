//3º DG. Manuel Sánchez Torrón. DG22
#include <iostream>
#include <vector>
#include "Grafo.h"

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
    int resultado=-1;

    for (int i=0; i< grafo.V(); i++){
        if (!marcas[i]) {
            tam=0;
            tamComponente(grafo, i, marcas, tam);
            resultado=std::max(resultado, tam);
        }
    }
    return resultado;
}



bool resuelve(){

    int f, c;
    char par; //Parcela
    bool vacio=true;

    std::cin >> f >> c;

    if (!std::cin) return false;

    Grafo grafo(f*c);
    std::vector<bool> olivos(grafo.V(), false);

    std::cin.ignore();

    for (int i=0; i<f; i++){
        for (int j=0; j<c; j++){//REcorremos de arriba a abajo y de izquierda a derecha
            std::cin.get(par);
            if (par=='#'){ //Si hay olivos los conectamos
                olivos[i*f+j]=true; //Marcamos que en la parcela (i,j) = i*f+j hay olivos
                vacio=false;
                if(i>0 && olivos[(i-1)*f+j]) //Si hay olivos arriba
                    grafo.ponArista(i*f+j, (i-1)*f+j);
                if (j>0 && olivos[i*f+j-1])//Si hay olivos a la izquierda
                    grafo.ponArista(i*f+j, i*f+j-1);
            }
        }
        std::cin.ignore(); //Ignoramos salto de linea
    }

    if(vacio)  std::cout<< "0" << "\n";
    else std::cout<<mayorComponente(grafo) << "\n";

    return true;
}





int main() {

   while(resuelve());

    return 0;
}