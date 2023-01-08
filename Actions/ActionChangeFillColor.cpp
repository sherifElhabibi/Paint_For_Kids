#include "ActionChangeFillColor.h"

#include "..\ApplicationManager.h"

#include "..\GUI\GUI.h"

ActionChangeFillColor::ActionChangeFillColor(ApplicationManager* pApp) :Action(pApp)
{}

//Execute the action
void ActionChangeFillColor::Execute()
{
	Point P1;
	GUI* pGUI = pManager->GetGUI();
	CFigure** FigsList = pManager->getFigureList();
	int* figcount = pManager->getFigCount();
	for (int i = *figcount - 1; i >= 0; i--)
	{
		if (FigsList[i]->IsSelected())
		{
			pGUI->ClearToolBar();
			pGUI->CreateColorToolBar();
			pGUI->PrintMessage("Pick color from platte");
			pGUI->GetPointClicked(P1.x, P1.y);
			for (int i = *figcount - 1; i >= 0; i--)
			{
				if (FigsList[i]->IsSelected())
				{
					FigsList[i]->SetSelected(false);
					FigsList[i]->ChngFillClr(pGUI->pWind->GetColor(P1.x, P1.y));	
				}
			}
			pGUI->ClearToolBar();
			pGUI->CreateDrawToolBar();
			break;
		}
	}

	pGUI->ClearStatusBar();
}
