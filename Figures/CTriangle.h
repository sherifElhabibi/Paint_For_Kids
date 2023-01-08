#ifndef CTRIANGLE_H
#define CTRIANGLE_H

#include "CFigure.h"

class CTriangle : public CFigure
{
private:
	Point Top,BotLeft,BotRight;
	 static int trianglecount;
public:
	CTriangle(); 
	CTriangle(Point P1,Point P2,Point P3, GfxInfo FigureGfxInfo);
	virtual void DrawMe(GUI* pOut) const;
	virtual bool InPoint(int x, int y);
	float AreaTriangle(float, float, float, float, float, float);
	void PrintMe(GUI* pGUI);
	void Resize(float size);
	static int getCount();
	void Save(ofstream& outputFile);
	void Load(ifstream& inputFile);

};

#endif