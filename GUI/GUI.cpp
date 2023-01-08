#include "GUI.h"

//constructor make necessary initializations
GUI::GUI()
{
	//Initialize user interface parameters
	UI.InterfaceMode = MODE_DRAW;
	
	UI.width = 1300;
	UI.height = 700;
	UI.wx = 5;
	UI.wy =5;

	
	UI.StatusBarHeight = 50;
	UI.ToolBarHeight = 50;
	UI.MenuItemWidth = 80;
	
	UI.DrawColor = BLUE;	//Drawing color
	UI.FillColor = GREEN;	//Filling color
	UI.MsgColor = RED;		//Messages color
	UI.BkGrndColor = LIGHTGOLDENRODYELLOW;	//Background color
	UI.HighlightColor = MAGENTA;	//This color should NOT be used to draw figures. use if for highlight only
	UI.StatusBarColor = TURQUOISE;
	UI.ToolBarBkGrndColor = WHITE;
	UI.PenWidth = 3;	//width of the figures frames

	
	//Create the output window
	pWind = CreateWind(UI.width, UI.height, UI.wx, UI.wy);
	//Change the title
	pWind->ChangeTitle("Paint for Kids - Programming Techniques Project");
	
	CreateDrawToolBar();
	CreateStatusBar();
	
}


//======================================================================================//
//								Input Functions										    //
//======================================================================================//

bool GUI::getColorIsFilled() const {
	if (UI.IsFilled == true) {
		return UI.IsFilled;
	}
}

void GUI::GetPointClicked(int &x, int &y) const
{
	pWind->WaitMouseClick(x, y);	//Wait for mouse click
}

string GUI::GetSrting() const 
{
	string Label;
	char Key;
	while(1)
	{
		pWind->WaitKeyPress(Key);
		if(Key == 27 )	//ESCAPE key is pressed
			return "";	//returns nothing as user has cancelled label
		if(Key == 13 )	//ENTER key is pressed
			return Label;
		if(Key == 8 )	//BackSpace is pressed
			Label.resize(Label.size() -1 );			
		else
			Label+= Key;
		PrintMessage(Label);
	}
}

//This function reads the position where the user clicks to determine the desired action
ActionType GUI::MapInputToActionType() const
{	
	int x,y;
	pWind->WaitMouseClick(x, y);	//Get the coordinates of the user click

	if(UI.InterfaceMode == MODE_DRAW)	//GUI in the DRAW mode
	{
		//[1] If user clicks on the Toolbar
		if ( y >= 0 && y < UI.ToolBarHeight)
		{	
			//Check whick Menu item was clicked
			//==> This assumes that menu items are lined up horizontally <==
			int ClickedItemOrder = (x / UI.MenuItemWidth);
			//Divide x coord of the point clicked by the menu item width (int division)
			//if division result is 0 ==> first item is clicked, if 1 ==> 2nd item and so on

			switch (ClickedItemOrder)
			{
			case ITM_SQUR: return DRAW_SQUARE;
			case ITM_ELPS: return DRAW_ELPS;
			case ITM_TRI: return DRAW_TRI;
			case ITM_HEX: return DRAW_HEX;
			case ITM_CIRC: return DRAW_CIRC;
			case ITM_CHANGE_DRAW_COLOR: return CHNG_DRAW_CLR;
			case ITM_CHANGE_FILL_COLOR: return CHNG_FILL_CLR;
			case ITM_CHANGE_BK_COLOR: return CHNG_BK_CLR;
			case ITM_SAVE:return SAVE;
			case ITM_LOAD:return LOAD;
			case ITM_RESIZE:return RESIZE;
			case ITM_DEL: return DEL;
			case ITM_PLAY: return PLAY; 
			case ITM_EXIT: return EXIT;	
				
			default: return EMPTY;	//A click on empty place in desgin toolbar
			}
		}

		//[2] User clicks on the drawing area
		if ( y >= UI.ToolBarHeight && y < UI.height - UI.StatusBarHeight)
		{
			return SELECTED;	
		}
		
		//[3] User clicks on the status bar
		return STATUS;
	}	
	else if (UI.InterfaceMode == MODE_RESIZE)
	{
		if (y >= 0 && y < UI.ToolBarHeight) {
			int ClickedItemOrder = (x / UI.MenuItemWidth);
			switch (ClickedItemOrder) {
			case ITM_HALF: return HALF;
			case ITM_QUARTER:return QUARTER;
			case ITM_DOUBLE:return DOUBLE1;
			case ITM_QUADRUPLE:return QUADRUPLE;
			case ITM_BACK2:return BACK2;
			default:return EMPTY;
			}
		}
		if (y >= UI.ToolBarHeight && y < UI.height - UI.StatusBarHeight) {
			return SELECTED;
		}
		else {
			return STATUS;
		}
	}
	else //if(UI.InterfaceMode == MODE_PLAY)	//GUI is in PLAY mode
	{ 
		if (y >= 0 && y < UI.ToolBarHeight) {
			int ClickedItemOrder = (x / UI.MenuItemWidth);
			switch (ClickedItemOrder) {
			case ITM_GAME_ONE: return GAME_ONE;
			case ITM_GAME_TWO:return GAME_TWO;
			case ITM_GAME_THREE:return GAME_THREE;
			case ITM_BACK:return BACK;
			default:return EMPTY;
			}
		}
		if (y >= UI.ToolBarHeight && y < UI.height - UI.StatusBarHeight) {
			return DRAWING_AREA;
		}
		else {
			return STATUS;
		}
	}	

}
//======================================================================================//
//								Output Functions										//
//======================================================================================//

