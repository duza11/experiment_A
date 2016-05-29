#pragma once

#include "quiz_floor.h"

typedef enum
{
	kBaseMenu,
	kAnswerMenu,
	kItemMenu,

	kNoneMenu,
} MenuEnum;

class IQuizFloor
{
public:
	virtual ~IQuizFloor() = 0;
	virtual void SwitchMenu(MenuEnum next_mode) = 0;
	virtual void CheckAnswer(bool answer_type) = 0;

private:

};