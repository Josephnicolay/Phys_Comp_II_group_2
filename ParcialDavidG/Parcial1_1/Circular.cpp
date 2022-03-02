#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <cmath>
#include <math.h>
#include <fstream>


#include "Circular.h"

using namespace std;

Circular::Circular(double _radio, double _angVel, double _Dt, double _tMax, double _fase){

    radio  = _radio;
    angVel = _angVel;
    dt     = _Dt;
    tMax   = _tMax;
    fase   = _fase;
    
}

Circular::~Circular(){

}

void Circular::setRadio(double _radio){

    if (_radio > 0){
        radio = _radio;
    }
    else{
        radio = 0;
    }

}

void Circular::setVel(double _angVel){

    angVel = _angVel;

}

void Circular::setDt(double _Dt){

    if (_Dt > 0){
    
        dt = _Dt;
    
    }
    else{
        dt = 0.01;
    }

}

void Circular::setT(double _tMax){

    if (_tMax > 0){
    
        tMax = _tMax;
    
    }
    else{
        tMax = 0;
    }

}

void Circular::setFase(double _fase){

    fase = _fase;

}

double Circular::getRadio(){

   return radio;

}

double Circular::getVel(){

    return angVel;

}

double Circular::getDt(){

    return dt;

}

double Circular::getT(){

   return tMax;

}

double Circular::getFase(){

    return fase;

}

double Circular::xPos(double _T){

    return radio * cos(angVel * _T + fase);

}

double Circular::yPos(double _T){

    return radio * sin(angVel * _T + fase);

}

void Circular::imprimirVars(){

    cout<<setw(5)<<"R:"<<setw(9)<<getRadio()<<endl;
    cout<<setw(5)<<"w:"<<setw(9)<<getVel()<<endl;
    cout<<setw(5)<<"dt:"<<setw(9)<<getDt()<<endl;
    cout<<setw(5)<<"T:"<<setw(9)<<getT()<<endl;
    cout<<setw(5)<<"a:"<<setw(9)<<getFase()<<endl;
    
}

void Circular::imprimirPos(double _T){

    cout<<"La posición de la partícula en el tiempo"<<setw(5)<<_T<<" es:"<<setw(5)<<xPos(_T)<<","<<setw(5)<<yPos(_T)<<endl;

}

void Circular::generarArchivo(){

    ofstream outFile;
    outFile.open ("posiciónCircular.txt");
    
    int N = tMax / dt;
    int cont = 0;
    
    while(cont < N){
    
        double time = cont * dt;
        outFile << left << setw(5) << time << setprecision(5) << setw(10) << xPos(time)<< setprecision(5) << setw(10) << yPos(time) << endl;
        
        cont++;
    
    }
    
    outFile.close();
   

}





















