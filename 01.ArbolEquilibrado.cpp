//3º DG. Manuel Sánchez Torrón
#include <iostream>
#include <fstream>
#include <algorithm>
#include "BinTree.h"

BinTree<char> leerArbol();
int altura(BinTree<char> const& arbol);
bool esEquilibrado(BinTree<char> const & arbin);
void resuelveCaso();


BinTree<char> leerArbol() {
    char raiz;
    std::cin >> raiz;
    if (raiz == '.') { // es un árbol vacío
        return {};
    }
    else { // leer recursivamente los hijos
        auto iz = leerArbol();
        auto dr = leerArbol();
        return {iz, raiz, dr};
    }
}

int altura(BinTree<char> const& arbol){
    if (arbol.empty())
        return 0;

    else
        return 1 + std::max(altura(arbol.left()), altura(arbol.right()));
}

bool esEquilibrado(BinTree<char> const & arbin) {

    if (arbin.empty()) return true;

    return (altura(arbin.left()) - altura(arbin.right()) <=1) &&
           (altura(arbin.right()) - altura(arbin.left()) <=1) &&
           esEquilibrado(arbin.right()) && esEquilibrado(arbin.left());

}


void resuelveCaso() {

    auto arbin = leerArbol();

    bool sol = esEquilibrado(arbin);

    if(sol) std::cout << "SI";
    else std::cout << "NO";
    std::cout << "\n";


}


int main() {

/*#ifndef DOMJUDGE
   std::ifstream in("casos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif
*/
    int numCasos;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();

    // para dejar todo como estaba al principio
/*#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif*/

    return 0;
}
