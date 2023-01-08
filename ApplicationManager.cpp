#include "ApplicationManager.h"
#include "Actions\ActionAddSquare.h"
#include "Actions\ActionAddTriangle.h"
#include "Actions\ActionAddHexagon.h"
#include "Actions\ActionAddElipse.h"
#include "Actions\ActionAddCircle.h"
#include "Actions\ActionSelect.h"
#include "Actions\ActionSave.h"
#include "Actions\ActionLoad.h"
#include "Actions\ActionChangeDrawColor.h"
#include "Actions\ActionChangeFillColor.h"
#include "Actions\ActionDelete.h"
#include "Actions\ActionResize.h"
#include "Actions\ActionBackToDraw.h"
#include "Actions\ActionSwitchToDrawMode.h"
#include "Actions\ActionPlayMode.h"
#include "Actions\ActionShapesGame.h"
#include "Actions\ActionChangeBKColor.h"
#include "Actions\ActionPlayWithColor.h"
#include "Figures/CSquare.h" 
#include "Figures/CElipse.h" 
#include "Figures/CHexagon.h" 
#include "Figures/CTriangle.h" 
#include "Figures/CCircle.h" 




//Constructor
ApplicationManager::ApplicationManager()
{
	//Create Input and output
	pGUI = new GUI;	
	
	FigCount = 0;
		
	//Create an array of figure pointers and set them to NULL		
	for(int i=0; i<MaxFigCount; i++)
		FigList[i] = NULL;	
}

void ApplicationManager::Run()
{
	ActionType ActType;
	do
	{		
		//1- Read user action
		ActType = pGUI->MapInputToActionType();

		//2- Create the corresponding Action
		Action *pAct = CreateAction(ActType);
		
		//3- Execute the action
		ExecuteAction(pAct);

		//4- Update the interface
		UpdateInterface();	

	}while(ActType != EXIT);
	
}


//==================================================================================//
//								Actions Related Functions							//
//==================================================================================//
//Creates an action
Action* ApplicationManager::CreateAction(ActionType ActType) 
{
	Action* newAct = NULL;
	
	//According to Action Type, create the corresponding action object
	switch (ActType)
	{
		case DRAW_SQUARE:
			newAct = new ActionAddSquare(this);
			break;
		case DRAW_ELPS:
			newAct = new ActionAddElipse(this);
			break;
		case DRAW_TRI:
			newAct = new ActionAddTriangle(this);
			break;
		case DRAW_HEX:
			newAct = new ActionAddHexagon(this);
			break;
		case DRAW_CIRC:
			newAct = new ActionAddCircle(this);
			break;
		case CHNG_DRAW_CLR:
			newAct = new ActionChangeDrawColor(this);
			break;
		case CHNG_FILL_CLR:
			newAct = new ActionChangeFillColor(this);
			break;
		case CHNG_BK_CLR:
			newAct = new ActionChangeBKColor(this);
			break;
		case SELECTED:
			newAct = new ActionSelect(this);
			break;
		case SAVE:
			newAct = new ActionSave(this);
			break;
		case LOAD:
			newAct = new ActionLoad(this);
			break;
		case DEL:
			newAct = new ActionDelete(this);
			break;
		case PLAY:
			newAct = new ActionPlayMode(this);
			break;
		case RESIZE:
			newAct = new ActionResize(this, SelectedFig);
			break;
		case GO_BACK:
			newAct = new ActionSwitchToDrawMode(this);
			break;
		case GAME_ONE:
			newAct = new ActionShapesGame(this);
			break;
		case GAME_TWO:
			newAct = new ActionPlayWithColor(this);
			break;
		case BACK:
			newAct = new ActionBackToDraw(this);
			break;
		case EXIT:
			///create ExitAction here
			
			break;
		
		case STATUS:	//a click on the status bar ==> no action
			return NULL;
			break;
	}	
	return newAct;
}
//////////////////////////////////////////////////////////////////////
//Executes the created Action
void ApplicationManager::ExecuteAction(Action* &pAct) 
{	
	//Execute the created action
	if(pAct != NULL)
	{
		pAct->Execute();//Execute
		delete pAct;	//Action is not needed any more ==> delete it
		pAct = NULL;
	}
}
//==================================================================================//
//						Figures Management Functions								//
//==================================================================================//



//Add a figure to the list of figures
void ApplicationManager::AddFigure(CFigure* pFig)
{
	if(FigCount < MaxFigCount )
		FigList[FigCount++] = pFig;	
}
////////////////////////////////////////////////////////////////////////////////////
CFigure *ApplicationManager::GetFigure(int x, int y) const
{
	//If a figure is found return a pointer to it.
	//if this point (x,y) does not belong to any figure return NULL
	for (int i = FigCount - 1; i >= 0; i--)
	{
		if (FigList[i]->InPoint(x, y))
		{
			return FigList[i];
		}
	}
	return NULL;
}
CFigure* ApplicationManager::FigureSelected() const
{
	//If a figure is found return a pointer to it.
	//if this point (x,y) does not belong to any figure return NULL

	///Add your code here to search for a figure given a point x,y	
	for (int i = FigCount - 1; i >= 0; i--)
		if (FigList[i]->IsSelected())
			return FigList[i];
	return NULL;
}
CFigure** ApplicationManager::getFigureList()
{
	return FigList;
}
int* ApplicationManager::getFigCount() {
	return &FigCount;
};