window* GUI::CreateWind(int w, int h, int x, int y) const
{ 
	window* pW = new window(w, h, x, y);
	pW->SetBrush(UI.BkGrndColor);
	pW->SetPen(UI.BkGrndColor, 1);
	pW->DrawRectangle(0, UI.ToolBarHeight, w, h);	
	return pW;
}
//////////////////////////////////////////////////////////////////////////////////////////
void GUI::CreateStatusBar() const
{
	pWind->SetPen(UI.StatusBarColor, 1);
	pWind->SetBrush(UI.StatusBarColor);
	pWind->DrawRectangle(0, UI.height - UI.StatusBarHeight, UI.width, UI.height);
}
//////////////////////////////////////////////////////////////////////////////////////////
void GUI::ClearStatusBar() const
{
	//Clear Status bar by drawing a filled white Square
	pWind->SetPen(UI.StatusBarColor, 1);
	pWind->SetBrush(UI.StatusBarColor);
	pWind->DrawRectangle(0, UI.height - UI.StatusBarHeight, UI.width, UI.height);
}
//////////////////////////////////////////////////////////////////////////////////////////
void GUI::CreateDrawToolBar() const
{
	UI.InterfaceMode = MODE_DRAW;

	//You can draw the tool bar icons in any way you want.
	//Below is one possible way
	
	//First prepare List of images for each menu item
	//To control the order of these images in the menu, 
	//reoder them in UI_Info.h ==> enum DrawMenuItem
	string MenuItemImages[DRAW_ITM_COUNT];
	MenuItemImages[ITM_SQUR] = "images\\MenuItems\\Menu_Sqr.JPG";
	MenuItemImages[ITM_ELPS] = "images\\MenuItems\\Menu_Elps.jpg";
	MenuItemImages[ITM_TRI] = "images\\MenuItems\\Menu_Tri.JPG";
	MenuItemImages[ITM_HEX] = "images\\MenuItems\\Menu_Hexa.JPG";
	MenuItemImages[ITM_CIRC] = "images\\MenuItems\\Menu_Circ.JPG";
	MenuItemImages[ITM_CHANGE_DRAW_COLOR] = "images\\MenuItems\\Menu_Draw.jpg";
	MenuItemImages[ITM_CHANGE_FILL_COLOR] = "images\\MenuItems\\fillcolor.jpg";
	MenuItemImages[ITM_CHANGE_BK_COLOR] = "images\\MenuItems\\bgcolor.jpg";
	MenuItemImages[ITM_SAVE] = "images\\MenuItems\\save.jpg";
	MenuItemImages[ITM_LOAD] = "images\\MenuItems\\load.jpg";
	MenuItemImages[ITM_RESIZE] = "images\\MenuItems\\Resize.jpg";
	MenuItemImages[ITM_DEL] = "images\\MenuItems\\delete.jpg";
	MenuItemImages[ITM_PLAY] = "images\\MenuItems\\play.jpg";
	MenuItemImages[ITM_EXIT] = "images\\MenuItems\\Menu_Exit.jpg";

	//TODO: Prepare images for each menu item and add it to the list

	//Draw menu item one image at a time
	for(int i=0; i<DRAW_ITM_COUNT; i++)
		pWind->DrawImage(MenuItemImages[i], i*UI.MenuItemWidth,0,UI.MenuItemWidth, UI.ToolBarHeight);



	//Draw a line under the toolbar
	pWind->SetPen(RED, 3);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);	

}

