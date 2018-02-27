//3º DG. Manuel Sánchez Torrón. DG22
#include <iostream>
#include <vector>
#include "Matriz.h"


bool resuelve(){

    std::string s;
    std::getline(std::cin, s);

    if(!std::cin) return false;

    int n=s.length();

    Matriz<bool> A(n,n,false);
    Matriz<bool> B(n,n,false);
    Matriz<bool> C(n,n,false);

    for (int i=0;i<=n-1;i++){
        if (s[i]=='a'){
            A[i][i]=true;
        }
        else if (s[i]=='b'){
            B[i][i]=true;
        }

        else if (s[i]=='c'){
            C[i][i]=true;
        }
    }

    for(int d=0;d<=n-1;d++){
        for(int i = 0;i<n-1-d;i++){
            int j = i+d+1;
            A[i][j] = B[i][j] = C[i][j] =0;
            for(int k = i;k<j;k++){
                A[i][j] = A[i][j] || A[i][k] && C[k+1][j] || B[i][k]&&C[k+1][j] || C[i][k]&&A[k+1][j];
                B[i][j] = B[i][j] || A[i][k] && A[k+1][j] || A[i][k]&&B[k+1][j] || B[i][k]&&B[k+1][j];
                C[i][j] = C[i][j] || B[i][k] && A[k+1][j] || C[i][k]&&B[k+1][j] || C[i][k]&&C[k+1][j];
            }
        }
    }

    if (n>0){
        bool b=A[0][n-1];
        std::cout << (b ? "SI" : "NO") << std::endl;
    }
    else std::cout << "NO";


    return true;
}


int main() {

    while (resuelve()){}

    return 0;
}