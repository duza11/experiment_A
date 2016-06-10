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
	SetCursorPosition(0,21);
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

void Player::UseItem(int item_num, Quiz &quiz, IQuizFloor *iqf)
{
	if (item_[item_num].enable_flag && item_[item_num].item_count > 0) {
		if (item_num == kFiftyFifty)
		{
			UseFiftyFity(quiz, iqf);
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
	this->item_[kFiftyFifty].item_name = "フィフティ・フィフティ";
	this->item_[kStopTimer].item_name = "タイムストッパー";
	this->item_[kFiftyFifty].explain = {"選択肢を3つ消します", "残りの選択肢が3つ", "以下の場合は正解に", "なります"};
	this->item_[kStopTimer].explain = {"このクイズに正解する", "まで時間経過で残り", "時間が減りません", "ペナルティは発生しま", "す"};
	this->now_position_ = { PLAYER_X , PLAYER_Y };
	this->next_position_ = { PLAYER_NEXT_X , PLAYER_NEXT_Y };
	this->now_floor_ = 1;
}

void Player::UseFiftyFity(Quiz & quiz, IQuizFloor *iqf)
{
	int enable_flag_count = 0;
	int answer_num;
	for (int i = 0; i < QUIZ_OPTION_SIZE; i++)
	{
		if (quiz.enable_flag[i])
		{
			if (quiz.answer_type[i] == true)
			{
				answer_num = i;
			}
			enable_flag_count++;
		}
	}
	if (enable_flag_count < 4)
	{
		(*iqf).CheckAnswer(answer_num);
		return;
	}
	else
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
	SetCursorPosition(70, 3);
	cout << "現在地点：" << this->now_floor_ << "/9階";
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
			SetColor(COL_WHITE, COL_BLACK);
		}
		else
		{
			SetColor(COL_GRAY, COL_BLACK);
		}
		SetCursorPosition(position.first, position.second + i);
		cout << this->item_[i].item_name << "*" << this->item_[i].item_count;
		SetColor(COL_WHITE, COL_BLACK);
	}
}

void Player::PrintItemExplain(int item_num, pair<int, int> position)
{
	for (int i = 0; i < item_[item_num].explain.size(); i++)
	{
		SetCursorPosition(position.first, position.second + i);
		cout << item_[item_num].explain[i];
	}
}
