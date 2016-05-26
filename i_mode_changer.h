#pragma once

typedef enum
{
	eMode_Menu,
	eMode_Answer,
	eMode_Item,

	eMode_None,
} eMode;

class IModeChanger
{
public:
	IModeChanger();
	virtual ~IModeChanger() = 0;
	virtual void change_mode(eMode next_mode) = 0;

private:

};