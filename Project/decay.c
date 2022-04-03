# include <stdio.h>
#include <stdlib.h>

#define drand48 1.0/RAND_MAX*rand
#define srand48 srand
#define lambda 0.04 // the decay constant
#define max 1250 // number of atoms at t =0
#define time_max 500 // time range
#define seed 68111 // seed for number generator


int main ( ) {

int atom , time , number , nloop ;
double decay ;

FILE * output ; // save data in decay.dat
output = fopen ("decay.dat" ,"w") ;
number = nloop = max ; // initial value

//seed number generator
srand48 ( seed );

// time loop
for ( time = 0; time<=time_max ; time ++) {
	// atom loop
	for ( atom = 1; atom<=number ; atom++) {
		decay = drand48 ( ) ;
		if ( decay < lambda ){
		nloop--;
		} // an atom decays
	}
	number = nloop ;
	fprintf ( output , "%d\t%f\n" , time , ( double ) number) ;
}
printf ("data stored in decay.dat\n") ;
fclose(output);
}
