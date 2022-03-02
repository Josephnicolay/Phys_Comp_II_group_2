#include <iostream>
#include <vector>

using namespace std;

#ifndef SISTEMA_H
#define SISTEMA_H

class sistemaEcuaciones{

    public:
        sistemaEcuaciones(vector<vector<double> >, vector<double>);
        ~sistemaEcuaciones();
    
        vector<double> solJacobi(vector<double>, double, int);
        vector<double> solSOR(vector<double>, double, double, int);
    
        void imprimirCoef();
        void imprimirB();
    
    private:
        vector<vector<double> > coeffs;
        vector<double> B;
        
};

#endif