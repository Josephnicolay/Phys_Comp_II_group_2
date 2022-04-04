#ifndef CONSTRUCTION_HH
#define CONSTRUCTION_HH

#include "G4SystemOfUnits.hh"

class MyDetectorConstruction : public G4UserDetectorConstruction
{
	public:
		//Constructor of Detector
		MyDetectorConstruction();
		~MyDetectorConstruction();
		
		//Construct Geometry of the Detector
		virtual G4VPhysicalVolume *Construct();
		
}
		
	
	
