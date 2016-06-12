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
	virtual ~IQuizFloor() = 0; // ´…‘åŽ÷
	virtual void SwitchMenu(MenuEnum next_mode) = 0; // ´…‘åŽ÷
	virtual void CheckAnswer(int option_num) = 0; // ´…‘åŽ÷
	virtual void set_message(string message) = 0; // ´…‘åŽ÷

private:

};