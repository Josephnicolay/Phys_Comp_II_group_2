#include <Radiactividad.h>

using namespace std;

float Analitic(int time, float lambda, float ){
        pass;
}

void mcSim(int N0, float t_half_rad, float t_half_act, float tf, int maxPoints, vector<float> &PopulationRad, vector<float> &PopulationAct){

    float dt = tf/maxPoints;
    vector<float> atoms1(N0,1);
    vector<float> atoms2(N0,2);


    float decProb_rad = 1 - exp(-dt/t_half_rad*log(2.0));
    float decProb_act = 1 - exp(-dt/t_half_act*log(2.0));

    for (int i=0; i<maxPoints;i++){
    
        PopulationRad[i] = count(atoms1.begin(),atoms1.end(),1);
        PopulationAct[i] = count(atoms2.begin(),atoms2.end(),2);

        for (int j=0; j<N0; j++){

            if (atoms1[j] == 1){ //Deciding whether the given atom should decay
                if (1.0/RAND_MAX*random() <= decProb_rad){
                    atoms1[j] = 2;
                }
                else{
                    atoms1[j] = 1;
                }
            }
            else if (atoms2[j] == 2){

                if (1.0/RAND_MAX*random() <= decProb_act){
                    atoms2[j] = 3;
                }
                else{
                    atoms2[j] = 2;
                }
            }
        }
    }
}


void Archivo(int Ttotal, vector<int> v1, vector<int> v2){

    ofstream outFile;
    outFile.open ("population.txt");
    
    outFile << left << setw(5) << "time" << setw(8) << "PopRad" << setw(8) << "PopAct" << endl;
    
    int cont = 0;
    
    while(cont < Ttotal){
    
        outFile << left << setw(5) << cont << setw(8) << v1[cont] << setw(8) << v2[cont] << endl;
        
        cont++;
    }
    
    outFile.close();

}