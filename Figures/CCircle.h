#ifndef CCIRCLE_H
#define CCIRCLE_H

#include "CFigure.h"

class CCircle : public CFigure
{
private:
	Point center;
	int reduis;
	static int circlecount; 
public:
	CCircle(); 
	CCircle(Point, int, GfxInfo FigureGfxInfo);
	virtual void DrawMe(GUI* pOut) const;
	virtual bool InPoint(int x, int y);
	void PrintMe(GUI* pGUI);
	void Save(ofstream& outputFile);
	void Load(ifstream& inputFile);
	void Resize(float size);
	static int getCount(); 
};


#endif