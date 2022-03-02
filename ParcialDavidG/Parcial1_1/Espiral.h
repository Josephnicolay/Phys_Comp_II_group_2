#ifndef ESPIRAL_H
#define ESPIRAL_H

#include "Circular.h"

using namespace std;

class Espiral : public Circular {

    public:
        Espiral(double, double, double, double, double, double, double);
        ~Espiral();
    
        void setZ0(double);
        void setVz0(double);
    
        double getZ0();
        double getVz0();
    
        double zPos(double);
    
    private:
        double z0;
        double vz0;

};

#endif