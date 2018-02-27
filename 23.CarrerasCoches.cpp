//3º DG. Manuel Sánchez Torrón. DG22
#include <iostream>
#include <vector>
#include <algorithm>

int voraz(std::vector<int> & datos, int v){

    int cont=0;
    int j=datos.size()-1;

    for (int i=0; i<j; i++){
        if(datos[i]+datos[j]>=v){
            cont++;
            j--;
        }
    }

    return cont;
}




bool resuelve(){

    int nDatos, dato, v;

    std::cin >> nDatos >> v;

    std::vector<int> datos;

    for (int i=0; i < nDatos; i++){
        std::cin >> dato;
        datos.push_back(dato);
    }


    std::sort(datos.begin(), datos.end());

    std::cout<<voraz(datos, v) << std::endl;


    return true;
}


int main() {

    int nDatos;

    std::cin >> nDatos;

   while (nDatos!=0){
       resuelve();
       nDatos--;
   }

    return 0;
}