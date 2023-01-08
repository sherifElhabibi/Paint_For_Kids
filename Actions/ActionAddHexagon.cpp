#include "ActionAddHexagon.h"
#include "..\Figures\CHexagon.h"

#include "..\ApplicationManager.h"

#include "..\GUI\GUI.h"

ActionAddHexagon::ActionAddHexagon(ApplicationManager* pApp) :Action(pApp)
{}

//Execute the action
void ActionAddHexagon::Execute()
{
	Point P1, P2;
	int H, L;

	//Get a Pointer to the Interface
	GUI* pGUI = pManager->GetGUI();


	GfxInfo SqrGfxInfo;
	SqrGfxInfo.isFilled = false;	//default is not filled
	//get drawing, filling colors and pen width from the interface
	SqrGfxInfo.DrawClr = pGUI->getCrntDrawColor();
	SqrGfxInfo.FillClr = pGUI->getCrntFillColor();
	SqrGfxInfo.BorderWdth = pGUI->getCrntPenWidth();


	//Step 1 - Read Hexagon data from the user

	pGUI->PrintMessage("New Hexagon: Click at first point");
	//Read 1st point and store in point P1
	pGUI->GetPointClicked(P1.x, P1.y);

	pGUI->PrintMessage("New Hexagon: Click at second point");
	//Read 2nd point and store in point P2
	pGUI->GetPointClicked(P2.x, P2.y);

	pGUI->ClearStatusBar();



	//Step 2 - Create a Hexagon with the parameters read from the user
	Point TopLeft;
	TopLeft.x = P1.x < P2.x ? P1.x : P2.x;
	TopLeft.y = P1.y < P2.y ? P1.y : P2.y;
	 L = abs(TopLeft.x - P2.x);
	 H = abs(TopLeft.y - P2.y);
	CHexagon* R = new CHexagon(TopLeft,H,L, SqrGfxInfo);

	//Step 3 - Add the Square to the list of figures
	if (P1.y >= UI.ToolBarHeight && P1.y < UI.height - UI.StatusBarHeight && P2.y >= UI.ToolBarHeight && P2.y < UI.height - UI.StatusBarHeight)
	{

		pManager->AddFigure(R);
	}
	else
	{
		pGUI->PrintMessage("Shape is Out of Drawing Area Boundry");
	}
}
