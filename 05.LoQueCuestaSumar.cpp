//3º DG. Manuel Sánchez Torrón. DG22
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include "PriorityQueue.h"

//Hay que ir sumando de 2 en 2 cogiendo siempre los 2 más pequeños,
// y metiendo el resultado de nuevo en la cola
//En cada suma sumamos a coste el coste de esa suma

long long int resuelve(PriorityQueue<long long int> & cola){

    long long int sumando1, sumando2, coste;
    coste=0;

    while(cola.size()>1){
        cola.pop(sumando1);
        cola.pop(sumando2);
        cola.push(sumando1+sumando2);
        coste+=sumando1+sumando2;
    }

    return coste;
}



int main() {

    int nSumandos;
    long long int numero;

    std::cin >> nSumandos;
    while (nSumandos!=0){

        PriorityQueue<long long int> cola;

        for (int i=0; i<nSumandos; i++){
            std::cin >> numero;
            cola.push(numero);
        }
        std::cout << resuelve (cola) << "\n";
        std::cin >> nSumandos;
    }

    return 0;
}
