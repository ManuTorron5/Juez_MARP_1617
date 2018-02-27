//3º DG. Manuel Sánchez Torrón. DG22
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include "PriorityQueue.h"

struct paciente{
    std::string nombre;
    int gravedad;
    int llegada;
};

bool operator < (const paciente & p1, const paciente & p2){
    if (p1.gravedad==p2.gravedad) return p1.llegada<p2.llegada; //p1 llego antes
    else return p1.gravedad>p2.gravedad; //p1 esta mas grave
} //Operador PRIORIDAD=> p1<p2 indica que p1 tiene más prioridad que p2

long long int resuelve(int nEventos) {


    PriorityQueue<paciente> cola;
    paciente p;
    char evType;

    for (int i = 0; i < nEventos; i++) {
        std::cin >> evType;
        if (evType == 'I') {
            std::cin >> p.nombre >> p.gravedad;
            p.llegada = i + 1;
            cola.push(p);
        } else if (evType == 'A') {
            cola.pop(p);
            std::cout << p.nombre << "\n";
        }
    }

    std::cout<<"----\n";
}



int main() {

    int nEventos;

    std::cin >> nEventos;

    while (nEventos!=0){
        resuelve (nEventos);
        std::cin >> nEventos;
    }

    return 0;
}
