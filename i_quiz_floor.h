#pragma once

#include "common.h"

typedef enum
{
	kAnswerMenu,
	kItemMenu,

	kMenuNum,

	kBaseMenu,

	kNoneMenu,
} MenuEnum;

class IQuizFloor
{
public:
	virtual ~IQuizFloor() = 0;
	virtual void SwitchMenu(MenuEnum next_mode) = 0;
	virtual void CheckAnswer(Quiz &quiz, int option_num) = 0;

private:

};