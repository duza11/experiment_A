#pragma once

#include <conio.h>
#include "i_mode_changer.h"
#include "consoleUtil.h"

class BaseMode
{
public:
	BaseMode(IModeChanger* changer);
	virtual ~BaseMode();
	virtual void init();
	virtual void finit();
	virtual void update();
	virtual void print();

protected:
	IModeChanger* m_mode_changer;

private:
	int now_select = 0;
};