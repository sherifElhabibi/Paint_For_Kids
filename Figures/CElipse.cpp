#include "CElipse.h"
#include <cmath>
#include <sstream>
#include<fstream>

int CElipse::elipsecount = 0;
CElipse::CElipse() : CFigure() {
	shapeType = 'e';
}
CElipse::CElipse(Point P1, Point P2, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	firstPoint = P1;
	secondPoint = P2;
	elipsecount++;
	shapeType = 'e';

}


void CElipse::DrawMe(GUI* pGUI) const
{
	pGUI->DrawElipse(firstPoint, secondPoint, FigGfxInfo, Selected);
}

//(x - center.x)^2 / a^2 + (y - center.y)^2 / b^2
bool CElipse::InPoint(int x, int y) {
	Point center;
	center.x = 0.5 * (secondPoint.x + firstPoint.x);
	center.y = 0.5 * (secondPoint.y + firstPoint.y);
	float a = abs(secondPoint.x - firstPoint.x) / 2;
	float b = abs(secondPoint.y - firstPoint.y) / 2;
	float check = (pow(x - center.x, 2) / pow(a, 2)) + (pow(y - center.y, 2) / pow(b, 2));
	if (check <= 1)
	{
		return true;
	}
	return false;
}
void CElipse::PrintMe(GUI* pGUI)
{
	stringstream properties;
	properties << "Second Point: " << "(" << secondPoint.x << "," << secondPoint.y << ")" << "First Point: " << " (" << firstPoint.x << "," << firstPoint.y << ")" << "Area: " << 3.14 * a * b;
	pGUI->PrintMessage(properties.str());
}

void CElipse::Save(ofstream& outputFile)
{
	if (outputFile.is_open())
	{
		/*cout << "here" << endl;*/
		outputFile << "ELLIPSE"
			<< "\t" << ID
			<< "\t" << firstPoint.x
			<< "\t" << firstPoint.y
			<< "\t" << secondPoint.x
			<< "\t" << secondPoint.y
			<< "\t" << ColorToString(this->FigGfxInfo.DrawClr);
		if (!this->FigGfxInfo.isFilled)
			outputFile << "\t" << "NO-FILL";
		else
			outputFile << "\t" << ColorToString(this->FigGfxInfo.FillClr);
		outputFile << "\n";
	}


}

void CElipse::Load(ifstream& inputFile)
{
	string borderColor, fillColor;
	//int borderWidth; //to read the width of each figure's border
	inputFile >> ID >> firstPoint.x >> firstPoint.y >> secondPoint.x >> secondPoint.y;



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


	//inputFile >> this->FigGfxInfo.Resize_Factor;
	Selected = false;
	this->setStored();
}
void CElipse::Resize(float size) {
	this->secondPoint.x = this->secondPoint.x * size;
	this->secondPoint.y = this->secondPoint.y * size;

}


int CElipse::getCount()
{
	return elipsecount;
}