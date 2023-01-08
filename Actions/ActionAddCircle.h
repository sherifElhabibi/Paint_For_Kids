#ifndef ACTION_ADD_CIRCLE_H
#define ACTION_ADD_CIRCLE_H

#include "Action.h"

//Add Square Action class
class ActionAddCircle : public Action
{
public:
	ActionAddCircle(ApplicationManager* pApp);

	virtual void Execute();
};

#endif