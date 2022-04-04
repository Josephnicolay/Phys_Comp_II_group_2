#include "Radiactividad.h"

using namespace std;

int main(){

    //initial conditions
    float t_half_rad   = 20.8;
    float t_half_act   = 10.0;
    int N0           = 250;
    int t1           = 100;
    int n_timepoints = 50;

    vector<float> PopulationRad(n_timepoints,0);
    vector<float> PopulationAct(n_timepoints,0);
    
    mcSim(N0, t_half_rad, t_half_act, t1, n_timepoints, PopulationRad, PopulationAct);
    
    Archivo(n_timepoints, PopulationRad, PopulationAct);

}
