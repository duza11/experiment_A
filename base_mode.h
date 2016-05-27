#pragma once

#include <conio.h>
#include "i_quiz_maker_changer.h"
#include "consoleUtil.h"
#include "quiz.h"

class BaseMode
{
public:
	BaseMode(IQuizMakerChanger* changer);
	BaseMode(IQuizMakerChanger* changer, Quiz* q);
	virtual ~BaseMode();
	virtual void init();
	virtual void finit();
	virtual bool update();
	virtual void print();

protected:
	IQuizMakerChanger* m_qm_changer;

private:
	int now_select = 0;
};