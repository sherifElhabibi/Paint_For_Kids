#include "ActionAddTriangle.h"
#include "..\Figures\CTriangle.h"

#include "..\ApplicationManager.h"

#include "..\GUI\GUI.h"

ActionAddTriangle::ActionAddTriangle(ApplicationManager* pApp) :Action(pApp)
{}

//Execute the action
void ActionAddTriangle::Execute()
{
	Point P1,P2,P3;

	//Get a Pointer to the Interface
	GUI* pGUI = pManager->GetGUI();


	GfxInfo SqrGfxInfo;
	SqrGfxInfo.isFilled = false;	//default is not filled
	//get drawing, filling colors and pen width from the interface
	SqrGfxInfo.DrawClr = pGUI->getCrntDrawColor();
	SqrGfxInfo.FillClr = pGUI->getCrntFillColor();
	SqrGfxInfo.BorderWdth = pGUI->getCrntPenWidth();


	//Step 1 - Read Triangle data from the user

	pGUI->PrintMessage("New Triangle: Click at first point");
	//Read 1st point and store in point P1
	pGUI->GetPointClicked(P1.x, P1.y);

	pGUI->PrintMessage("New Triangle: Click at second point");
	//Read 2nd point and store in point P2
	pGUI->GetPointClicked(P2.x, P2.y);

	pGUI->PrintMessage("New Triangle: Click at third point");
	//Read 3rd point and store in point P3
	pGUI->GetPointClicked(P3.x, P3.y);

	pGUI->ClearStatusBar();


	//Step 2 - prepare triangle data

	Point Top=P1;
	Point BotLeft=P2;
	Point BotRight=P3;

	//Step 3 - Create a Triangle with the parameters read from the user
	CTriangle* R = new CTriangle(Top,BotLeft,BotRight,SqrGfxInfo);

	if (P1.y >= UI.ToolBarHeight && P1.y < UI.height - UI.StatusBarHeight && P2.y >= UI.ToolBarHeight && P2.y < UI.height - UI.StatusBarHeight && P3.y >= UI.ToolBarHeight && P3.y < UI.height - UI.StatusBarHeight)
	{

		pManager->AddFigure(R);
	}
	else
	{
		pGUI->PrintMessage("Shape is Out of Drawing Area Boundry");
	}
	//Step 4 - Add the Triangle to the list of figures
}
