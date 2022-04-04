#include "construction.hh"



MyDetectorConstruction::MyDetectorConstruction()
{}


MyDetectorConstruction::~MyDetectorConstruction()
{}

G4VPhysicalVolume *MyDetectorConstruction::Construct()
{
	//Medium in Material 
	G4NistManager *nist = G4NistManager::Instance();
	G4Material *worldmat = nist->FindOrBuildMaterial("G4 AIR");
	
	//Geometry of Material: volume m³ (G4 SystemOfUnits)
	G4Box *solidWorld = new G4Box("solidWorld", 0.5*m,0.5*m,0.5*m);
	
	G4LogicalVolume *logicWorld = new G4LogicalVolume(solidWorld, worldMat, "logicWorld");
	
	G4PhysicalVolume *physWorld = new G4PVPlacement(0, G4ThreeVector(0.,0.,0.), logicWorld, "physWorld", 0)
}
