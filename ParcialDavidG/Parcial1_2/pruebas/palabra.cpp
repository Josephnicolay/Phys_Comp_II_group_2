#include <iostream>
#include <iomanip>
#include <math.h>
#include <string>
#include <stdlib.h>
#include <cstring>
#include <fstream>

using namespace std;

    string setPalabra();
    int comprobarPalabra(const string, const string);
    string comprobarLetra(const string, string, string);
    string ingresarLetra(const string , string, int &);
    void ascii(int);
    string obtenerLineas(ifstream&);

    int main(){
        //string palabra="pasaje";
        string palabra = setPalabra();
        string oculta=".";

        for (int i=0; i<palabra.size(); i++){
            oculta.append("_.");
        }

        cout<<"Adivine la palabra:"<<right<<setw(3+2*palabra.size())<<oculta<<endl;

        
        /*oculta=ingresarLetra(palabra,oculta);
        cout<<oculta<<endl;*/
        int cont=0;
        
        while (oculta.find("_")!=-1 && cont<7){
        
            oculta=ingresarLetra(palabra,oculta,cont);
            cout<<oculta<<endl;
            
            if (cont!=0){
                //cout<<oculta<<endl;
                ascii(cont);
            }
            
        }
        cout<<"Ha perdido, la palabra era:"<<setw(palabra.size()+2)<<palabra<<endl;
        
    }

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

    int comprobarPalabra(const string _palabra, const string _oculta){
        int val =0;
        if (_palabra.compare(_oculta)==0){

            val=1;

            }

        return val;

        }

    string comprobarLetra(const string _palabra, string _oculta, string _letra){

        size_t found = _palabra.find(_letra); 

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
                cout<<positions[i]<<endl;
            }

        }
        
        return _oculta;

    }

    string obtenerLineas(ifstream& archivo){
    
        string lineas="";
        if (archivo){
            while (archivo.good())
            {
                std::string lineaTemporal;                 
                std::getline (archivo , lineaTemporal);       
                lineaTemporal += "\n";                    

                lineas += lineaTemporal;                   
            }
            return lineas;
        }
        else{
            return "ERROR File does not exist.";
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
