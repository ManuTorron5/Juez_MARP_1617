//3º DG. Manuel Sánchez Torrón. DG22
#include <iostream>
#include <vector>
#include <algorithm>

int voraz(std::vector<int> & libros){

    int cont=0;

    for (int i=2; i<libros.size(); i+=3){
        cont+=libros[i];
    }

    return cont;
}




bool resuelve(){

    int nLibros, libro;

    std::cin >> nLibros;

    if (!std::cin) return false;

    std::vector<int> libros;

    for (int i=0; i < nLibros; i++){
        std::cin >> libro;
        libros.push_back(libro);
    }

    std::sort(libros.begin(), libros.end(), std::greater<int>());

    std::cout<<voraz(libros) << std::endl;

    return true;
}


int main() {

   while (resuelve());

    return 0;
}