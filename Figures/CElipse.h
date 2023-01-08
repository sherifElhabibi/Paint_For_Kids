#ifndef CELIPSE_H
#define CELIPSE_H

#include "CFigure.h"

class CElipse : public CFigure
{
private:
	Point firstPoint;
	Point secondPoint;
	Point Center;
	int a, b;
	static int elipsecount; 

public:
	CElipse(); 
	CElipse(Point, Point, GfxInfo FigureGfxInfo);
	virtual void DrawMe(GUI* pOut) const;
	virtual bool InPoint(int x, int y);
	void PrintMe(GUI* pGUI);
	void Resize(float size);
	static int getCount();
	void Save(ofstream& outputFile);
	void Load(ifstream& inputFile);
};

#endif