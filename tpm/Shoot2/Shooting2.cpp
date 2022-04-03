#include "Shooting2.h"

using namespace std;

vector<double> Schroedinger(vector<double> y, double V, double E){

    double psi = y[0];
    double phi = y[1];
    
    vector<double> dphidx = { phi , (V - E ) * psi };
    
    return dphidx;
    
}

vector<double> RK4(double (*funct)(double, double, double, double), double psi0, vector<double> x, vector<double> V, double E){

    int n = x.size();
    vector<double> psi(n, psi0);
    
    for(int i=0; i<n; i++){
    
        double h = x [i + 1] - x[i];
        double k1 = h*funct ( psi [ i], x[i] , V [i], E);
        double k2 = h*funct ( psi [ i] + 0.5* k1 , x [i] + 0.5* h , V[ i], E);
        double k3 = h*funct ( psi [ i] + 0.5* k2 , x [i] + 0.5* h , V[ i], E);
        double k4 = h*funct ( psi [ i] + k3 , x[i +1] , V[i], E);
        double psi [i +1] = psi [i] + ( k1 + 2.0*( k2 + k3 ) + k4 ) / 6.0;
        
    }
    
    return psi;

}

vector<double> Shoot(double (*funct)(double, double, double, double), vector<double> psi0, vector<double> x, vector<double> V, vector<double> E_arr){

    vector<double> psi_rightb;
    for (double EN : E_arr) {
        
        psi = RK4 ( func , psi0 , x , V , EN );
        psi_rightb.push_back ( psi [ len ( psi ) -1][0]);
            
    }
    
    return psi_rightb;

}






















