#include "ActionPlayMode.h"

#include "..\ApplicationManager.h"

#include "..\GUI\GUI.h"

ActionPlayMode::ActionPlayMode(ApplicationManager* pApp) :Action(pApp)
{}

//Execute the action
void ActionPlayMode::Execute()
{
	GUI* pGUI = pManager->GetGUI();
	pGUI->ClearToolBar(); 
	pGUI->CreatePlayToolBar(); 
	pGUI->ClearStatusBar();
}
