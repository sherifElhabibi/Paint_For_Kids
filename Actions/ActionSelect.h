#ifndef ACTION_SELECT_H
#define ACTION_SELECT_H

#include "Action.h"
class ActionSelect : public Action
{
public:
	ActionSelect(ApplicationManager* pApp);

	virtual void Execute();
};
#endif