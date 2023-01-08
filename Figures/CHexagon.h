#ifndef CHEXAGON_H
#define CHEXAGON_H

#include "CFigure.h"

class CHexagon : public CFigure
{
private:
	Point TopLeft;
	int Height, Length;
	 static int hexagoncount;
public:
	CHexagon();
	CHexagon(Point P, int H,int L, GfxInfo FigureGfxInfo);
	virtual bool InPoint(int x, int y);
	float AreaTriangle(float, float, float, float, float, float);
	virtual void DrawMe(GUI* pOut) const;
	void PrintMe(GUI* pGUI);
	void Save(ofstream& outputFile);
	void Load(ifstream& inputFile);
	void Resize(float size);
	 static int getCount();

};

#endif