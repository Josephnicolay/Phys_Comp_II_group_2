#include <iostream>
#include <iomanip>
#include <valarray>
using namespace std;

void RK4step( double, double &, valarray<double> & );
valarray<double> F( double , valarray<double> );
void Solution(int, double, double, double, double);