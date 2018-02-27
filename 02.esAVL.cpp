//3º DG. Manuel Sánchez Torrón
#include <iostream>
#include <fstream>
#include <algorithm>
#include "BinTree.h"

BinTree<int> leerArbol() {
    int raiz;
    std::cin >> raiz;
    if (raiz == -1) { // es un árbol vacío
        return {};
    }
    else { // leer recursivamente los hijos
        auto iz = leerArbol();
        auto dr = leerArbol();
        return {iz, raiz, dr};
    }
}



void esAVL(BinTree<int> const & arbin, int & min, int & max, int & altura, bool & AVL){
    if (arbin.empty()){
        min=2147483647; //valor de INT_MAX
        max=-1;
        altura=0;
        AVL=true;
    }

    else {
        int mini, maxi, hi, mind, maxd, hd;
        bool avli, avld;
        esAVL(arbin.left(), mini, maxi, hi, avli);
        esAVL(arbin.right(), mind, maxd, hd, avld);
        min=std::min(std::min(mini, mind), arbin.root());
        max=std::max(std::max(maxi, maxd), arbin.root());
        altura=1+std::max(hi,hd);
        AVL= avli && avld && maxi<arbin.root() && arbin.root()<mind
                && hi-hd<=1 && hd-hi<=1;
    }
}


void resuelveCaso() {

    auto arbin = leerArbol();
    int min, max, altura;
    bool AVL;

    esAVL(arbin, min, max, altura, AVL);

    if(AVL) std::cout << "SI";
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
#endif
*/
    return 0;
}
