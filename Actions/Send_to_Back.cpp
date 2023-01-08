#include "Send_to_Back.h"

// Constructor of AddEllipse Action Class
Send_to_Back::Send_to_Back(ApplicationManager* pApp, CFigure* s) : Action(pApp), Selected(s)
{}

//Read Function to Read Ellipse parameters
void Send_to_Back::ReadActionParameters()
{}

//Add Ellipse to the ApplicationManager To Execute it 
void Send_to_Back::Execute()
{
	GUI* pGUI = pManager->GetGUI();
	int selectedIndex = pManager->getSelectedFigure();
	if (selectedIndex != -1) {
		pManager->Send_Back(selectedIndex);
		pGUI->ClearDrawArea();
	}
	else {
		pGUI->PrintMessage("Select a shape before you can perform this action");
	}
}