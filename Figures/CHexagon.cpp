#include "CHexagon.h"
#include <cmath>
#include<fstream>
#include <sstream>
int CHexagon::hexagoncount = 0;
CHexagon::CHexagon() : CFigure() {
	shapeType = 'h';
}
CHexagon::CHexagon(Point P, int H,int L, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	TopLeft = P;
	Length = L;
	Height = H;
	hexagoncount++; 
	shapeType = 'h';
}


void CHexagon::DrawMe(GUI* pGUI) const
{
	pGUI->DrawHexagon(TopLeft, Height, Length, FigGfxInfo, Selected);
}



bool CHexagon::InPoint(int x, int y)
{
	// if inside inner rectangle
	if (x >= TopLeft.x && x <= TopLeft.x + Length && y >= TopLeft.y && y <= TopLeft.y + Height)
		return true;
	///////////////////////
	float sideTrianglesArea = AreaTriangle(TopLeft.x, TopLeft.y, TopLeft.x, TopLeft.y + Height, TopLeft.x - 0.5 * Length, TopLeft.x + 0.5 * Height);
	// if inside left side triangle
	// left triangle >> (x,y), (x, y+h), (x-0.5l, y+0.5h)
	float Area1 = AreaTriangle(x, y, TopLeft.x, TopLeft.y + Height, TopLeft.x - 0.5 * Length, TopLeft.y + 0.5 * Height);
	float Area2 = AreaTriangle(TopLeft.x, TopLeft.y, x, y, TopLeft.x - 0.5 * Length, TopLeft.y + 0.5 * Height);
	float Area3 = AreaTriangle(TopLeft.x, TopLeft.y, TopLeft.x, TopLeft.y + Height, x, y);
	if (Area1 + Area2 + Area3 == sideTrianglesArea)
		return true;
	// if inside right side triangle
	// right triangle >> (x+l,y), (x+l, y+h), (x+1.5l, y+0.5h)
	Area1 = AreaTriangle(x, y, TopLeft.x + Length, TopLeft.y + Height, TopLeft.x + 1.5 * Length, TopLeft.y + 0.5 * Height);
	Area2 = AreaTriangle(TopLeft.x + Length, TopLeft.y, x, y, TopLeft.x + 1.5 * Length, TopLeft.y + 0.5 * Height);
	Area3 = AreaTriangle(TopLeft.x + Length, TopLeft.y, TopLeft.x + Length, TopLeft.y + Height, x, y);
	if (Area1 + Area2 + Area3 == sideTrianglesArea)
	{
		return true;
	}
	
	return false;
}

float CHexagon::AreaTriangle(float x1, float y1, float x2, float y2, float x3, float y3)
{
	return abs((x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2)) * 0.5);
}
void CHexagon::PrintMe(GUI* pGUI)
{
	stringstream properties;
	properties << "Points: " << "(" << TopLeft.x << "," << TopLeft.y << ")" << "Area: " << 3 * sqrt(3) * pow(Length, 2) / 3;
	pGUI->PrintMessage(properties.str());
}

void CHexagon::Save(ofstream& outputFile)
{
	if (outputFile.is_open())
	{
		/*cout << "here" << endl;*/
		outputFile << "HEXAGON"
			<< "\t" << ID
			<< "\t" << TopLeft.x
			<< "\t" << TopLeft.y
			<< "\t" << Height
			<< "\t" << Length
			<< "\t" << ColorToString(this->FigGfxInfo.DrawClr);
		if (!this->FigGfxInfo.isFilled)
			outputFile << "\t" << "NO-FILL";
		else
			outputFile << "\t" << ColorToString(this->FigGfxInfo.FillClr);
		outputFile << "\n";
	}


}
void CHexagon::Load(ifstream& inputFile)
{
	string borderColor, fillColor;
	//int borderWidth; //to read the width of each figure's border
	inputFile >> ID >> TopLeft.x >> TopLeft.y >>Height>> Length;



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

void CHexagon::Resize(float size) {
	this->Height = this->Height * size;
	this->Length = this->Length * size;
}

int CHexagon::getCount()
{
	return hexagoncount;
}