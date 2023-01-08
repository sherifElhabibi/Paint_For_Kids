#ifndef CFIGURE_H
#define CFIGURE_H

#include "..\defs.h"
#include "..\GUI\GUI.h"

//Base class for all figures
class CFigure
{
protected:
	static int MainID;
	int ID;		//Each figure has an ID
	char shapeType;
	bool Selected;	//true if the figure is selected.
	GfxInfo FigGfxInfo;	//Figure graphis info
	bool isHidden;
	
	/// Add more parameters if needed.
	color storedDraw, storedFill;
	bool IsFilled;

public:
	CFigure();
	CFigure(GfxInfo FigureGfxInfo);
	void SetSelected(bool );	//select/unselect the figure
	bool IsSelected() const;	//check whether fig is selected
	virtual void DrawMe(GUI*) const  = 0 ;		//Draw the figure
	
	void ChngDrawClr(color Dclr);	//changes the figure's drawing color
	void ChngFillClr(color Fclr);	//changes the figure's filling color
	bool isShapeHiddin();
	color GetCurrentFillClr();
	virtual bool InPoint(int x, int y)=0;
	virtual void PrintMe(GUI* pGUI) = 0;
	char getShapeType();
	GfxInfo GetGfxInfo() const;
	///The following functions should be supported by the figure class
	///It should be overridden by each inherited figure

	///Decide the parameters that you should pass to each function	


	//virtual void Rotate() = 0;	//Rotate the figure
	virtual void Resize(float size) = 0;	//Resize the figure
	//virtual void Move() = 0;		//Move the figure
	string ColorToString(color c);
	color StringToColor(string s);
	virtual void Save(ofstream&) = 0; //Save Figure
	void setStored();
	virtual void Load(ifstream &Infile) = 0;	//Load the figure parameters to the file

	//virtual void PrintInfo(Output* pOut) = 0;	//print all figure info on the status bar
};

#endif