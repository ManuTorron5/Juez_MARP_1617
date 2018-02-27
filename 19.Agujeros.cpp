//3º DG. Manuel Sánchez Torrón. DG22
#include <iostream>
#include <vector>

int voraz(std::vector<int> & agujeros, int l) {

    int cuenta = 0;
    int cubierto = -1;

    for (int aguj: agujeros) {
        if (aguj > cubierto) {
            cuenta++;
            cubierto = aguj + l;
        }
    }

    return cuenta;
}


bool resuelveCaso() {
    int n, l, auxAguj;
    std::vector<int> agujeros;
    std::cin >> n >> l;

    if (!std::cin) return false;

    for (int i = 0; i < n; i++) {
        std::cin >> auxAguj;
        agujeros.push_back(auxAguj);
    }

    std:: cout << voraz (agujeros, l) << std::endl;

    return true;
}

int main() {

    while (resuelveCaso());

    return 0;
}