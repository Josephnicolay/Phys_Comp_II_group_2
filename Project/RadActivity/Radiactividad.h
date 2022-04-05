#include <random>
#include <iomanip>
#include <iostream>
#include <cmath>
#include <bits/stdc++.h>
#include <fstream>

using namespace std;

void Analitic(float (*funct)(float, float, float), float, float, float, float, int, string);

void mcSim(int, float, float, float ,int, vector<float> &, vector<float> &);

void Archivo(int, int, vector<float>, vector<float>);