void GUI::CreatePlayToolBar() const
{
	UI.InterfaceMode = MODE_PLAY;

	//You can draw the tool bar icons in any way you want.
	//Below is one possible way

	//First prepare List of images for each menu item
	//To control the order of these images in the menu, 
	//reoder them in UI_Info.h ==> enum DrawMenuItem
	string MenuItemImages[PLAY_ITM_COUNT];
	MenuItemImages[ITM_GAME_ONE] = "images\\MenuItems\\shapes.jpg";
	MenuItemImages[ITM_GAME_TWO] = "images\\MenuItems\\shapes_colors.jpg";
	MenuItemImages[ITM_GAME_THREE] = "images\\MenuItems\\shapesss.JPG";
	MenuItemImages[ITM_BACK] = "images\\MenuItems\\back.JPG";
	//TODO: Prepare images for each menu item and add it to the list

	//Draw menu item one image at a time
	for (int i = 0; i < PLAY_ITM_COUNT; i++)
		pWind->DrawImage(MenuItemImages[i], i * UI.MenuItemWidth, 0, UI.MenuItemWidth, UI.ToolBarHeight);



	//Draw a line under the toolbar
	pWind->SetPen(RED, 3);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);

}

void GUI::CreateResizeToolBar() const
{
	UI.InterfaceMode = MODE_RESIZE;

	string MenuItemImages[RESIZE_ITM_COUNT];

	MenuItemImages[ITM_HALF] = "images\\MenuItems\\1.jpg";
	MenuItemImages[ITM_QUARTER] = "images\\MenuItems\\2.jpg";
	MenuItemImages[ITM_DOUBLE] = "images\\MenuItems\\3.jpg";
	MenuItemImages[ITM_QUADRUPLE] = "images\\MenuItems\\4.jpg";
	MenuItemImages[ITM_BACK2] = "images\\MenuItems\\back.jpg";

	for (int i = 0; i < RESIZE_ITM_COUNT;i++) {
		pWind->DrawImage(MenuItemImages[i], i * UI.MenuItemWidth, 0, UI.MenuItemWidth, UI.ToolBarHeight);
	}
	pWind->SetPen(CORNFLOWERBLUE, 3);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);
}

void GUI::CreateColorToolBar() const
{
	UI.InterfaceMode = MODE_COLOR;

	//You can draw the tool bar icons in any way you want.
	//Below is one possible way

	//First prepare List of images for each menu item
	//To control the order of these images in the menu, 
	//reoder them in UI_Info.h ==> enum DrawMenuItem
	string MenuItemImages[COLOR_ITM_COUNT];
	MenuItemImages[ITM_BLUE] = "images\\MenuItems\\Menu_Blue.JPG";
	MenuItemImages[ITM_RED] = "images\\MenuItems\\Menu_Red.jpg";
	MenuItemImages[ITM_YELLOW] = "images\\MenuItems\\Menu_Yellow.JPG";
	MenuItemImages[ITM_GREEN] = "images\\MenuItems\\Menu_Green.JPG";
	//MenuItemImages[ITM_BACK] = "images\\MenuItems\\back.jpg";

	//TODO: Prepare images for each menu item and add it to the list

	//Draw menu item one image at a time
	for (int i = 0; i < COLOR_ITM_COUNT; i++)
		pWind->DrawImage(MenuItemImages[i], i * UI.MenuItemWidth, 0, UI.MenuItemWidth, UI.ToolBarHeight);



	//Draw a line under the toolbar
	pWind->SetPen(RED, 3);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);

}

//////////////////////////////////////////////////////////////////////////////////////////

void GUI::ClearToolBar() const
{
	//clear tool bar by drawing filled white square
	pWind->SetPen(UI.BkGrndColor, 1);
	pWind->SetBrush(UI.ToolBarBkGrndColor);
	pWind->DrawRectangle(0, 0, UI.width, UI.ToolBarHeight);
}

void GUI::ClearDrawArea() const
{
	pWind->SetPen(UI.BkGrndColor, 1);
	pWind->SetBrush(UI.BkGrndColor);
	pWind->DrawRectangle(0, UI.ToolBarHeight, UI.width, UI.height - UI.StatusBarHeight);	
	
}
//////////////////////////////////////////////////////////////////////////////////////////

