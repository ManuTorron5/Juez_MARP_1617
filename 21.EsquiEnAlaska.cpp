//3º DG. Manuel Sánchez Torrón. DG22
#include <iostream>
#include <vector>
#include <algorithm>

int voraz(std::vector<int> & esquis, std::vector<int> & esquiadores) {
    int dif = 0;

    for (int i=0; i< esquis.size(); i++) {
       dif+=std::abs(esquis[i] - esquiadores[i]);
    }

    return dif;
}


bool resuelveCaso() {

    int n, aux;
    std::vector<int> esquis, esquiadores;
    std::cin >> n;

    if (n==0) return false;

    for (int i = 0; i < n; i++) {
        std::cin >> aux;
        esquis.push_back(aux);
    }

    for (int i = 0; i < n; i++) {
        std::cin >> aux;
        esquiadores.push_back(aux);
    }

    std::sort(esquis.begin(), esquis.end());
    std::sort(esquiadores.begin(), esquiadores.end());

    std:: cout << voraz (esquis, esquiadores) << std::endl;

    return true;
}

int main() {

    while (resuelveCaso());

    return 0;
}