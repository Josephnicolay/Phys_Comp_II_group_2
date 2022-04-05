#include "Radiactividad.h"

using namespace std;

void Analitic(float (*funct)(float,float,float), float thalf, float tini, float tfin, float P0, int M, string fileName){
    float h=(tfin-tini)/M;
    float t=tini;
    float Pop=P0;
    
    ofstream outFile;
    outFile.open(fileName.c_str());
    
    outFile<<setw(11)<<"time"<<setw(11)<<"Population"<<endl;
    outFile<<setw(11)<<t<<setw(11)<<Pop<<endl;
    
    for (int i=1;i<=M;i++){
        
        float k1=funct(t,Pop,thalf)*h;
        float k2=funct(t+h/2.0,Pop+k1/2.0,thalf)*h;
        float k3=funct(t+h/2.0,Pop+k2/2.0,thalf)*h;
        float k4=funct(t+h,Pop+k3,thalf)*h;
        
        t=tini+i*h;
        Pop+=(k1+2*k2+2*k3+k4)/6.0;
        outFile<<setw(11)<<t<<setw(11)<<Pop<<endl;
    }
    
    outFile.close();
}

void mcSim(int N0, float t_half_rad, float t_half_act, float tf, int maxPoints, vector<float> &PopulationRad, vector<float> &PopulationAct){

    float dt = tf/maxPoints;
    vector<float> atoms(N0,1);
    //vector<float> atoms2(N0,2);


    float decProb_rad = 1 - exp(-dt/t_half_rad*log(2.0));
    float decProb_act = 1 - exp(-dt/t_half_act*log(2.0));

    for (int i=0; i<maxPoints;i++){
    
        PopulationRad[i] = count(atoms.begin(),atoms.end(),1);
        PopulationAct[i] = count(atoms.begin(),atoms.end(),2);

        for (int j=0; j<N0; j++){

            if (atoms[j] == 1){ //Deciding whether the given atom should decay
                if (1.0/RAND_MAX*random() <= decProb_rad){
                    atoms[j] = 2;
                }
                else{
                    atoms[j] = 1;
                }
            }
            else if (atoms[j] == 2){

                if (1.0/RAND_MAX*random() <= decProb_act){
                    atoms[j] = 3;
                }
                else{
                    atoms[j] = 2;
                }
            }
        }
    }
}


void Archivo(int Ttotal, int numPoints, vector<float> v1, vector<float> v2){
    
    float dt = Ttotal/numPoints;

    ofstream outFile;
    outFile.open ("population.txt");
    
    outFile << left << setw(5) << "time" << setw(8) << "PopRad" << setw(8) << "PopAct" << endl;
    
    int cont = 0;
    
    while(cont*dt < Ttotal){
    
        outFile << left << setw(5) << cont*dt << setw(8) << v1[cont] << setw(8) << v2[cont] << endl;
        
        cont++;
    }
    
    outFile.close();

}
