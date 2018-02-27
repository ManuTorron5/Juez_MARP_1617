//3º DG. Manuel Sánchez Torrón. DG22
#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include "PriorityQueue.h"

using namespace std;

struct pelicula{
    int ini;
    int dur;
};

bool operator < (pelicula & p1, pelicula & p2){
    //if (p1.ini==p2.ini) return p1.dur<p2.dur;
    return p1.ini+p1.dur<p2.ini+p2.dur;
}


bool resuelve(){

    int n;

    cin >> n;

    if(n==0) return false;

    vector<pelicula> peliculas;
    peliculas.push_back({-1,-1});

    pelicula p;
    int h, m, d;

    for (int i=1; i<=n; i++){
        cin >> h;
        cin.ignore(1);
        cin >> m;
        cin >> d;
        p.ini=h*60+m;
        p.dur=d;
        peliculas.push_back(p);
    }

    sort (peliculas.begin(), peliculas.end());

    vector<int> final;
    vector<int> maxMinutos; //debería ser creciente
    maxMinutos.push_back(0);
    final.push_back(-10);

    for (int i=1; i<=n; i++){
        int ini=peliculas[i].ini;
        int dur=peliculas[i].dur;

        int prevMax=maxMinutos[i-1];
        maxMinutos.push_back(prevMax);
        final.push_back(final[i-1]);

        for (int j=i-1; j>=0; j--){
            if (ini>=final[j]+10){ //Buscamos el maraton más largo donde la podamos meter
                if (dur+maxMinutos[j]>prevMax){
                    maxMinutos[i]=dur+maxMinutos[j];
                    final[i]=ini+dur;
                    break;
                }
            }
        }
    }

    cout << maxMinutos[n] << endl;

    return true;
}


int main() {

    while (resuelve()){}

    return 0;
}