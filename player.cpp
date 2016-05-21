#include "player.h"

Player::Player()
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
	this->np_pos.first = (this->np_pos.first % PLAYER_MAX_X) + 1;
}

void Player::player_move_left()
{
	this->np_pos.first = (this->np_pos.first + PLAYER_MAX_X - 2) % PLAYER_MAX_X + 1;
}

void Player::player_move_front()
{
	this->p_pos.first = this->np_pos.first;
	this->p_pos.second = this->np_pos.second;
	this->np_pos.second--;
	if (this->np_pos.second == 1) {
		np_pos.first = BOARD_ARY_WD / 2;
	}
}