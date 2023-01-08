#ifndef ACTION_BACK_TO_DRAW_H
#define ACTION_BACK_TO_DRAW_H

#include "Action.h"
class ActionBackToDraw : public Action
{
public:
	ActionBackToDraw(ApplicationManager* pApp);

	virtual void Execute();
};
#endif