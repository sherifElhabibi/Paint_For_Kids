#pragma once
#pragma once
#include "..\Figures\CFigure.h"
#include "Action.h"


class ActionPlayWithColor :public Action {
	CFigure* Fig;
	Point P;
	int ColorsNumber, pickedColorNumber, wrongColor,rightColor, randomFigNumber;
	int ColorsList[5];
	color AssignColor(CFigure*);
	void PrintScore(int);

public:
	ActionPlayWithColor(ApplicationManager*);
	void ReadActionParameters();
	void Execute();
};