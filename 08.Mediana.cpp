//3º DG. Manuel Sánchez Torrón. DG22
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include "PriorityQueue.h"


//Usaremos dos colas, de forma que los elementos top de cada una sean los valores centrales de la
//sucesion de valores.
//La funcion dobleMediana devuelve el doble de la mediana teniendo en cuenta que en
//menores se guardan la mitad de los numeros mas pequeños y en mayores la mitad de los más grandes


/*int dobleMediana (PriorityQueue<int> mayores, PriorityQueue<int, std::greater<int>> menores){
    if(mayores.size()==menores.size()) return mayores.top()+menores.top();
    else return 2*menores.top(); //Siempre mas elementos en menores que en mayores (o mismos)
}*/


void resuelve(int n) {

    PriorityQueue<int> mayores;
    PriorityQueue<int, std::greater<int>> menores;
    int num;
    int elem;

    for (int i = 0; i < n; i++) {
        std::cin >> num;
        if (menores.empty()) menores.push(num); //Primer número
        else if (num<menores.top()) menores.push(num);
        else mayores.push(num);

        if (menores.size()>mayores.size()+1){ //Compensamos si el tamaño es muy desigual
            menores.pop(elem);
            mayores.push(elem);
        }

        else if (mayores.size()>menores.size()){
            mayores.pop(elem);
            menores.push(elem);
        }

        if (menores.size()==mayores.size()) std::cout<<menores.top()+mayores.top()<< " ";
        else std::cout << 2*menores.top() << " ";
        /*std::cout<<dobleMediana(mayores, menores) << " ";*/


    }

    std::cout<<"\n";
}



int main() {

    int n;

    std::cin >> n;

    while (n!=0){
        resuelve (n);
        std::cin >> n;
    }

    return 0;
}
