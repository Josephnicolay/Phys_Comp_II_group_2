#include <iostream>
#include <vector>
#include <iomanip>

#include "sistemaEcuaciones.h"
#include "Jacobi.h"
#include "SOR.h"

using namespace std;

sistemaEcuaciones::sistemaEcuaciones(vector<vector<double> > _coeffs, vector<double> _B){

    coeffs = _coeffs;
    B = _B;
    
}

sistemaEcuaciones::~sistemaEcuaciones(){
}

vector<double> sistemaEcuaciones::solJacobi(vector<double> guess, double TOL, int N){

    return Jacobi(coeffs, B, guess, TOL, N);

}

vector<double> sistemaEcuaciones::solSOR(vector<double> guess, double TOL, double w, int N){

    return SOR(coeffs, B, guess, TOL, w, N);

}

void sistemaEcuaciones::imprimirCoef(){
    
    int numFilas= coeffs.size();
    int numCols=coeffs[0].size();

    for (int i=0; i<numCols; i++){
        for (int j=0; j<numCols; j++){
        
            cout<<setw(4)<<coeffs[i][j]<<"\t";
            
        }
        cout<<"\n";
    }
}

void sistemaEcuaciones::imprimirB(){

    for (int i=0; i<B.size(); i++){
    
        cout<<setw(4)<<B[i]<<endl;
        
    }
    
}