void ApplicationManager::SaveAll(ofstream& outputfile)
{
	// Figure save Functions Run
	if (outputfile.is_open())
	{
		//outputfile << to_string(FigCount) << "\n";
		for (int i = 0; i < FigCount; i++)
		{
			FigList[i]->Save(outputfile);
		}
	}

}
void ApplicationManager::deleteALLFig()
{
	for (int i = 0; i < FigCount; i++)
		FigList[i] == NULL;
	FigCount = 0;
}

int ApplicationManager::getSelectedFigure() {
	for (int i = 0;i < FigCount;i++) {
		if (FigList[i]->IsSelected()) {
			return i;
		}
	}
	return -1;
}

CFigure* ApplicationManager::GetSelectedFigure() const {
	for (int i = 0; i < FigCount; i++) {
		if (FigList[i]->IsSelected())
			return FigList[i];
	}
	return NULL;
}
void ApplicationManager::set_selected(CFigure* fig)   //set the selcted figure. We need it on copy, cut, paste and delete actions
{
	SelectedFig = fig;
}
int ApplicationManager::getSquareCount()
{
	return CSquare::getCount();
}
int ApplicationManager::getElipseCount()
{
	return CElipse::getCount();
}
int ApplicationManager::getTriangleCount()
{
	return CTriangle::getCount();
}
int ApplicationManager::getCircleCount()
{
	return CCircle::getCount();
}
int ApplicationManager::getHexagonCount()
{
	return CHexagon::getCount();
}

int ApplicationManager::getFigCount2() {
	return FigCount;
};

CFigure* ApplicationManager::DrawnFigs(int i) const
{
	return FigList[i];
}
CFigure** ApplicationManager::getFigList() {
	return FigList;
};

int* ApplicationManager::getSelectedFigCount() {
	return &selectedFigCount;

};

void ApplicationManager::getFiguresColors(int* frequencyColor)
{
	color* colors = new color[FigCount];
	for (int i = 0; i < FigCount; i++)
	{
		colors[i] = FigList[i]->GetCurrentFillClr();
		if ((colors[i].ucBlue == RED.ucBlue) && (colors[i].ucGreen == RED.ucGreen) && (colors[i].ucRed == RED.ucRed))
			frequencyColor[0]++;
		else if ((colors[i].ucBlue == GREEN.ucBlue) && (colors[i].ucGreen == GREEN.ucGreen) && (colors[i].ucRed == GREEN.ucRed))
			frequencyColor[1]++;
		else if ((colors[i].ucBlue == BLUE.ucBlue) && (colors[i].ucGreen == BLUE.ucGreen) && (colors[i].ucRed == BLUE.ucRed))
			frequencyColor[2]++;
		else if ((colors[i].ucBlue == YELLOW.ucBlue) && (colors[i].ucGreen == YELLOW.ucGreen) && (colors[i].ucRed == YELLOW.ucRed))
			frequencyColor[3]++;
		else
			frequencyColor[4]++;
	}
	delete[] colors;
}


/*
bool ApplicationManager::isSquare(Point P1)
{
	CSquare* sq1; 
	pGUI->GetPointClicked(P1.x, P1.y);
	return sq1->InPoint(P1.x, P1.y);
}

bool ApplicationManager::isCircle(Point P1)
{
	CCircle* ci1;
	pGUI->GetPointClicked(P1.x, P1.y);
	return ci1->InPoint(P1.x, P1.y);
}

bool ApplicationManager::isHexagon(Point P1)
{
	isCircle(P1);
	CHexagon* hx1;
	pGUI->GetPointClicked(P1.x, P1.y);
	return hx1->InPoint(P1.x, P1.y);
}
bool ApplicationManager::isElipse(Point P1)
{
	CElipse* el1;
	pGUI->GetPointClicked(P1.x, P1.y);
	return el1->InPoint(P1.x, P1.y);
}
bool ApplicationManager::isTriangle(Point P1)
{
	CTriangle* tr1;
	pGUI->GetPointClicked(P1.x, P1.y);
	return tr1->InPoint(P1.x, P1.y);
}
*/
//==================================================================================//
//							Interface Management Functions							//
//==================================================================================//

//Draw all figures on the user interface
void ApplicationManager::UpdateInterface() const
{	
	for(int i=0; i<FigCount; i++)
		FigList[i]->DrawMe(pGUI);		//Call Draw function (virtual member fn)
}
////////////////////////////////////////////////////////////////////////////////////
//Return a pointer to the interface
GUI *ApplicationManager::GetGUI() const
{	return pGUI; }
////////////////////////////////////////////////////////////////////////////////////
//Destructor
ApplicationManager::~ApplicationManager()
{
	for(int i=0; i<FigCount; i++)
		delete FigList[i];
	delete pGUI;
	
}
