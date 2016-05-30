#pragma once

#include "base_mode.h"
#include "player.h"
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
	ItemMode(IQuizFloor* changer, Quiz *quiz);
	void Finitialize() override;
	bool Update() override;
	void Print() override;

private:
	int now_select_ = kFiftyFifty;
	pair<int, int> position_;
	pair<int, int> box_position_;
	TextBox *tb_;
	Quiz *quiz_;
};