#include <string>
#include <vector>
#include <cmath>
#include <iomanip>

#include "../Shooting.h"

//Burden, Numerical Analysis §11.1 Problema 7
using namespace std;

//Potencial inicial
float V0 = 110; 
float funct(float _r,float _U, float _Up){
    return ( (-2/_r)*_U );
}


int main(){

    //Rango de distancia radial
    float a = 2;
    float b = 4;
    
    //potencial en las fronteras
    float alpha = V0;
    float beta = 0;
    
    //parametros del metodo
    int N = 20, M = 10;
    float TOL = 1e-5; 
    
    Shooting(*(funct), a, b, alpha, beta, N, TOL, M);
    
    
}
