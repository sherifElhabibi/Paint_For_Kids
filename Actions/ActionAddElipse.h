#ifndef ACTION_ADD_ELIPSE_H
#define ACTION_ADD_ELIPSE_H

#include "Action.h"
class ActionAddElipse : public Action
{
public:
	ActionAddElipse(ApplicationManager* pApp);

	virtual void Execute();
};
#endif