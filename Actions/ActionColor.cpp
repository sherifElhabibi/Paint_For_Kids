#include "ActionColor.h"

#include "..\ApplicationManager.h"

#include "..\GUI\GUI.h"

ActionColor::ActionColor(ApplicationManager* pApp) :Action(pApp)
{}

//Execute the action
void ActionColor::Execute()
{
	ActionType colorF; 
	GUI* pGUI = pManager->GetGUI();
	colorF= pGUI->MapInputToActionType();
	CFigure** FigsList = pManager->getFigureList();
	int* figcount = pManager->getFigCount();
				for (int i = *figcount - 1; i >= 0; i--)
				{
					if (FigsList[i]->IsSelected())
					{
						switch (colorF)
						{
						case BLUE_CL :
							FigsList[i]->SetSelected(false);
							FigsList[i]->ChngDrawClr(BLUE);
							break;
						case RED_CL:
							FigsList[i]->SetSelected(false);
							FigsList[i]->ChngDrawClr(RED);
							break;
						case YELLOW_CL:
							FigsList[i]->SetSelected(false);
							FigsList[i]->ChngDrawClr(YELLOW);
							break;
						case GREEN_CL:
							FigsList[i]->SetSelected(false);
							FigsList[i]->ChngDrawClr(GREEN);
							break;
						}
					}
				}
	pGUI->ClearStatusBar();
}
