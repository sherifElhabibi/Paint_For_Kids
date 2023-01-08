#pragma once
#include "Action.h"
class ActionLoad : public Action
{
private:
	string FileName;
	int force;
public:
	ActionLoad(ApplicationManager* pMan, int _force = 0); // constructor
	//virtual void ReadParameters();
	virtual void Execute();
	virtual void load();
	//string convertToString(color c); //convert from color type to string
	color convertToColor(string s);
};