void GUI::PrintMessage(string msg) const	//Prints a message on status bar
{
	ClearStatusBar();	//First clear the status bar
	
	pWind->SetPen(UI.MsgColor, 50);
	pWind->SetFont(20, BOLD , BY_NAME, "Arial");   
	pWind->DrawString(10, UI.height - (int)(UI.StatusBarHeight/1.5), msg);
}
//////////////////////////////////////////////////////////////////////////////////////////

color GUI::getCrntDrawColor() const	//get current drwawing color
{	return UI.DrawColor;	}
//////////////////////////////////////////////////////////////////////////////////////////

color GUI::getCrntFillColor() const	//get current filling color
{	return UI.FillColor;	}
//////////////////////////////////////////////////////////////////////////////////////////
	
int GUI::getCrntPenWidth() const		//get current pen width
{	return UI.PenWidth;	}

//======================================================================================//
//								Figures Drawing Functions								//
//======================================================================================//

void GUI::DrawSquare(Point P1, int length, GfxInfo RectGfxInfo, bool selected) const
{
	color DrawingClr;
	if(selected)	
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else			
		DrawingClr = RectGfxInfo.DrawClr;
	
	pWind->SetPen(DrawingClr, RectGfxInfo.BorderWdth);	//Set Drawing color & width
	
	drawstyle style;
	if (RectGfxInfo.isFilled)	
	{
		style = FILLED;		
		pWind->SetBrush(RectGfxInfo.FillClr);
	}
	else	
		style = FRAME;

	
	pWind->DrawRectangle(P1.x, P1.y, P1.x +length, P1.y+length, style);

}



//////////////////////////////////////////////////////////////////////////////////////////

void GUI::DrawTriangle(Point P1, Point P2, Point P3, GfxInfo RectGfxInfo, bool selected) const
{
	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else
		DrawingClr = RectGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, RectGfxInfo.BorderWdth);	//Set Drawing color & width

	drawstyle style;
	if (RectGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(RectGfxInfo.FillClr);
	}
	else
		style = FRAME;


	pWind->DrawTriangle(P1.x, P1.y, P2.x, P2.y, P3.x, P3.y, style);
}

//////////////////////////////////////////////////////////////////////////////////////////
void GUI::DrawHexagon(Point TopLeft, int L, int H, GfxInfo RectGfxInfo, bool selected) const
{
	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else
		DrawingClr = RectGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, RectGfxInfo.BorderWdth);	//Set Drawing color & width

	drawstyle style;
	if (RectGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(RectGfxInfo.FillClr);
	}
	else
		style = FRAME;
	//2.4- Calculate array of points :
	int px1 = TopLeft.x, px2 = TopLeft.x +L, px3 = TopLeft.x + 1.5*L, px4 = TopLeft.x +L, px5 = px1, px6 = TopLeft.x - (0.5 * L);
	int py1 = TopLeft.y, py2 = py1, py3 = TopLeft.y + 0.5*H, py4 = TopLeft.y + H, py5 = py4, py6 = TopLeft.y + 0.5*H;
	int hX[6] = { px1,px2,px3,px4,px5,px6 };
	int hY[6] = { py1,py2,py3,py4,py5,py6 };
	pWind->DrawPolygon(hX, hY, 6, style);
}
//////////////////////////////////////////////////////////////////////////////////////////
void GUI::DrawCircle(Point center, int reduis, GfxInfo RectGfxInfo, bool selected) const
{
	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else
		DrawingClr = RectGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, RectGfxInfo.BorderWdth);	//Set Drawing color & width

	drawstyle style;
	if (RectGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(RectGfxInfo.FillClr);
	}
	else
		style = FRAME;


	pWind->DrawCircle(center.x, center.y, reduis, style);

}
//////////////////////////////////////////////////////////////////////////////////////////
void GUI::DrawElipse(Point P1, Point P2, GfxInfo RectGfxInfo, bool selected) const
{
	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else
		DrawingClr = RectGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, RectGfxInfo.BorderWdth);	//Set Drawing color & width

	drawstyle style;
	if (RectGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(RectGfxInfo.FillClr);
	}
	else
		style = FRAME;

	pWind->DrawEllipse(P1.x, P1.y, P2.x, P2.y, style);
}
//////////////////////////////////////////////////////////////////////////////////////////

GUI::~GUI()
{
	delete pWind;
}

