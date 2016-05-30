#include "player.h"

pair<int, int> Player::get_now_position()
{
	return now_position_;
}

pair<int, int> Player::get_next_position()
{
	return this->next_position_;
}

void Player::MoveNextPositionLeft()
{
	next_position_.first = (next_position_.first + PLAYER_MAX_X - 1) % PLAYER_MAX_X;
}

void Player::MoveNextPositionRight()
{
	next_position_.first = (next_position_.first + 1) % PLAYER_MAX_X;
}

void Player::MovePositionFront()
{
	now_position_.first = next_position_.first;
	now_position_.second = next_position_.second;
	next_position_.second--;
}

void Player::GetItem(int item_num)
{
	if (item_num != -1)
	{
		item_[item_num].item_count++;
	}
}

void Player::UseItem(int item_num, Quiz &quiz)
{
	if (item_[item_num].enable_flag) {
		if (item_num == kFiftyFifty)
		{
			UseFiftyFity(quiz);
		}
		else if (item_num == kStopTimer)
		{
			UseStopTimer();
		}
		item_[item_num].enable_flag = false;
	}
}

Player::Player()
{
	for (int i = 0; i < kItemKind; i++)
	{
		item_[i].item_count = 0;
		item_[i].enable_flag = true;
	}
	item_[kFiftyFifty].item_name = "アイテム1";
	item_[kStopTimer].item_name = "アイテム2";
	now_position_.first = PLAYER_X;;
	now_position_.second = PLAYER_Y;
	next_position_.first = PLAYER_NEXT_X;
	next_position_.second = PLAYER_NEXT_Y;
	now_floor_ = 1;
}

void Player::UseFiftyFity(Quiz & quiz)
{
	for (int i = 0; i < (QZ_OPT_SIZE / 2);)
	{
		int temp = rnd() % QZ_OPT_SIZE;
		if (!quiz.answer_type[temp] && quiz.enable_flag[temp])
		{
			quiz.enable_flag[temp] = false;
			i++;
		}
	}
}

void Player::UseStopTimer()
{
	Timer::get_instance().timer_switch(false);
}

void Player::GoUpstairs()
{
	now_floor_++;
}

int Player::get_now_floor()
{
	return now_floor_;
}

void Player::PrintNowFloor()
{
	setCursorPos(60, 1);
	cout << "現在地点：" << now_floor_ << "階";
}

void Player::EnableItem()
{
	for (int i = 0; i < kItemKind; i++)
	{
		item_[i].enable_flag = true;
	}
}
