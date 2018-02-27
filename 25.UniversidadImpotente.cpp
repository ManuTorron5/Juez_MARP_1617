//3º DG. Manuel Sánchez Torrón. DG22
#include <iostream>
#include <vector>
#include <algorithm>
#include "PriorityQueue.h"

struct conferencia {
    int ini;
    int fin;
};

bool operator < (conferencia & e1, conferencia & e2){
    return e1.ini<e2.ini;
}

int voraz(std::vector<conferencia> & datos){

    int cont=0;
    PriorityQueue<int> fines;
    fines.push(1000000001);

    for(conferencia c : datos){
        if (c.ini<fines.top()){ //necesitamos un aula mas
            cont++;
        }
        else fines.pop();
        fines.push(c.fin);
    }

    return cont;
}




bool resuelve(){

    int nDatos;
    conferencia dato;

    std::cin >> nDatos;

    if(nDatos==0) return false;

    std::vector<conferencia> datos;


    for (int i=0; i < nDatos; i++){
        std::cin >> dato.ini >> dato.fin;
        datos.push_back(dato);

    }

    std::sort(datos.begin(), datos.end());

    std::cout<<voraz(datos) << std::endl;


    return true;
}


int main() {

   while (resuelve()){}

    return 0;
}