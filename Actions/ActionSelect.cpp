#include "ActionSelect.h"

#include "..\ApplicationManager.h"

#include "..\GUI\GUI.h"

ActionSelect::ActionSelect(ApplicationManager* pApp) :Action(pApp)
{}

//Execute the action
void ActionSelect::Execute()
{
	Point P1;
	GUI* pGUI = pManager->GetGUI();
	pGUI->PrintMessage("Click again");

	pGUI->GetPointClicked(P1.x, P1.y);

	CFigure* fig = pManager->GetFigure(P1.x, P1.y);
	
	if (fig != NULL)
	{
		if (!fig->IsSelected())
		{
			fig->SetSelected(true);
			fig->PrintMe(pGUI);
		}
		else
		{
			fig->SetSelected(false);
		}

	}
}