#include "ActionDelete.h"

#include "..\ApplicationManager.h"

#include "..\GUI\GUI.h"

ActionDelete::ActionDelete(ApplicationManager* pApp) :Action(pApp)
{}

//Execute the action
void ActionDelete::Execute()
{
	//Get a Pointer to the Interface
	GUI* pGUI = pManager->GetGUI();


	/*
		CFigure** figlist = pManager->getFigureList();
		int figcount = pManager->getFigureCount();
		int figSelectFlag = 0;
		for (int i = 0; i <figcount; i++)
		{
			//figlist[i] = pManager->FigureSelected();
			if (figlist[i]->IsSelected())
			{
				delete figlist[i];
				pManager->setFigureCount(figcount--);
				figcount--;
				for (int j = i; j < figcount; j++)
				{
					 figlist[j]= figlist[j + 1];

				}
				i--;
			}
		}
		if (figSelectFlag == 1) {
			if (UI.InterfaceMode == MODE_DRAW)
				pGUI->PrintMessage("Figure Deleted");
			pGUI->ClearDrawArea();
			pManager->UpdateInterface();
		}
		*/


	int* Figs = pManager->getFigCount();
	CFigure** FigsList = pManager->getFigureList();
	int figSelectFlag = 0;
	for (int i = 0; i < *Figs; i++) {
		if (FigsList[i]->IsSelected())
		{
			delete FigsList[i];
			*Figs = *Figs - 1;
			figSelectFlag = 1;
			for (int j = i; j < *Figs; j++) {
				FigsList[j] = FigsList[j + 1];
			}
			i--;
		}
	}
	if (figSelectFlag == 1) {
		if (UI.InterfaceMode == MODE_DRAW)
			pGUI->PrintMessage("Figure Deleted");
		pGUI->ClearDrawArea();
		pManager->UpdateInterface();
	}
	pGUI->ClearStatusBar();
}
