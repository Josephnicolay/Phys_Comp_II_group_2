#include <string>
#include <vector>
#include <cmath>
#include <iomanip>

#include "../Shooting.h"


using namespace std;


float funct(float _x,float _y, float _yp){
    return (32 + 2 * pow(_x, 3) - _y * _yp) / 8;
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
    
    float a = 1;
    float b = 3;
    float alpha = 17.0;
    float beta = 43.0/3.0;
    int N = 20, M = 10;
    float TOL = 1e-5; 
    
    Shooting(*(funct), a, b, alpha, beta, N, TOL, M);
    
    
}
