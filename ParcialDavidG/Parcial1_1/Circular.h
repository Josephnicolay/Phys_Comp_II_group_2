#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <cmath>
#include <math.h>


using namespace std;

#ifndef CIRCULAR_H
#define CIRCULAR_H

class Circular{

    public:
        Circular(double, double, double, double, double);
        ~Circular();
    
        double xPos(double);
        double yPos(double);
    
        void setRadio(double);
        void setVel(double);
        void setDt(double);
        void setT(double);
        void setFase(double);
    
        double getRadio();
        double getVel();
        double getDt();
        double getT();
        double getFase(); 
    
        void imprimirVars();
        void imprimirPos(double);
    
        void generarArchivo();
    
    
    private: 
        double radio;
        double angVel;
        double dt;
        double tMax;
        double fase;
    
};

#endif
