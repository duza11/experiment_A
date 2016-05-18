#include "player.h"

Player::Player()
{
	this->x = PLAYER_X;
	this->y = PLAYER_Y;
	this->next_x = PLAYER_NEXT_X;
	this->next_y = PLAYER_NEXT_Y;
}

Player::~Player()
{

}

void Player::player_set_pos(int (&g_board)[BOARD_ARY_WD][BOARD_ARY_HT])
{
	g_board[this->x][this->y] = 'P';
	g_board[this->next_x][this->next_y] = 'N';
}

void Player::player_move_right(int(&g_board)[BOARD_ARY_WD][BOARD_ARY_HT])
{
	if (this->next_x == PLAYER_MAX_X)
	{
		swap(g_board[this->next_x][this->next_y], g_board[PLAYER_MIN_X][this->next_y]);
		this->next_x = PLAYER_MIN_X;
	}
	else
	{
		swap(g_board[this->next_x][this->next_y], g_board[this->next_x + 1][this->next_y]);
		this->next_x++;
	}
}

void Player::player_move_left(int(&g_board)[BOARD_ARY_WD][BOARD_ARY_HT])
{
	if (this->next_x == PLAYER_MIN_X)
	{
		swap(g_board[this->next_x][this->next_y], g_board[PLAYER_MAX_X][this->next_y]);
		this->next_x = PLAYER_MAX_X;
	}
	else
	{
		swap(g_board[this->next_x][this->next_y], g_board[this->next_x - 1][this->next_y]);
		this->next_x--;
	}
}

void Player::player_move_front(int(&g_board)[BOARD_ARY_WD][BOARD_ARY_HT])
{
	swap(g_board[this->next_x][this->next_y], g_board[PLAYER_X][this->next_y - 1]);
	swap(g_board[this->x][this->y], g_board[this->next_x][this->next_y]);
	this->x = this->next_x;
	this->y = this->next_y;
	this->next_x = PLAYER_X;
	this->next_y--;

	if (this->y == PLAYER_MAX_Y) {
		
	}
}