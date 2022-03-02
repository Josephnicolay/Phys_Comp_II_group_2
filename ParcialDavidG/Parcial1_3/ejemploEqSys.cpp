#include <iostream>
#include <vector>
#include <iomanip>

#include "sistemaEcuaciones.h"
#include "Jacobi.h"
#include "SOR.h"


int main(){

    vector<vector<double> > systCoe =
    {
        {10, -1, 2, 0},
        {-1, -11, -1, 3},
        {2, -1, 10, -1},
        {0, 3, -1, 8}
    };
    
    vector<double> systB ={6, 25, -11, 6};
    
    sistemaEcuaciones system(systCoe, systB);
    //system.imprimirCoef();
    //system.imprimirB();
    
    double tol = 0.005;
    int N = 20;
    double w = 1.5;
    vector<double> guess ={0.0, 0.0, 0.0, 0.0};
    
    
    vector<double> solJ = system.solJacobi(guess, tol, N);
    vector<double> solS = system.solSOR(guess, tol, w, N);
    
    cout<<"Solucion..."<<endl;
    cout<<setw(10)<<"Jacobi"<<setw(10)<<"SOR"<<endl;
    
    for (int i=0; i<4;i++){
        cout<<setw(10)<<solJ[i]<<setw(10)<<solS[i]<<endl;
    }
    
}