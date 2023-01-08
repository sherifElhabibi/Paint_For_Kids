#include "ActionBackToDraw.h"

#include "..\ApplicationManager.h"

#include "..\GUI\GUI.h"

ActionBackToDraw::ActionBackToDraw(ApplicationManager* pApp) :Action(pApp)
{}

//Execute the action
void ActionBackToDraw::Execute()
{
	CFigure** FigsList = pManager->getFigureList();
	int* figcount = pManager->getFigCount();
	for (int i = 0; i < *figcount; i++)
	{
		FigsList[i]->ChngDrawClr(BLUE);

	}
	pManager->UpdateInterface();
	GUI* pGUI = pManager->GetGUI();
	pGUI->ClearToolBar();
	pGUI->CreateDrawToolBar();
	pGUI->ClearStatusBar();

}
