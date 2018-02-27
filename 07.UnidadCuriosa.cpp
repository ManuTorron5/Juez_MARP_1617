//3º DG. Manuel Sánchez Torrón. DG22
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include "PriorityQueue.h"

struct usuario{
    int id;
    int periodo;
    int orden;
};

bool operator < (const usuario & u1, const usuario & u2){
    if (u1.orden==u2.orden) return u1.id<u2.id; //u1 tiene id menor
    else return u1.orden<u2.orden; //u1 va antes que u2
} //Operador PRIORIDAD=> p1<p2 indica que p1 tiene más prioridad que p2

void resuelve(int nUsuarios) {


    PriorityQueue<usuario> cola;
    usuario u;


    for (int i = 0; i < nUsuarios; i++) {
        std::cin >> u.id >> u.periodo;
        u.orden=u.periodo;
        cola.push(u);
    }

    int k;

    std::cin >> k;

    for (int i=0;i<k;i++){
        cola.pop(u);
        std::cout<<u.id<<"\n";
        u.orden+=u.periodo; //
        cola.push(u);

    }


    std::cout<<"----\n";
}



int main() {

    int nUsuarios;

    std::cin >> nUsuarios;

    while (nUsuarios!=0){
        resuelve (nUsuarios);
        std::cin >> nUsuarios;
    }

    return 0;
}
