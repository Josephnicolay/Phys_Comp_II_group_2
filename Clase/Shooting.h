#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <iomanip>


using namespace std;

double dfdy(float (*funct)(float, float, float), float, float, float);

double dfdyp(float (*funct)(float, float, float), float, float, float);

void Shooting(float (*funct)(float,float,float), float , float , float , float , int , float , int );

void GenerarArchivo();
