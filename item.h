#pragma once

#include <stdarg.h>
#include <random>
#include "common.h"
#include "quiz.h"

class Item
{
public:
	static Item& get_instance()
	{
		static Item item;
		return item;
	}

	void get_item(int selected_item) {
		this->avail_item[selected_item]++;
		cout << item_name[selected_item] << "を手に入れた";
	}

	void use_item(int selected_item, ...) {
		if (!use_flag[selected_item]) {
			va_list args;
			va_start(args, selected_item);
			if (selected_item == eItem_harf)
			{
				Quiz *q = va_arg(args, Quiz *);
				use_harf(*q);
			}
			else if (selected_item == eItem_time)
			{
				use_time();
			}
			va_end(args);
			use_flag[selected_item] = true;
		}
	}

	void use_flag_reset()
	{
		for (int i = 0; i < eItem_length; i++)
		{
			use_flag[i] = false;
		}
	}

private:
	Item()
	{
		for (int i = 0; i < eItem_length; i++)
		{
			avail_item[i] = 0;
			use_flag[i] = false;
		}
		item_name[eItem_harf] = "アイテム1";
		item_name[eItem_time] = "アイテム2";
	}
	Item(const Item & item) {}
	~Item() {}

	void use_harf(Quiz & q)
	{
		for (int i = 0; i < (QZ_OPT_SIZE / 2);)
		{
			int temp = rnd() % QZ_OPT_SIZE;
			if (!q.quiz_get_ans_type(temp) && !q.quiz_get_answered_flag(temp))
			{
				q.quiz_set_answered_flag(temp, true);
				i++;
			}
		}
	}

	void use_time()
	{
		Timer::get_instance().timer_switch(false);
	}

	random_device rnd;
	int avail_item[eItem_length];
	int use_flag[eItem_length];
	string item_name[eItem_length];
};