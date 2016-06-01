#include "player.h"

Player & Player::GetInstance()
{
	static Player player;
	return player;
}

pair<int, int> Player::get_now_position()
{
	return this->now_position_;
}

pair<int, int> Player::get_next_position()
{
	return this->next_position_;
}

void Player::MoveNextPositionLeft()
{
	this->next_position_.first = (next_position_.first + ITEM_FLOOR_WIDTH - 1) % ITEM_FLOOR_WIDTH;
}

void Player::MoveNextPositionRight()
{
	this->next_position_.first = (next_position_.first + 1) % ITEM_FLOOR_WIDTH;
}

void Player::MovePositionFront()
{
	this->now_position_ = this->next_position_;
	this->next_position_.second--;
}

void Player::GetItem(int item_num)
{
	setCursorPos(0,21);
	if (item_num != -1)
	{
		this->item_[item_num].item_count++;
		cout << item_[item_num].item_name << "を手に入れた";
	}
	else
	{
		cout << "何も見つからなかった   ";
	}
}

void Player::UseItem(int item_num, Quiz &quiz)
{
	if (item_[item_num].enable_flag && item_[item_num].item_count > 0) {
		if (item_num == kFiftyFifty)
		{
			UseFiftyFity(quiz);
		}
		else if (item_num == kStopTimer)
		{
			UseStopTimer();
		}
		this->item_[item_num].enable_flag = false;
		this->item_[item_num].item_count--;
	}
}

Player::Player()
{
	for (int i = 0; i < kItemKind; i++)
	{
		this->item_[i].item_count = 0;
		this->item_[i].enable_flag = true;
	}
	this->item_[kFiftyFifty].item_name = "アイテム1";
	this->item_[kStopTimer].item_name = "アイテム2";
	this->now_position_ = { PLAYER_X , PLAYER_Y };
	this->next_position_ = { PLAYER_NEXT_X , PLAYER_NEXT_Y };
	this->now_floor_ = 1;
}

void Player::UseFiftyFity(Quiz & quiz)
{
	for (int i = 0; i < (QUIZ_OPTION_SIZE / 2);)
	{
		int temp = (unsigned)rnd() % QUIZ_OPTION_SIZE;
		if (!quiz.answer_type[temp] && quiz.enable_flag[temp])
		{
			quiz.enable_flag[temp] = false;
			i++;
		}
	}
}

void Player::UseStopTimer()
{
	Timer::GetInstance().SwitchTimer(false);
}

void Player::GoUpstairs()
{
	this->now_floor_++;
}

int Player::get_now_floor()
{
	return this->now_floor_;
}

void Player::PrintNowFloor()
{
	setCursorPos(60, 3);
	cout << "現在地点：" << this->now_floor_ << "階";
}

void Player::EnableItem()
{
	for (int i = 0; i < kItemKind; i++)
	{
		this->item_[i].enable_flag = true;
	}
}

void Player::PrintItemStatus(pair<int, int> position)
{
	for (int i = 0; i < kItemKind; i++)
	{
		if (item_[i].enable_flag && item_[i].item_count > 0)
		{
			setColor(COL_WHITE, COL_BLACK);
		}
		else
		{
			setColor(COL_GRAY, COL_BLACK);
		}
		setCursorPos(position.first, position.second + i);
		cout << this->item_[i].item_name << "*" << this->item_[i].item_count;
		setColor(COL_WHITE, COL_BLACK);
	}
}
