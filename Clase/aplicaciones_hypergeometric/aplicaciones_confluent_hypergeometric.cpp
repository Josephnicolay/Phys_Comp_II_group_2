#include <string>
#include <vector>
#include <cmath>
#include <iomanip>

#include "../Shooting.h"

//Problemas con simetria Axial para modelos tipo Hidrógeno
using namespace std;

//Numeros cuánticos
float n = 1, m = 1;

//Ecuacion de Kummer ODE (Hipergeométrica Confluente)
float funct(float _r,float _F, float _Fp){
    return ( -((m + 1.0)/_r)*_Fp - (n/_r)*_F );
}


int main(){
    // distancia radial
    float a = 1;
    float b = 3;
    //Valores en la frontera
    float alpha = 1;
    float beta = 4;
    
    //parametros del metodo
    int N = 20, M = 10;
    float TOL = 1e-5; 
    
    Shooting(*(funct), a, b, alpha, beta, N, TOL, M);  
    
}
