#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <cmath>
#include <math.h>


#include "Circular.h"

using namespace std;

const static double PI =  M_PI;

int main(){

    //Parámetros predeterminados.
    double R = 1.5;
    double W = 2.0;
    double Dt = 0.1;
    double Ttotal = 3.2;
    double alpha = PI/4.0;
    double Zini = 0.5;
    double Vzini = 2.1;
    
    Circular mov1(R, W, Dt, Ttotal, alpha);
    mov1.imprimirVars();
    mov1.imprimirPos(0.0);
    mov1.generarArchivo();

}