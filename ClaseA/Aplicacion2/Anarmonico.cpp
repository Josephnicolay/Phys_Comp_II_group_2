#include <string>
#include <vector>
#include <cmath>
#include <iomanip>

#include "ModShooting.h"


using namespace std;

const static float alpha = -1.0;
const static float beta = 1.0;
const static float delta = 0.3;
const static float gamm = 0.65;
const static float w = 1.2;


float funct(float _x,float _y, float _yp){
    return gamm*cos(w*_x) - delta*_yp - alpha*_y - beta*pow(_y, 3);
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
    float alpha = 1.0;
    float beta = 0.5;
    int N = 30, M = 30;
    float TOL = 1e-5;
    float T0 = (beta - alpha)/(b - a);
    //float T0 = 1.0;
    
    ModShooting(*(funct), a, b, alpha, beta, N, TOL, M, T0);
    
    
}
