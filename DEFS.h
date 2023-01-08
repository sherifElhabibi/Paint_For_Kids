#ifndef DEFS_H
#define DEFS_H

#include "CMUgraphicsLib\CMUgraphics.h"

//This file contais some global constants and definitions to be used in the project.
enum ActionType //The actions supported (you can add more if needed)
{
	DRAW_SQUARE,	//Draw a Square
	DRAW_ELPS,		//Draw an Ellipse		//Draw a Rectangle
	DRAW_TRI,	    //Draw a Triangle
	DRAW_HEX,	    //Draw a Hexagon
	BLUE_CL,
	RED_CL,
	YELLOW_CL,
	GREEN_CL,
	DRAW_CIRC,	    //Draw a Circle
	SELECTED,			//Select shape
	CHNG_DRAW_CLR,	//Change the drawing color
	CHNG_FILL_CLR,	//Change the filling color
	CHNG_BK_CLR,	//Change background color
	COLOR,
	DEL,			//Delete a figure(s)
	PLAY,
	MOVE,			//Move a figure(s)
	GAME_ONE,
	GAME_TWO,
	GAME_THREE,
	BACK,
	RESIZE,			//Resize a figure(s)
	SEND_TO_BACK,
	ROTATE,			//Rotate a figure(s)
	SEND_BACK,		//Send a figure to the back of all figures
	BRNG_FRNT,		//Bring a figure to the front of all figures
	SAVE,			//Save the whole graph to a file
	LOAD,			//Load a graph from a file
	EXIT,			//Exit the application

	DRAWING_AREA,	//A click on the drawing area
	STATUS,			//A click on the status bar
	EMPTY,			//A click on empty place in the toolbar

	TO_DRAW,		//Switch interface to Draw mode
	TO_PLAY	,		//Switch interface to Play mode

	///TODO: Add more action types (if needed)
	HALF,
	QUARTER,
	DOUBLE1,
	QUADRUPLE,
	BACK2,
	GO_BACK,
	SELECT_TYPE,
	SELECT_FILL,
	SELECT_BOTH,
	DRAW_MODE,
	PLAY_MODE,

};

struct Point	//To be used for figures points
{ int x,y; };

struct GfxInfo	//Graphical info of each figure (you may add more members)
{
	color DrawClr;	//Draw color of the figure
	color FillClr;	//Fill color of the figure
	bool isFilled;	//Figure Filled or not
	int BorderWdth;	//Width of figure borders

};

#endif