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
	next_position_.first = (next_position_.first + ITEM_FLOOR_WIDTH - 1) % ITEM_FLOOR_WIDTH;
}

void Player::MoveNextPositionRight()
{
	next_position_.first = (next_position_.first + 1) % ITEM_FLOOR_WIDTH;
}

void Player::MovePositionFront()
{
	now_position_.first = next_position_.first;
	now_position_.second = next_position_.second;
	next_position_.second--;
}

void Player::GetItem(int item_num)
{
	setCursorPos(0,21);
	if (item_num != -1)
	{
		item_[item_num].item_count++;
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
		item_[item_num].enable_flag = false;
		item_[item_num].item_count--;
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
		cout << item_[i].item_name << "*" << item_[i].item_count;
		setColor(COL_WHITE, COL_BLACK);
	}
}
