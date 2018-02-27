//3º DG. Manuel Sánchez Torrón. DG22
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include "TreeMap_RB.h"

//void mostrar(TreeMap <std::string, std::vector<int>> & arbol);

int resuelve(int nCapitulos){

    TreeMap <int, int> arbol; //clave=numero capitulo valor=dia ultima vez emitido

    int capitulo;
    int maxDias=0; //Maximo num de dias sin repetirse
    int dia=0;


    for (int i=1; i<=nCapitulos; i++){
        std::cin>>capitulo;

        if(arbol.contains(capitulo)) { //Si el capitulo es repetido
            if (arbol.at(capitulo)>dia) dia=arbol.at(capitulo);
            //dia es el ultimo dia que se repitio un capitulo
        }

        maxDias=std::max(maxDias, i-dia);
        arbol.insert(capitulo,i); //Solo nos interesa el ultimo dia de emision

    }

    return maxDias;
}

/*void mostrar(TreeMap <std::string, std::vector<int>> & arbol) {
    auto it=arbol.begin();
    auto end=arbol.end();

    while (it!=end){
        std::cout << it.clave() <<  " ";

        auto vit=it.valor().begin();
        auto vend=it.valor().end();

        while (vit!=vend) {
            std::cout << *vit << " ";
            vit++;
        }

        it++;

        std::cout << "\n";

    }
}*/





int main() {

 int nSeries, nCapitulos;
    std::cin >> nSeries;
        for (int i=0; i<nSeries;i++) {
            std::cin>>nCapitulos;
            std::cout << resuelve(nCapitulos);
            std::cout << "\n";
        }

    return 0;
}
