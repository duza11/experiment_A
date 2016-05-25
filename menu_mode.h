#pragma once

#include "base_mode.h"

typedef enum
{
	eMenu_Asnwer,
	eMenu_Item,

	eMenu_Num,
} eMenu;

class MenuMode : public BaseMode
{
public:
	MenuMode(IModeChanger* changer);
	void init() override;
	void finit() override;
	void update() override;
	void print() override;

private:
	int now_select = eMenu_Asnwer;
};