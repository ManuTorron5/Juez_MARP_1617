//3º DG. Manuel Sánchez Torrón. DG22
#include <iostream>
#include <vector>
#include <algorithm>

struct restaurante {
    int ini;
    int fin;
};

bool operator < (restaurante & e1, restaurante & e2){
    return e1.ini<e2.ini;
}//Ordena los restaurantes segun el cominenzo de su influjo


int voraz(std::vector<restaurante> & datos, int l){

    if (datos.empty()) return -1;
    int cont=0;
    int cub=0;
    int cub_aux=cub;
    int i=0;

    while (cub<l && i<datos.size()){
        while (datos[i].ini<=cub && cub_aux<l && i<datos.size()){
            cub_aux=std::max(cub_aux, datos[i].fin);
            i++;
        }//Mientras solape con lo recubierto, cogemos el que acabe mas a la dcha

        cont++; //Colocamos el que solape con el fin mas a la dcha
        cub=cub_aux;
        if (i<datos.size()) {
            if (datos[i].ini > cub) return -1;
            if (datos[i].fin < cub) {
                i++; //Si esta dentro de cub, pasamos al siguiente. Si no lo tenemos en
                //cuenta para la siguiente colocacion
            }
        }
    }

    if (cub<l) return -1;
    return datos.size()-cont;
}




bool resuelve(){

    int l,n;
    restaurante dato;

    std::cin >> l >> n;

    if(!std::cin) return false;

    std::vector<restaurante> datos;

    int c, r;

    for (int i=0; i < n; i++){
        std::cin >> c >> r;
        dato.ini=std::max(0, c-r);
        dato.fin=std::min(l, c+r);
        datos.push_back(dato);

    }

    std::sort(datos.begin(), datos.end());

    std::cout<<voraz(datos, l) << std::endl;


    return true;
}


int main() {

    while (resuelve()){}

    return 0;
}