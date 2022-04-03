#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <iomanip>


using namespace std;

void Shooting(float (*funct)(float,float,float), float (*dfdy)(float,float,float), float (*dfdyp)(float,float,float) , 
              float , float , float , float , int , float , int );

void GenerarArchivo();