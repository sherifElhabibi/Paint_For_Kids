#ifndef UI_INFO_H
#define UI_INFO_H

#include "..\CMUgraphicsLib\CMUgraphics.h"

//User Interface information file.
//This file contains info that is needed by Input and Output classes to
//handle the user interface

enum GUI_MODE	//Graphical user interface mode
{
	MODE_DRAW,	//Drawing mode (startup mode)
	MODE_PLAY,	//Playing mode
	MODE_COLOR,
	MODE_RESIZE
};

enum DrawMenuItem //The items of the Draw menu (you should add more items)
{
	//Note: Items are ordered here as they appear in menu
	//If you want to change the menu items order, change the order here
	ITM_SQUR,		   //Square item in menu
	ITM_ELPS,		  //Ellipse item in menu		 //Rectangle item in menu 
	ITM_TRI,	    //Triangle item in menu
	ITM_HEX,	   //Hexagon item in menu
	ITM_CIRC,	//Circle item in menu	 //Select shape
	ITM_CHANGE_DRAW_COLOR,
	ITM_CHANGE_BK_COLOR,
	ITM_CHANGE_FILL_COLOR,
	ITM_SAVE,
	ITM_LOAD,
	ITM_RESIZE,
	ITM_DEL,
	ITM_PLAY,


	
	
	//TODO: Add more items names here

	ITM_EXIT,		//Exit item
	

	DRAW_ITM_COUNT		//no. of menu items ==> This should be the last line in this enum
	
};

enum ColorMenuItem //The items of the Draw menu (you should add more items)
{
	//Note: Items are ordered here as they appear in menu
	//If you want to change the menu items order, change the order here
	ITM_BLUE,		   //Square item in menu
	ITM_RED,		  //Ellipse item in menu		 //Rectangle item in menu 
	ITM_YELLOW,	    //Triangle item in menu
	ITM_GREEN,	   //Hexagon item in menu
	//ITM_BACK,
	COLOR_ITM_COUNT,	//Circle item in menu	 //Select shape
};

enum ResizeMenuItem
{
	ITM_QUARTER,
	ITM_HALF,
	ITM_DOUBLE,
	ITM_QUADRUPLE,

	ITM_BACK2,

	RESIZE_ITM_COUNT

};
enum PlayMenuItem //The items of the Play menu (you should add more items)
{
	ITM_GAME_ONE,
	ITM_GAME_TWO,
	ITM_GAME_THREE,
	ITM_BACK,
	PLAY_ITM_COUNT		//no. of menu items ==> This should be the last line in this enum
	
};





__declspec(selectany) //This line to prevent "redefinition error"

struct UI_Info	//User Interface Info.
{
	GUI_MODE InterfaceMode;
	
	int	width, height,	//Window width and height
		wx , wy,			//Window starting coordinates
		StatusBarHeight,	//Status Bar Height
		ToolBarHeight,		//Tool Bar Height (distance from top of window to bottom line of toolbar)
		MenuItemWidth;		//Width of each item in toolbar menu
	
	bool IsFilled;
	color DrawColor;		//Drawing color
	color FillColor;		//Filling color
	color HighlightColor;	//Highlighting color
	color MsgColor;			//Messages color
	color BkGrndColor;		//Background color
	color ToolBarBkGrndColor;
	color StatusBarColor;	//Status bar color
	int PenWidth;			//width of the pen that draws shapes

	/// Add more members if needed
	
}UI;	//create a global object UI

#endif