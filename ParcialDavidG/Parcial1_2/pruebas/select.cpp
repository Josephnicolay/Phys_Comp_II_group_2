#include <stdio.h>
#include <iostream>
#include <string>
#include <time.h>
#include <fstream>
#include <stdlib.h>

void palabra();

using namespace std;

int main(){

    palabra();

}

void palabra(){

    ifstream inFile;
    inFile.open("palabras");
    
    srand(time(NULL));
    int number=1 + rand() % (20 +1 - 1);

    if (inFile.fail()) {
            cerr << "Unable to open file convertir.txt";
            exit(1);   // call system to stop
    }
    
    string linea;
    string palabra;
    int cont=0;
    
    while(inFile>>linea && cont<=number){
    
        palabra = linea;
        cont++;
        
    }
    
    inFile.close();
    
    cout<< palabra<<endl;

}