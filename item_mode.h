#pragma once

#include "base_mode.h"
#include "item.h"

class ItemMode : BaseMode
{
public:
	ItemMode(IModeChanger* changer);
	void init() override;
	void finit() override;
	void update() override;
	void print() override;

private:
	int now_select = eItem_harf;
};