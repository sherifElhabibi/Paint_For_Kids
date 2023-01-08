#include "CTriangle.h"
#include <cmath>
#include <sstream>
#include <fstream>

int CTriangle::trianglecount = 0;
CTriangle::CTriangle() : CFigure() {
	shapeType = 't';
}
CTriangle::CTriangle(Point P1, Point P2,Point P3, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	Top = P1;
	BotLeft = P2;
	BotRight = P3;
	trianglecount++; 
	shapeType = 't';
}


void CTriangle::DrawMe(GUI* pGUI) const
{
	//Call Output::DrawRect to draw a Square on the screen	
	pGUI->DrawTriangle(Top,BotLeft,BotRight,FigGfxInfo, Selected);


}
bool CTriangle::InPoint(int x, int y)
{

    float Sum = AreaTriangle(Top.x, Top.y, BotLeft.x, BotLeft.y, BotRight.x, BotRight.y); 


     float Area1 = AreaTriangle(x,y, Top.x, Top.y, BotLeft.x, BotLeft.y);

     float Area2 = AreaTriangle(x,y, Top.x, Top.y, BotRight.x, BotRight.y); 

     float Area3 = AreaTriangle(x,y, BotRight.x, BotRight.y, BotLeft.x, BotLeft.y);

	 float sumAreas = Area1 + Area2 + Area3;
	 if (sumAreas == Sum)
		 return true;
	 return false;
     
}

float CTriangle::AreaTriangle(float x1, float y1, float x2, float y2, float x3, float y3)
{
	return abs((x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2)) * 0.5);
}
void CTriangle::PrintMe(GUI* pGUI)
{
	stringstream properties;
	properties << "Top Points: " << "(" << Top.x << "," << Top.y << ")" << "Bot Right Points: " << " (" << BotRight.x << "," << BotRight.y << ")" << "Bot Left Points: " << " (" << BotLeft.x << "," << BotLeft.y << ")" << "Area: " << 0.5 * abs(Top.x * (BotRight.y - BotLeft.y) + BotLeft.x * (BotLeft.y - Top.y) + BotRight.x * (Top.y - BotRight.y));
	pGUI->PrintMessage(properties.str());
}

void CTriangle::Save(ofstream& outputFile)
{
	if (outputFile.is_open())
	{
		/*cout << "here" << endl;*/
		outputFile << "TRIANGLE"
			<< "\t" << ID
			<< "\t" << Top.x
			<< "\t" << Top.y
			<< "\t" << BotLeft.x
			<< "\t" << BotLeft.y
			<< "\t" << BotRight.x
			<< "\t" << BotRight.y
			<< "\t" << ColorToString(this->FigGfxInfo.DrawClr);
		if (!this->FigGfxInfo.isFilled)
			outputFile << "\t" << "NO-FILL";
		else
			outputFile << "\t" << ColorToString(this->FigGfxInfo.FillClr);
		outputFile << "\n";
	}


}

void CTriangle::Load(ifstream& inputFile)
{
	string borderColor, fillColor;
	//int borderWidth; //to read the width of each figure's border
	inputFile >> ID >> Top.x >> Top.y >> BotLeft.x >> BotLeft.y >> BotRight.x >> BotRight.y;



	inputFile >> borderColor;
	this->FigGfxInfo.DrawClr = StringToColor(borderColor);

	inputFile >> fillColor;
	//cout << borderColor<< endl << fillColor << endl;

	if (fillColor == "NO-FILL") {
		//cout << fillColor << endl;
		this->FigGfxInfo.isFilled = false;
	}
	else
	{
		this->FigGfxInfo.isFilled = true;
		this->FigGfxInfo.FillClr = StringToColor(fillColor);
	}
	/*inputFile >> borderWidth;
	this->FigGfxInfo.BorderWdth = borderWidth;*/
	this->FigGfxInfo.BorderWdth = 3;

	//inputFile >> this->FigGfxInfo.Resize_Factor;
	Selected = false;
	this->setStored();
}

void CTriangle::Resize(float size) {
	this->Top.x = this->Top.x * size;
	this->Top.y = this->Top.y * size;

	this->BotLeft.x = this->BotLeft.x * size;
	this->BotLeft.y = this->BotLeft.y * size;

	this->BotRight.x = this->BotRight.x * size;
	this->BotRight.y = this->BotRight.y * size;
}

int CTriangle::getCount()
{
	return trianglecount;
}