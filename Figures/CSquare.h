#ifndef CSQUARE_H
#define CSQUARE_H

#include "CFigure.h"

class CSquare : public CFigure
{
private:
	Point TopLeftCorner;	
	int length;
	 static int squarecount;
public:
	CSquare(); 
	CSquare(Point , int, GfxInfo FigureGfxInfo );
	virtual void DrawMe(GUI* pOut) const;
	virtual bool InPoint(int x, int y);
	void PrintMe(GUI* pGUI);
	void Save(ofstream& outputFile);
	void Load(ifstream& inputFile);

	void Resize(float size);
	static int getCount();
};

#endif