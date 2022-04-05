#include "ODE.h"

void RK4step( double dt, double &t, valarray<double> &N )
{
   int popVar = N.size();
   valarray<double> dN1(2), dN2(2), dN3(2), dN4(2);

   dN1 = F( t           , N             ) * dt;
   dN2 = F( t + 0.5 * dt, N + 0.5 * dN1 ) * dt;
   dN3 = F( t + 0.5 * dt, N + 0.5 * dN2 ) * dt;
   dN4 = F( t +       dt, N       + dN3 ) * dt;
   N += ( dN1 + 2.0 * dN2 + 2.0 * dN3 + dN4 ) / 6.0;

   t += dt;
}

valarray<double> F( double t, valarray<double> N )
{
   float tau_rad = 20.8/log(2.0);
   float tau_act = 10.0/log(2.0);
   valarray<double> f( N.size() );               

   f[0] = -1/tau_rad*N[0];         
   f[1] =  1/tau_rad*N[0] - 1/tau_act*N[1];
                                                 
   return f;
}

void Solution(int Pasos, double t0, double dt, double NR0, double NA0){

    valarray<double> SolN(2);
    
   #define SP << setw( 12 ) << fixed << setprecision( 4 ) <<    // save some repetition when writing
   cout << "t" SP "NR"  SP "NA"  << endl;
   cout <<  t0 << setw( 12 ) << fixed << setprecision( 4 ) <<  SolN[0] << setw( 12 ) << fixed << setprecision( 4 ) <<  SolN[1] << endl;
    
    for ( int n = 1; n <= Pasos; n++ ) {
      RK4step( dt, t0, SolN );                          // main Runge-Kutta step
      cout << t0 SP SolN[0] SP SolN[1] << endl;         // output
   }
    
}






