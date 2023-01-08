#include<iostream>
#include "Action.h"
#include"ActionSave.h"
#include"..\GUI\GUI.h"
#include"..\ApplicationManager.h"


ActionSave::ActionSave(ApplicationManager* pApp, int _force) :Action(pApp)
{
	force = _force;
}

void ActionSave::Execute()
{
	int* nums = pManager->getFigCount();
	if (force == 0)
		ReadParameters();
	else
		filename = "saver";

	GUI* pGui = pManager->GetGUI();
	ofstream outputfile((filename + ".txt"));
	if (outputfile.is_open())
	{
		outputfile << ColorToString(UI.DrawColor)
			<< "\t" << ColorToString(UI.FillColor)
			<< "\t" << ColorToString(UI.BkGrndColor)
			<< "\n"
			<< *nums
			<< "\n";

		pManager->SaveAll(outputfile);

		pGui->PrintMessage("Graph Saved successfully :)");

		outputfile.close();
	}



}




void ActionSave::ReadParameters()
{
	GUI* Pgui = pManager->GetGUI();

	while (true)
	{
		Pgui->PrintMessage("Enter the file name you want to save :)");
		filename = Pgui->GetSrting();
		if (filename != "")
		{
			break;
		}
	}

}
string ActionSave::ColorToString(color c) {

	if ((c.ucBlue == BLACK.ucBlue) && (c.ucGreen == BLACK.ucGreen) && (c.ucRed == BLACK.ucRed))
		return "BLACK";
	if ((c.ucBlue == BLUE.ucBlue) && (c.ucGreen == BLUE.ucGreen) && (c.ucRed == BLUE.ucRed))
		return "BLUE";
	if ((c.ucBlue == WHITE.ucBlue) && (c.ucGreen == WHITE.ucGreen) && (c.ucRed == WHITE.ucRed))
		return "WHITE";
	if ((c.ucBlue == RED.ucBlue) && (c.ucGreen == RED.ucGreen) && (c.ucRed == RED.ucRed))
		return "RED";
	if ((c.ucBlue == YELLOW.ucBlue) && (c.ucGreen == YELLOW.ucGreen) && (c.ucRed == YELLOW.ucRed))
		return "YELLOW";
	if ((c.ucBlue == GREEN.ucBlue) && (c.ucGreen == GREEN.ucGreen) && (c.ucRed == GREEN.ucRed))
		return "GREEN";
	if ((c.ucBlue == LIGHTGOLDENRODYELLOW.ucBlue) && (c.ucGreen == LIGHTGOLDENRODYELLOW.ucGreen) && (c.ucRed == LIGHTGOLDENRODYELLOW.ucRed))
		return "LIGHTGOLDENRODYELLOW";
	if ((c.ucBlue == MAGENTA.ucBlue) && (c.ucGreen == MAGENTA.ucGreen) && (c.ucRed == MAGENTA.ucRed))
		return "MAGENTA";
	if ((c.ucBlue == TURQUOISE.ucBlue) && (c.ucGreen == TURQUOISE.ucGreen) && (c.ucRed == TURQUOISE.ucRed))
		return "TURQUOISE";
	if ((c.ucBlue == SKYBLUE.ucBlue) && (c.ucGreen == SKYBLUE.ucGreen) && (c.ucRed == SKYBLUE.ucRed))
		return "SKYBLUE";
	if ((c.ucBlue == LIGHTSTEELBLUE.ucBlue) && (c.ucGreen == LIGHTSTEELBLUE.ucGreen) && (c.ucRed == LIGHTSTEELBLUE.ucRed))
		return "LIGHTSTEELBLUE";
	if ((c.ucBlue == IVORY.ucBlue) && (c.ucGreen == IVORY.ucGreen) && (c.ucRed == IVORY.ucRed))
		return"IVORY";
	if ((c.ucBlue == HONEYDEW.ucBlue) && (c.ucGreen == HONEYDEW.ucGreen) && (c.ucRed == HONEYDEW.ucRed))
		return"HONEYDEW";
	return "NO-FILL";
}