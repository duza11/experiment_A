#pragma once

#include "base_mode.h"
#include "item.h"
#include "text_box.h"

#define ITEM_BOX_X 10
#define ITEM_BOX_Y 21
#define ITEM_OPT_X (ITEM_BOX_X + 2)
#define ITEM_OPT_Y (ITEM_BOX_Y + 1)
#define ITEM_BOX_WD 16
#define ITEM_BOX_HT 4

class ItemMode : BaseMode
{
public:
	ItemMode(IQuizMakerChanger* changer, Quiz* q);
	void init() override;
	void finit() override;
	bool update() override;
	void print() override;

private:
	int now_select = eItem_harf;
	pair<int, int> pos;
	pair<int, int> box_pos;
	TextBox *tb;
	Quiz *q;
};