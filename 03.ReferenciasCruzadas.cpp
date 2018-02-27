//3º DG. Manuel Sánchez Torrón. DG22
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <sstream>
#include "TreeMap_RB.h"

void mostrar(TreeMap <std::string, std::vector<int>> & arbol);

void resolver(TreeMap <std::string, std::vector<int>> & arbol, int nLines){

    std::string linea;
    std::string palabra;

    int line=1;

    while (line<=nLines){
        std::getline(std::cin, linea);
        std::transform(linea.begin(), linea.end(), linea.begin(), ::tolower);
        std::istringstream iss(linea);
        iss>>palabra;
        while(iss) {
            if (palabra.size() > 2 && !arbol.contains(palabra)) { //Si es la 1a aparicion de la palabra
                std::vector<int> v = {line};
                arbol.insert(palabra, v);
            } else if (arbol.contains(palabra)) {
                std::vector<int> v = arbol.at(palabra); //Si ya ha aparecido
                if (line != v[v.size() - 1]) v.push_back(line); //Si no ha aparecido antes en la misma linea
                arbol.insert(palabra, v);
            }

            iss >> palabra;
        }

        line++;
    }


}

void mostrar(TreeMap <std::string, std::vector<int>> & arbol) {
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
}

void resuelveCaso(int numLines) {
    TreeMap <std::string, std::vector<int>> arbol;
    resolver(arbol, numLines);
    mostrar(arbol);
    std::cout << "----\n";
}


int main() {

 int numLines;
    std::cin >> numLines;
    while (numLines!=0){
        std::cin.ignore();
        resuelveCaso(numLines);
        std::cin >> numLines;
    }
    return 0;
}
