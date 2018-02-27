//3º DG. Manuel Sánchez Torrón. DG22
#include <iostream>
#include <vector>
#include "ConjuntosDisjuntosMax.h"

/*void tamComponente(const Grafo & g, int v, std::vector<bool> & marcas, int & tam) { //Tamaño componente conexa vertice v

    if (!marcas[v]) tam++; //Si no hemos pasado, es un vertice más
    marcas[v] = true; //Marcamos el vertice

    for (int w: g.adj(v)) {
        if (!marcas[w]) {
            tamComponente(g, w, marcas, tam);
        }
    }
}

int mayorComponente(const Grafo & grafo){

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
}*/


void conectar(ConjuntosDisjuntosMax & cd, int f, int c, std::vector<bool> & petroleo, int i, int j) {
    int pos=i*c+j;
    petroleo[pos] = true;
    for (int p = std::max(0, i - 1); p < std::min(i + 2, f); p++) {
        for (int q = std::max(0, j - 1); q < std::min(j + 2, c); q++) {
            if (petroleo[p * c + q])
                cd.unir(pos, p*c+q);
        }
    }
} //Pone ptroleo en i,j y lo conecta con sus casillas adyacentes si hay petroleo

bool resuelve(){

    int f, c,n;
    char par; //Parcela
    bool vacio=true;

    std::cin >> f >> c;

    if (!std::cin) return false;

    ConjuntosDisjuntosMax cd(f*c);
    std::vector<bool> petroleo(f*c, false);

    std::cin.ignore();

    for (int i=0; i<f; i++){
        for (int j=0; j<c; j++){//REcorremos de arriba a abajo y de izquierda a derecha
            std::cin.get(par);
            if (par=='#') { //Si hay olivos los conectamos
                vacio = false;
                conectar(cd, f, c, petroleo, i, j);
            }
        }

        std::cin.ignore(); //Ignoramos salto de linea
    }

    if(vacio)  std::cout<< "0";
    else std::cout << cd.maximo();

    std::cin >> n;

    int i,j;

    for (int k = 0 ; k<n ; k++){
        std::cin >> i >> j;
        i--; j--;
        conectar(cd, f, c, petroleo, i, j);
        std::cout << " " << cd.maximo();
    }

    std::cout << std::endl;

    return true;
}


int main() {

    while (resuelve());

    return 0;
}