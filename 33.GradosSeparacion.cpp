//3º DG. Manuel Sánchez Torrón. DG22
#include <iostream>
#include "GrafoValoradoVector.h"
#include "TreeMap_AVL.h"

using namespace std;

bool resuelve(){

    int T, N;
    cin >> N >> T;
    if(!cin) return false;

    GrafoValoradoVector<int> g = GrafoValoradoVector<int>(N);
    TreeMap<string,int> list = TreeMap<string, int>();
    int cont = 0,res;
    for (int i = 0; i < T; i++) {
        string n1, n2;
        cin >> n1 >> n2;
        if (!list.contains(n1)) {
            list.insert(n1, cont);
            cont++;
        }
        if (!list.contains(n2)) {
            list.insert(n2, cont);
            cont++;
        }
        g.ponArista(Arista<int>(list.at(n1), list.at(n2), 1));
    }

    g.floydWarshall();
    res = g.maxDist();
    if (res == 2147483647) cout << "DESCONECTADA" <<endl;
    else cout << res << endl;

    return true;
}



int main() {

    while (resuelve()){}

    return 0;
}