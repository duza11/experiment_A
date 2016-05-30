#pragma once

#include <conio.h>
#include "i_quiz_maker_changer.h"
#include "consoleUtil.h"

class BaseMode
{
public:
	BaseMode(IQuizFloor *changer);
	BaseMode(IQuizFloor *changer, Quiz *quiz);
	virtual ~BaseMode();
	virtual void Finitialize();
	virtual bool Update();
	virtual void Print();

protected:
	IQuizFloor* iqf_;

private:
	int now_select = 0;
};