#include <random>
#include <iomanip>
#include <iostream>
#include <cmath>
#include <bits/stdc++.h>

using namespace std;

float Analitic(int, float, float);

void mcSim(int, float, float, float ,int, vector<int> &, vector<int> &);

int main(){

//initial conditions
float t_half_rad   = 20.8;
float t_half_act   = 10.0;
int N0           = 250;
int t1           = 100;
int n_timepoints = 50;

vector<int> PopulationRad={n_timepoints,0};
vector<int> PopulationAct={n_timepoints,0};

mcSim(N0, t_half_rad, t_half_act, t1, n_timepoints, PopulationRad, PopulationAct);

for (int i=0; i<n_timepoints; i++){

	cout<<PopulationRad[i]<<" | "<<PopulationAct[i]<<endl;

}

}

float Analitic(int N0, float t_half, float time){

	return exp(-time/t_half*log(2.0));

}

void mcSim(int N0, float t_half_rad, float t_half_act, float tf, int maxPoints, vector<int> &PopulationRad, vector<int> &PopulationAct){

	float dt = tf/maxPoints;
	vector<int> atoms{N0,1};

	float decProb_rad = 1 - exp(-dt/t_half_rad*log(2.0));
	float decProb_act = 1 - exp(-dt/t_half_act*log(2.0));

	for (int i=0; i<maxPoints;i++){
	
		PopulationRad[i] = count(atoms.begin(),atoms.end(),1);
		PopulationAct[i] = count(atoms.begin(),atoms.end(),2);

		if (atoms[i] == 1){ //Deciding whether the given atom should decay
                	if (random() <= decProb_rad){
                    		atoms[i] = 2;
			}
                	else{
                    		atoms[i] = 1;
			}
		}
            	else if (atoms[i] == 2){

                	if (random() <= decProb_act){
                    		atoms[i] = 3;
			}
                	else{
                    		atoms[i] = 2;
			}
		}

	}


}
