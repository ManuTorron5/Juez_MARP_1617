//3º DG. Manuel Sánchez Torrón. DG22
#include <iostream>
#include <vector>
#include <algorithm>


struct edificio {
    int w;
    int e;
};

bool operator < (edificio & e1, edificio & e2){
    return e1.e<e2.e;
}

int voraz(std::vector<edificio> & datos){

    int cont=0; int cubierto=-1;

    for(edificio ed : datos){
        if(ed.w>=cubierto){ //Si está mas a la dcha de lo que cubierto
            cubierto=ed.e;
            cont++;
        }
    }

    return cont;
}

bool resuelve(){

    int nDatos;
    edificio dato;

    std::cin >> nDatos;

    if(nDatos==0) return false;

    std::vector<edificio> datos;

    for (int i=0; i < nDatos; i++){
        std::cin >> dato.w >> dato.e;
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