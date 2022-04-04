//PREPROCESSORS
//libraries -> C++
#include <iostream>
//--------------------------------------------------------------

//Toolkit classes of Geant4
#include "G4RunManager.hh"
//#include "G4MTRunManager.hh"
#include "G4UImanager.hh"
#include "G4UIExecutive.hh"
#include "G4VisManager.hh"
#include "G4VisExecutive.hh"

#include "construction.hh"
#include "physics.hh"
#include "action.hh"



int main(int argc, char** argv)
{
	//Construct the default Manager
	G4RunManager *runManager = new G4RunManager();
	
	//Iniatialize class MyDetectorConstruction
	runManager->SetUserInitialization(new MyDetectorConstruction());
	
	////Iniatialize class MyPhysicsList()
	runManager->SetUserInitialization(new MyPhysicsList());
	
	////Iniatialize class MyPhysicsList()
	runManager->SetUserInitialization(new MyActionInitialization());
	//Initialize Manager
	runManager->Initialize();
	
	//Define UI(User Interface) session 	
	G4UIExecutive *ui = new G4UIExecutive(argc, argv);
	
	// Initialize visualization
	G4VisManager *visManager = new G4VisExecutive();
	visManager->Initialize();
	
	// Get the pointer to the User Interface manager
	G4UImanager *UImanager = G4UImanager::GetUIpointer();
	
	//Commands using UImanager
	UImanager->ApplyCommand("/vis/open OGL");
	UImanager->ApplyCommand("/vis/viewer/set/viewpointVector 1 1 1");
	UImanager->ApplyCommand("/vis/drawVolume");
	UImanager->ApplyCommand("/vis/viewer/set/autoRefresh true");
	UImanager->ApplyCommand("/vis/scene/add/trajectories smooth");
	
	
	//UI start
	ui->SessionStart();
	
	
	
	
	
	return 0;
}
