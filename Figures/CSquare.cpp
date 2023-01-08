#include "CSquare.h"
#include <cmath>
#include <fstream>
#include <sstream>
int CSquare::squarecount = 0;
CSquare::CSquare() : CFigure() {
	shapeType = 's';
}
CSquare::CSquare(Point P1, int len, GfxInfo FigureGfxInfo):CFigure(FigureGfxInfo)
{
	TopLeftCorner = P1;
	length = len;
	squarecount++;
	shapeType = 's';
}
	

void CSquare::DrawMe(GUI* pGUI) const
{
	//Call Output::DrawRect to draw a Square on the screen	
	pGUI->DrawSquare(TopLeftCorner, length, FigGfxInfo, Selected);
	
}
bool CSquare::InPoint(int x, int y) {

	//Checks if the x & y coordinates lie inside/on the rectangle
	if (x >= TopLeftCorner.x && x <= TopLeftCorner.x + length &&
		y >= TopLeftCorner.y && TopLeftCorner.y + length)
		return true;
	return false;
}


void CSquare::PrintMe(GUI* pGUI)
{
	stringstream properties;
	properties << "Points:" << " (" << TopLeftCorner.x << "," << TopLeftCorner.y << ") " << "Area: " << pow(length, 2) / 2;
	pGUI->PrintMessage(properties.str());
}

void CSquare::Save(ofstream& outputFile)
{
	if (outputFile.is_open())
	{
		outputFile << "SQUARE"
			<< "\t" << ID
			<< "\t" << TopLeftCorner.x
			<< "\t" << TopLeftCorner.y
			<< "\t" << length
			<< "\t" << ColorToString(this->FigGfxInfo.DrawClr);
		if (!this->FigGfxInfo.isFilled)
			outputFile << "\t" << "NO-FILL";
		else
			outputFile << "\t" << ColorToString(this->FigGfxInfo.FillClr);
		outputFile << "\n";
	}


}

void CSquare::Load(ifstream& inputFile) {
	string borderColor, fillColor;
	//int borderWidth; //to read the width of each figure's border
	inputFile >> ID >> TopLeftCorner.x >> TopLeftCorner.y >> length;



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
void CSquare::Resize(float size) {
	this->length = this->length * size;
}

int CSquare::getCount()
{
	return squarecount;
}