#ifndef ACTION_SHAPES_GAME_H
#define ACTION_SHAPES_GAME_H

#include "Action.h"
class ActionShapesGame : public Action
{
public:
	ActionShapesGame(ApplicationManager* pApp);

	virtual void Execute();
};
#endif