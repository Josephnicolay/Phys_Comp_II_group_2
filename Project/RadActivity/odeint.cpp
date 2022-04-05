#include <iostream>
#include <iomanip>
#include <valarray>
#include <fstream>
using namespace std;

// Function prototypes
void RK4step( double, double &, valarray<double> & );
valarray<double> Bateman( double t, valarray<double> N );

//======================================================================


int main()
{
   int pasos = 50;
   double t = 0.0;
   double dt = 2;
    
   valarray<double> SolN(2);

   // Valores iniciales.
   SolN[0] = 250;   
   SolN[1] = 0;
    
   ofstream outFile;
   outFile.open("Analitica.txt");

   // Write header and initial conditions
   //#define SP << setw( 12 ) << fixed << setprecision( 4 ) <<    // save some repetition when writing
   outFile << 't' << setw( 12 ) << fixed << setprecision( 4 ) << "NR"  << setw( 12 ) << fixed << setprecision( 4 ) << "NA"  << endl;
   outFile <<  t  << setw( 12 ) << fixed << setprecision( 4 ) << SolN[0] << setw( 12 ) << fixed << setprecision( 4 ) << SolN[1] << endl;

   // Solve the differential equation using nstep intervals
   for ( int n = 1; n <= pasos; n++ ) 
   {
      RK4step( dt, t, SolN );                          // main Runge-Kutta step
      outFile << t << setw( 12 ) << fixed << setprecision( 4 ) << SolN[0] << setw( 12 ) << fixed << setprecision( 4 ) << SolN[1] << endl;         // output
   }
}

//======================================================================

void RK4step( double dt, double &t, valarray<double> &N )
{
   int ndep = N.size();
   valarray<double> dN1(ndep), dN2(ndep), dN3(ndep), dN4(ndep);

   dN1 = Bateman( t           , N             ) * dt;
   dN2 = Bateman( t + 0.5 * dt, N + 0.5 * dN1 ) * dt;
   dN3 = Bateman( t + 0.5 * dt, N + 0.5 * dN2 ) * dt;
   dN4 = Bateman( t +       dt, N       + dN3 ) * dt;
   N += ( dN1 + 2.0 * dN2 + 2.0 * dN3 + dN4 ) / 6.0;

   t += dt;
}

//======================================================================

valarray<double> Bateman( double t, valarray<double> N )
{
   float tau_rad = 20.8/log(2.0);
   float tau_act = 10.0/log(2.0);
   valarray<double> f( N.size() );               // this will be returned as F in the output

   f[0] = -1/tau_rad*N[0];         // ****************************************
   f[1] =  1/tau_rad*N[0] - 1/tau_act*N[1];         // just encode derivative components here *
                                                 // ****************************************
   return f;
}

//====================================================================== 