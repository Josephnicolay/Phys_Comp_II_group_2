#include <iostream>
#include <iomanip>
#include <math.h>
#include <string>
#include <stdlib.h>
#include <cstring>
#include <fstream>
#include <vector>

using namespace std;

string setPalabra();
int adivinarPalabra(const string, const string);
string comprobarLetra(const string, string, string);
string ingresarLetra(const string , string, int &);
void ascii(int);
string obtenerLineas(ifstream&);
void Jugar();