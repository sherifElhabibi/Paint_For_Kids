#include "ActionAddCircle.h"
#include "..\Figures\CCircle.h"

#include "..\ApplicationManager.h"

#include "..\GUI\GUI.h"

ActionAddCircle::ActionAddCircle(ApplicationManager* pApp) :Action(pApp)
{}

//Execute the action
void ActionAddCircle::Execute()
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

	pGUI->PrintMessage("New Circle: Click at first point");
	//Read 1st point and store in point P1
	pGUI->GetPointClicked(P1.x, P1.y);
	pGUI->PrintMessage("New Circle: Click at second point");
	//Read 1st point and store in point P1
	pGUI->GetPointClicked(P2.x, P2.y);
	
	pGUI->ClearStatusBar();
	Point center;
	center.x = P1.x;
	center.y = P1.y;

	//2.2- Calcuate square side legnth
	//The square side length would be the longer distance between the two points coordinates
	int reduis = max(abs(P1.x - P2.x), abs(P1.y - P2.y));

	//Step 3 - Create a Square with the parameters read from the user
	CCircle* C = new CCircle(center, reduis, SqrGfxInfo);
	if (P1.y >= UI.ToolBarHeight && P1.y < UI.height - UI.StatusBarHeight && P2.y >= UI.ToolBarHeight && P2.y < UI.height - UI.StatusBarHeight)
	{
		
		pManager->AddFigure(C);
	}
	else
	{
		pGUI->PrintMessage("Shape is Out of Drawing Area Boundry");
	}
	//Step 4 - Add the Square to the list of figures
	
}
