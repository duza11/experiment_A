#include "player.h"

/*Player::Player()
{
	this->p_pos.first = PLAYER_X;
	this->p_pos.second = PLAYER_Y;
	this->np_pos.first = PLAYER_NEXT_X;
	this->np_pos.second = PLAYER_NEXT_Y;
}

Player::~Player()
{

}

pair<int, int> Player::player_get_pos()
{
	return this->p_pos;
}

pair<int, int> Player::player_get_next_pos()
{
	return this->np_pos;
}

void Player::player_move_right()
{
	this->np_pos.first = (this->np_pos.first + 1) % PLAYER_MAX_X;
}

void Player::player_move_left()
{
	this->np_pos.first = (this->np_pos.first + PLAYER_MAX_X - 1) % PLAYER_MAX_X;
}

void Player::player_move_front()
{
	this->p_pos.first = this->np_pos.first;
	this->p_pos.second = this->np_pos.second;
	this->np_pos.second--;
}*/

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
	setCursorPos(40, 4);
	cout << item_[item_num].item_name << "を手に入れた";
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
