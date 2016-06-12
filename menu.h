#pragma once

#include <conio.h>
#include "i_quiz_floor.h"
#include "console_util.h"

class Menu
{
public:
	Menu(IQuizFloor *changer); // ´…‘åŽ÷
	Menu(IQuizFloor *changer, Quiz *quiz); // ´…‘åŽ÷
	virtual ~Menu(); // ´…‘åŽ÷
	virtual void Finitialize(); // ´…‘åŽ÷
	virtual bool Update(); // ´…‘åŽ÷
	virtual void Print(); // ´…‘åŽ÷

protected:
	IQuizFloor* iqf_;

private:
	int now_select_ = 0;
};