#pragma once

class IClearFlagChanger
{
public:
	virtual ~IClearFlagChanger() = 0;
	virtual void change_clear_flag(bool clear_flag) = 0;

private:

};