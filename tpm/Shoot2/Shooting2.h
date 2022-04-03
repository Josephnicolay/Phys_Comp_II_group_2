#include <string>
#include <vector>
#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

vector<double> Schroedinger(vector<float>, double, double);

vector<double> RK4(double (*funct)(double, double, double, double), double, double, vector<double>, double);

vector<double> Shoot(double (*funct)(double, double, double, double), vector<double>, vector<double>, vector<double>, vector<double>);

