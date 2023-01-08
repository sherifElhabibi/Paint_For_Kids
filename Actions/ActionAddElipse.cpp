#include "ActionAddElipse.h"

#include "..\Figures\CElipse.h"

#include "..\ApplicationManager.h"

#include "..\GUI\GUI.h"
#include "Action.h"

ActionAddElipse::ActionAddElipse(ApplicationManager* pApp) :Action(pApp)
{}

//Execute the action
void ActionAddElipse::Execute()
{
	Point P1, P2;

	//Get a Pointer to the Interface
	GUI* pGUI = pManager->GetGUI();


	GfxInfo SqrGfxInfo;
	SqrGfxInfo.isFilled = false;	//default is not filled
	//get drawing, filling colors and pen width from the interface
	SqrGfxInfo.DrawClr = pGUI->getCrntDrawColor();
	SqrGfxInfo.FillClr = pGUI->getCrntFillColor();
	SqrGfxInfo.BorderWdth = pGUI->getCrntPenWidth();


	//Step 1 - Read Square data from the user

	pGUI->PrintMessage("New Elipse: Click at first point");
	//Read 1st point and store in point P1
	pGUI->GetPointClicked(P1.x, P1.y);

	pGUI->PrintMessage("New Elipse: Click at second point");
	//Read 2nd point and store in point P2
	pGUI->GetPointClicked(P2.x, P2.y);

	pGUI->ClearStatusBar();

	//Step 3 - Create an E with the parameters read from the user
	CElipse* E = new CElipse(P1, P2, SqrGfxInfo);
	if (P1.y >= UI.ToolBarHeight && P1.y < UI.height - UI.StatusBarHeight && P2.y >= UI.ToolBarHeight && P2.y < UI.height - UI.StatusBarHeight)
	{

		pManager->AddFigure(E);
	}
	else
	{
		pGUI->PrintMessage("Shape is Out of Drawing Area Boundry");
	}
	//Step 4 - Add the Square to the list of figures
}

class ActionColorApplied :
	public Action
{
};
