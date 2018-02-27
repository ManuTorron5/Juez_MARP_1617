//3º DG. Manuel Sánchez Torrón. DG22
#include <iostream>
#include <vector>
#include <queue>
#include "GrafoDirigido.h"

int shortestPath(const GrafoDirigido & graph, int start, int end) {
    std::queue<int> queue;
    std::vector<bool> marked(graph.V());
    std::vector<int> pathSize(graph.V());

    marked[start] = true;
    queue.push(start);

    while (!queue.empty() && !marked[end]) {
        int v = queue.front();
        queue.pop();
        for (int w: graph.adj(v)) {
            if (!marked[w]) {
                pathSize[w] = pathSize[v] + 1;
                marked[w] = true;
                queue.push(w);
            }
        }
    }

    return pathSize[end];
}




bool resuelveCaso(GrafoDirigido & grafo) {
    int ini, fin;
    std::cin >> ini >> fin;

    if (!std::cin) return false;

    std:: cout << shortestPath(grafo, ini, fin) << std::endl;

    return true;
}

int main() {

    GrafoDirigido grafo(10000);
    for (size_t i = 0; i < 10000; i++) {
        grafo.ponArista(i, (i + 1) % 10000);
        grafo.ponArista(i, (i * 2) % 10000);
        grafo.ponArista(i, i / 3);
    }

    while (resuelveCaso(grafo));

    return 0;
}