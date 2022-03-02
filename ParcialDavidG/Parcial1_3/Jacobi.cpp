#include <iostream>
#include <string>
#include <vector>
#include <numeric>
#include <cmath>
#include <iomanip>

#include "Jacobi.h"

using namespace std;

vector<double> Jacobi(vector<vector<double> > A, vector<double> b, vector<double> guess, double TOL, int N){

    //STEP 1.
    int k = 1;
    
    vector<double> x0 = guess;
    vector<double> xk;
    
    //STEP 2.
    while (k <= N){
    
        //STEP 3.
        for (int i=0; i<A.size(); i++){
            
            //***
            double comSum = 0.0;
            for (int j=0; j<A.size(); j++){
        
                -A[i][j] * x0[j];
            
            }
        
            double xi = 1 / A[i][i] * (comSum + A[i][i] * x0[i] + b[i]);
            xk.push_back(xi);
            
        }
        
        //STEP 4.
        if (absDiff(xk, x0)<TOL){
        
            return xk;
        
        }
        
        //STEP 5.
        k++;
        
        //STEP 6.
        x0 = xk;
        
    }
    
    //STEP 7
    return xk;
}

double absDiff(vector<double> _u, vector<double> _v){
    
    double value = 0;
    
    for (int i=0; i<_u.size(); i++){
    
        value += pow(_u[i] - _v[i], 2);
        
    }
    
    return sqrt(value);
    
}

