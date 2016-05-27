#pragma once

typedef enum
{
	eMode_Menu,
	eMode_Answer,
	eMode_Item,

	eMode_None,
} eMode;

class IQuizMakerChanger
{
public:
	virtual ~IQuizMakerChanger() = 0;
	virtual void change_mode(eMode next_mode) = 0;
	virtual void change_clear_flag(bool clear_flag) = 0;

private:

};