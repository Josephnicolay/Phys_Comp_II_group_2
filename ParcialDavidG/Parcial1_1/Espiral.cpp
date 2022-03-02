#include "Espiral.h"

using namespace std;

Espiral::Espiral(double _radio, double _angVel, double _Dt, double _tMax, double _fase, double _z0, double _vz0)
    :Circular (_radio, _angVel, _Dt, _tMax, _fase)
    {
    
        setZ0(_z0);
        setVz0(_vz0);
    
    }

Espiral::~Espiral(){

}

void Espiral::setZ0(double _z0){

    z0 = _z0;

}

void Espiral::setVz0(double _vz0){

    vz0 = _vz0;

}

double Espiral::getZ0(){

    return z0;

}

double Espiral::getVz0(){

    return vz0;

}

double zPos(double _T){

    return getZ0()*_T;

}
