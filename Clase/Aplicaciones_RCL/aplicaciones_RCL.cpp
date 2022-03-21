#include <string>
#include <vector>
#include <cmath>
#include <iomanip>

#include "../Shooting.h"


using namespace std;

float R=4,L=1,C=1.0/3.0;

//Ecuacion diferencial para el circuito RCL
float funct(float _t,float _I, float _Ip){
    return ( (-R/L)*_Ip + (-1.0/(C*L))*_I );
    }

int main(){
    
    //Puntos de frontera
    float a = 0;
    float b = 20;
    
    //Valor de la corriente en la frontera
    float alpha = 0;
    float beta = 4;
    
    //Parametros del método
    int N = 20, M = 10;
    float TOL = 1e-5; 
    
    Shooting(*(funct), a, b, alpha, beta, N, TOL, M);
    
    
}
