
#include "ActionPlayWithColor.h"
#include "..\CMUgraphicsLib\colors.cpp" 
#include "..\ApplicationManager.h"
#include <iostream>
using namespace std;
ActionPlayWithColor::ActionPlayWithColor(ApplicationManager* pApp) : Action(pApp)
{
	wrongColor = 0;
	rightColor = 0;
	ColorsNumber = 0;
	for (int i = 0; i < 5; i++)
	{
		ColorsList[i] = 0;
	}

};
color ActionPlayWithColor::AssignColor(CFigure* Fig)
{
	if (Fig->GetGfxInfo().FillClr == RED)
		return RED;
	else if (Fig->GetGfxInfo().FillClr == BLUE)
		return BLUE;
	else if (Fig->GetGfxInfo().FillClr == GREEN)
		return GREEN;
	else if (Fig->GetGfxInfo().FillClr == YELLOW)
		return YELLOW;

}
void ActionPlayWithColor::PrintScore(int score)
{
	GUI* pGUI = pManager->GetGUI();
	string message;

	if (score == 1)
	{
		rightColor++;
		message = "Right!, Your score is: " + to_string(rightColor) + " Right, and " + to_string(wrongColor) + " Wrong.";

	}
	else if (score == 2)
	{
		wrongColor++;
		message = "Wrong!, Your score is: " + to_string(rightColor) + " Right, and " + to_string(wrongColor) + " Wrong.";
	}
	else if (pickedColorNumber == 0 && rightColor > wrongColor)
	{
		message = "Congratulation, YOU WIN!, Your score is: " + to_string(rightColor) + " Right, and " + to_string(wrongColor) + " Wrong.";
	}
	else
		message = "Oops, YOU LOSE!, Your score is: " + to_string(rightColor) + " Right, and " + to_string(wrongColor) + " Wrong.";


	//pickedColorNumber
	pGUI->PrintMessage(message);
}
void ActionPlayWithColor::ReadActionParameters()
{
	for (int i = 0; i < pManager->getFigCount2(); i++)
	{
		Fig = pManager->DrawnFigs(i);
		if (Fig->GetGfxInfo().isFilled)
		{
			color fill = Fig->GetCurrentFillClr();
			cout << "Fill color is " << Fig->ColorToString(fill) << endl;
			if ((fill.ucBlue == GREEN.ucBlue) && (fill.ucGreen == GREEN.ucGreen) && (fill.ucRed == GREEN.ucRed))
				ColorsList[0]++;
			else if ((fill.ucBlue == BLUE.ucBlue) && (fill.ucGreen == BLUE.ucGreen) && (fill.ucRed == BLUE.ucRed))
				ColorsList[1]++;
			else if ((fill.ucBlue == RED.ucBlue) && (fill.ucGreen == RED.ucGreen) && (fill.ucRed == RED.ucRed))
				ColorsList[2]++;
			else if ((fill.ucBlue == YELLOW.ucBlue) && (fill.ucGreen == YELLOW.ucGreen) && (fill.ucRed == YELLOW.ucRed))
				ColorsList[3]++;
		}
		else {
			ColorsList[4]++;
		}
			
	}

	for (int i = 0; i < 5; i++)
		if (ColorsList[i] != 0) ColorsNumber++;
}
void ActionPlayWithColor::Execute()
{
	CFigure* clickedFig;
	GUI* pGUI = pManager->GetGUI();
	ReadActionParameters();
	if (ColorsNumber > 1)
	{
		randomFigNumber = rand() % pManager->getFigCount2();
		Fig = pManager->DrawnFigs(randomFigNumber);
		if (Fig->GetGfxInfo().isFilled)
		{
			if (Fig->GetGfxInfo().FillClr == GREEN)
			{
				pickedColorNumber = ColorsList[0];
				pGUI->PrintMessage("Pick GREEN Shapes");
			}
			else if (Fig->GetGfxInfo().FillClr == BLUE)
			{
				pickedColorNumber = ColorsList[1];
				pGUI->PrintMessage("Pick BLUE Shapes");
			}
			else if (Fig->GetGfxInfo().FillClr == RED)
			{
				pickedColorNumber = ColorsList[2];
				pGUI->PrintMessage("Pick RED Shapes");
			}
			else if (Fig->GetGfxInfo().FillClr == YELLOW)
			{
				pickedColorNumber = ColorsList[3];
				pGUI->PrintMessage("Pick YELLOW Shapes");
			}

		}
		else {
			pickedColorNumber = ColorsList[4];
			pGUI->PrintMessage("Pick Shapes which are not filled");

		}


		while (pickedColorNumber > 0)
		{
			pGUI->GetPointClicked(P.x, P.y);
			if (P.y > UI.ToolBarHeight || P.x > (UI.MenuItemWidth * PLAY_ITM_COUNT))
			{
				clickedFig = pManager->GetFigure(P.x, P.y);
				if (clickedFig != NULL)
				{
					if (!(Fig->GetGfxInfo().isFilled) && !(clickedFig->GetGfxInfo().isFilled))
					{
						PrintScore(1);
						clickedFig->ChngDrawClr(LIGHTGOLDENRODYELLOW);
						//clickedFig->Hide();
						pManager->UpdateInterface();
						pickedColorNumber--;
					}
					else if ((clickedFig->GetGfxInfo().isFilled && Fig->GetGfxInfo().isFilled) && clickedFig->GetGfxInfo().FillClr == AssignColor(Fig))
					{
						PrintScore(1);
						clickedFig->ChngDrawClr(LIGHTGOLDENRODYELLOW);
						//clickedFig->Hide();
						pManager->UpdateInterface();
						pickedColorNumber--;
					}
					else {
						PrintScore(2);
						clickedFig->ChngDrawClr(LIGHTGOLDENRODYELLOW);
						//clickedFig->Hide();
						pManager->UpdateInterface();
					}
				}
			}
			else
			{
				pGUI->PrintMessage("Toolbar clicked, game aborted.");
				pickedColorNumber = -1;
			}
			if (pickedColorNumber == 0)
				PrintScore(3);
		}
	}
	else
	{
		pGUI->PrintMessage("You must have at least two or more figures to play to play pick by figure!");
	}
	/*for (int i = 0; i < pManager->getFigCount2(); i++)
		pManager->DrawnFigs(i)->Show();
	pManager->UpdateInterface();*/
};