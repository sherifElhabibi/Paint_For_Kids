#include "ActionChangeBKColor.h"

#include "..\ApplicationManager.h"

#include "..\GUI\GUI.h"

ActionChangeBKColor::ActionChangeBKColor(ApplicationManager* pApp) :Action(pApp)
{}

//Execute the action
void ActionChangeBKColor::Execute()
{

	Point P1;
	GUI* pGUI = pManager->GetGUI();
	pGUI->ClearToolBar();
	pGUI->CreateColorToolBar();
	pGUI->PrintMessage("Pick color from platte");
	pGUI->GetPointClicked(P1.x, P1.y);
	UI.BkGrndColor= pGUI->pWind->GetColor(P1.x, P1.y);
	pGUI->ClearDrawArea();
	pGUI->ClearToolBar();
	pGUI->CreateDrawToolBar();
	pGUI->ClearStatusBar();
}
