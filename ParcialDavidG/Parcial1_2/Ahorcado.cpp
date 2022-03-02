#include <iostream>
#include <iomanip>
#include <math.h>
#include <string>
#include <stdlib.h>
#include <cstring>
#include <vector>
#include <fstream>

#include "Ahorcado.h"

using namespace std;

string setPalabra(){
    
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
        
    return palabra;
    
}

int adivinarPalabra(const string _palabra){
    int val =0;
    string intento;
    cout << "La palabra oculta es:"<<endl;
    cin >> intento;
    
    if (_palabra.compare(intento)==0){
        
        cout<<"Ha encontrado la palabra oculta!"<<endl;
        val=1;

    }
    else{
    
        cout<<"No era la palabra oculta."<<endl;
        
    }

    return val;
}

string ingresarLetra(const string _palabra, string _oculta, int &contError){

    string _letra;
    cout<<"Ingrese una letra... ";
    cin >> _letra;

    vector<int> positions;

    int found = _palabra.find(_letra);
        
    if (found==-1){
        contError+=1;
    }
        
    else{
        
        positions.push_back(found);
        
        while(found>-1){
        
            found=_palabra.find(_letra,found+1);
            positions.push_back(found);
            
        }
            
        
        for (int i=0; i<positions.size()-1; i++){
            _oculta.replace(2*positions[i]+1,1,_letra);
            //cout<<positions[i]<<endl;
        }

    }
        
    return _oculta;

}

string obtenerLineas(ifstream& archivo){
    
    string lineas="";
    if (archivo){
        while (archivo.good()){
            
            std::string lineaTemporal;                 
            std::getline (archivo , lineaTemporal);       
            lineaTemporal += "\n";                    

            lineas += lineaTemporal;                   
        }
        return lineas;
    }
    else{
        return "El archivo no está.";
    }
}

void ascii(int error){
    
    char estado=error+'0';
    char archivoNombre[20]={'a','s','c','i','i','/','a','h','o','r','c','a','d','o',estado,'.','d','a','t'};
 
    ifstream Lector (archivoNombre);
        
    string ascii = obtenerLineas (Lector);
    cout << ascii << std::endl;
    Lector.close ();
 
}


void Jugar(){

    string palabra = setPalabra();
    string oculta=".";
    
    for (int i=0; i<palabra.size(); i++){
        oculta.append("_.");
    }

    cout<<"Adivine la palabra:"<<right<<setw(3+2*palabra.size())<<oculta<<endl;
    
    int cont=0;
        
    while (oculta.find("_")!=-1 && cont<7){
        
        char adivinar = 'n';
        
        oculta=ingresarLetra(palabra,oculta,cont);
        cout<<setw(15)<<oculta<<endl;
            
        if (cont!=0){
            ascii(cont);
        }
        
        cout<<"Quiere adivinar la palabra? [y]/[n]";
        cin>>adivinar;
        
        if (adivinar=='y'){
            
            int continuar = adivinarPalabra(palabra);
            
            if (continuar==1){
                break;
            }
            else {
            
                ascii(cont+1);
                cont++;
            
            }
            
        }
            
    }
    
    if (oculta.find("_")!=-1 && cont<7){
        return ;
    }
    else{
        cout<<"Ha sido colgado, la palabra oculta era:"<<setw(palabra.size()+2)<<palabra<<endl;
    }

}

