#include "CCircle.h"
#include <cmath>
#include <sstream>
#include <fstream>
int CCircle::circlecount = 0;
CCircle::CCircle() : CFigure() {
	shapeType = 'c';
}
CCircle::CCircle(Point _center, int _reduis, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	center = _center;
	reduis = _reduis;
	circlecount++;
	shapeType = 'c';
}


void CCircle::DrawMe(GUI* pGUI) const
{	
	pGUI->DrawCircle(center, reduis, FigGfxInfo, Selected);

}
bool CCircle::InPoint(int x, int y) {
	//(x - center_x)² + (y - center_y)² < radius².
	double dx = pow(x - center.x, 2);
	double dy = pow(y - center.y, 2);

	if (dx + dy < pow(reduis,2))
	{
		return true;
	}
	return false;
	
}
void CCircle::PrintMe(GUI* pGUI)
{
	stringstream properties;
	properties << "Points Center: " << "(" << center.x << "," << center.y << ")" << " Radius: " << reduis << " Area: " << 3.14 * pow(reduis, 2);
	pGUI->PrintMessage(properties.str());
}

void CCircle::Save(ofstream& outputFile)
{
	if (outputFile.is_open())
	{
		/*cout << "here" << endl;*/
		outputFile << "CIRCLE"
			<< "\t" << ID
			<< "\t" << center.x
			<< "\t" << center.y
			<< "\t" << reduis
			<< "\t" << ColorToString(this->FigGfxInfo.DrawClr);
		if (!this->FigGfxInfo.isFilled)
			outputFile << "\t" << "NO-FILL";
		else
			outputFile << "\t" << ColorToString(this->FigGfxInfo.FillClr);
		outputFile << "\n";
	}


}

void CCircle::Load(ifstream& inputFile)
{
	string borderColor, fillColor;
	//int borderWidth; //to read the width of each figure's border
	inputFile >> ID >> center.x >> center.y >>  reduis;



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
void CCircle::Resize(float size) {
	this->reduis = this->reduis * size;
}

int CCircle::getCount()
{
	return circlecount; 
}