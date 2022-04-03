#include <string>
#include <vector>
#include <cmath>
#include <iomanip>

#include "ModShooting.h"


using namespace std;


float funct(float _x,float _y, float _yp){
    return -sin(_y);
}

/*
float dfunct(float _x,float _y, float _yp){
    return -_yp / 8;
}

float dpfunct(float _x,float _y, float _yp){
    return -_y / 8;
}
*/

int main(){
    
    float a = 0.0;
    float b = 10.0;
    float alpha = 0.0;
    float beta = 0.0;
    int N = 30, M = 10;
    float TOL = 1e-5;
    //float T0 = (beta - alpha)/(b - a);
    float T0 = 1.0;
    
    ModShooting(*(funct), a, b, alpha, beta, N, TOL, M, T0);
    
    
}
