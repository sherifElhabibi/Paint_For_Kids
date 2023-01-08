#include "ActionShapesGame.h"

#include "..\ApplicationManager.h"

#include "..\GUI\GUI.h"

ActionShapesGame::ActionShapesGame(ApplicationManager* pApp) :Action(pApp)
{}

//Execute the action
void ActionShapesGame::Execute()
{
	Point P1;
	GUI* pGUI = pManager->GetGUI();

	CFigure** FigsList = pManager->getFigureList();
	int* figcount = pManager->getFigCount();
	int squarecount = pManager->getSquareCount();
	int elipsecount = pManager->getElipseCount();
	int hexagoncount = pManager->getHexagonCount();
	int circlecount = pManager->getCircleCount();
	int trianglecount = pManager->getTriangleCount();
	int shapearray[] = { squarecount,elipsecount,hexagoncount,circlecount,trianglecount };
	int random;


	for (int i = 0; i < *figcount; i++)
	{
		FigsList[i]->ChngDrawClr(BLUE);

	}
	pManager->UpdateInterface();

	if (*figcount)
	{
		do
		{
			random = rand() % 5;
		} while (shapearray[random] == 0);
		if (random == 0)
		{
			int right = 0;
			string result;
			pGUI->PrintMessage("pick square shapes");
			for (int i = 0; i < squarecount; i++)
			{
				pGUI->GetPointClicked(P1.x, P1.y);
				CFigure* fig = pManager->GetFigure(P1.x, P1.y);

				if (fig->getShapeType() == 's')
				{
					right++;
					pGUI->PrintMessage("right shape");
					fig->ChngDrawClr(LIGHTGOLDENRODYELLOW);
					pManager->UpdateInterface(); 
				}
				else
				{
					pGUI->PrintMessage("wrong shape");
				}
			}
			result = "You choose " + to_string(right) + " right answers from " + to_string(squarecount);
			pGUI->PrintMessage(result);
			right = 0;
		}
		
		else if (random == 1)
		{
			int right = 0;
			string result;
			pGUI->PrintMessage("pick elipse shapes");
			for (int i = 0; i < elipsecount; i++)
			{
				pGUI->GetPointClicked(P1.x, P1.y);
				CFigure* fig = pManager->GetFigure(P1.x, P1.y);
				if (fig->getShapeType() == 'e')
				{
					right++;
					pGUI->PrintMessage("right shape");
					fig->ChngDrawClr(LIGHTGOLDENRODYELLOW);
					pManager->UpdateInterface();
				}
				else
				{
					pGUI->PrintMessage("wrong shape");
				}
			}
			result = "You choose " + to_string(right) + " right answers from " + to_string(elipsecount);
			pGUI->PrintMessage(result);
			right = 0;
		}
		else if (random == 2)
		{
			int right = 0;
			string result;
			pGUI->PrintMessage("pick hexagon shapes");
			for (int i = 0; i < hexagoncount; i++)
			{
				pGUI->GetPointClicked(P1.x, P1.y);
				CFigure* fig = pManager->GetFigure(P1.x, P1.y);
				if (fig->getShapeType() == 'h')
				{
					right++;
					pGUI->PrintMessage("right shape");
					fig->ChngDrawClr(LIGHTGOLDENRODYELLOW);
					pManager->UpdateInterface();
				}
				else
				{
					pGUI->PrintMessage("wrong shape");
				}
			}
			result = "You choose " + to_string(right) + " right answers from " + to_string(hexagoncount);
			pGUI->PrintMessage(result);
			right = 0;
		}
		else if (random == 3)
		{
			int right = 0;
			string result;
			pGUI->PrintMessage("pick circle shapes");
			for (int i = 0; i < circlecount; i++)
			{
				pGUI->GetPointClicked(P1.x, P1.y);
				CFigure* fig = pManager->GetFigure(P1.x, P1.y);
				if (fig->getShapeType() == 'c')
				{
					right++;
					pGUI->PrintMessage("right shape");
					fig->ChngDrawClr(LIGHTGOLDENRODYELLOW);
					pManager->UpdateInterface();
				}
				else
				{
					pGUI->PrintMessage("wrong shape");
				}
			}
			result = "You choose " + to_string(right) + " right answers from " + to_string(circlecount);
			pGUI->PrintMessage(result);
			right = 0;
		}
		else
		{
			int right = 0;
			string result;
			pGUI->PrintMessage("pick triangle shapes");
			for (int i = 0; i < trianglecount; i++)
			{
				pGUI->GetPointClicked(P1.x, P1.y);
				CFigure* fig = pManager->GetFigure(P1.x, P1.y);;
				if (fig->getShapeType() == 't')
				{
					right++;
					pGUI->PrintMessage("right shape");
					fig->ChngDrawClr(LIGHTGOLDENRODYELLOW);
					pManager->UpdateInterface();
				}
				else
				{
					pGUI->PrintMessage("wrong shape");
				}
			}
			result = "You choose " + to_string(right) + " right answers from " + to_string(trianglecount);
			pGUI->PrintMessage(result);
			right = 0;
		}

	}
		else
		{
			pGUI->PrintMessage("please draw any shape before play");
		}

	}



