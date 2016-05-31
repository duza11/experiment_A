#pragma once

#include <conio.h>
#include "i_quiz_floor.h"
#include "console_util.h"

class Menu
{
public:
	Menu(IQuizFloor *changer);
	Menu(IQuizFloor *changer, Quiz *quiz);
	virtual ~Menu();
	virtual void Finitialize();
	virtual bool Update();
	virtual void Print();

protected:
	IQuizFloor* iqf_;

private:
	int now_select_ = 0;
};