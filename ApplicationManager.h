#ifndef APPLICATION_MANAGER_H
#define APPLICATION_MANAGER_H

#include "DEFS.h"
#include "Figures\CFigure.h"


class Action;	//Forward Declaration


//Main class that manages everything in the application.
class ApplicationManager
{
	enum { MaxFigCount = 200 };	//Max no of figures

private:
	int FigCount , selectedFigCount;		//Actual number of figures
	CFigure* SelectedFig;
	CFigure* FigList[MaxFigCount];	//List of all figures (Array of pointers)

	//Pointers to Input and Output classes
	GUI* pGUI;
	

public:	
	ApplicationManager(); 
	~ApplicationManager();

	void Run();		//to run the application
	
	// -- Action-Related Functions
	Action* CreateAction(ActionType);
	void ExecuteAction(Action*&) ; //Execute an action
	
	// -- Figures Management Functions
	void AddFigure(CFigure* pFig); //Adds a new figure to the FigList
	CFigure *GetFigure(int x, int y) const; //Search for a figure given a point inside the figure
	int* getFigCount();
	int getFigCount2();
	CFigure* DrawnFigs(int i) const;
	CFigure** getFigureList();
	CFigure* FigureSelected() const;
	void SaveAll(ofstream& outputfile);
	void deleteALLFig();
		
	int getSelectedFigure();
	CFigure* GetSelectedFigure() const;
	void set_selected(CFigure* fig);
	int getSquareCount(); 
	int getElipseCount();
	int getHexagonCount();
	int getCircleCount();
	int getTriangleCount(); 
	bool isSquare(Point);
	bool isCircle(Point);
	bool isHexagon(Point);
	bool isTriangle(Point);
	bool isElipse(Point);
	// -- Interface Management Functions	
	GUI *GetGUI() const; //Return pointer to the interface
	void UpdateInterface() const;	//Redraws all the drawing window	
	CFigure** getFigList();
	int* getSelectedFigCount();
	void getFiguresColors(int* frequencyColor);
	
};

#endif