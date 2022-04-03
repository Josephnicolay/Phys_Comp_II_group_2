#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <iomanip>


using namespace std;

double dfdy(float (*funct)(float, float, float), float, float, float);

double dfdyp(float (*funct)(float, float, float), float, float, float);

void ModShooting(float (*funct)(float,float,float), float , float , float , float , int , float , int , float);

void GenerarArchivo();
