//----------------------------------------------------------------------
//		2048
//		Copyright (C) 2048 by N.Tsuda
//		License: CDDL 1.0 (http://opensource.org/licenses/CDDL-1.0)
//----------------------------------------------------------------------
#include <Windows.h>
#include <conio.h>		//	_getch
#include <time.h>			//	time
#include <iostream>
#include <sstream>      // std::ostringstream
#include <string>
#include "Player.h"
#include "consoleUtil.h"
#include "common.h"

#define	KEY_ARROW 0xe0
#define	KEY_UP 0x48
#define	KEY_LEFT 0x4b
#define	KEY_RIGHT 0x4d
#define	KEY_DOWN 0x50

int	g_score = 0;
//int	g_nBlank;		//	空欄箇所数
int	g_board[BOARD_WD + 2][BOARD_HT + 2];		//	番人付きボード２次元配列

												//----------------------------------------------------------------------
std::string tostr(int v)
{
	std::ostringstream os;
	os << v;
	return os.str();
}
//----------------------------------------------------------------------
void	init_board()
{
	//g_nBlank = BOARD_WD * BOARD_HT;		//	空欄箇所数
	for (int x = 0; x < BOARD_WD + 2; ++x) {
		for (int y = 0; y < BOARD_HT + 2; ++y) {
			if (x == 0 || x == BOARD_WD + 1 ||
				y == 0 || y == BOARD_HT + 1)
			{
				g_board[x][y] = WALL;
			}
			else {
				g_board[x][y] = 0;
			}
		}
	}
}
template <class X> void setFgBgColor(X input)
{
	int fg = COL_WHITE;
	int bg = COL_BLACK;
	switch (input) {
	case 0:		bg = COL_LIGHT_GRAY;	break;
	case 1:		bg = COL_DARK_YELLOW;	break;
	case 2:		bg = COL_DARK_CYAN;	break;
	case 3:		bg = COL_DARK_GREEN;	break;
	case 'P':	bg = COL_DARK_BLUE;	break;
	case 'N':	bg = COL_BLACK; break;
	}

	setColor(fg, bg);
}

void print_line(int y, bool printVal)
{
	for (int x = 1; x <= BOARD_WD; ++x) {
		int v = g_board[x][y];
		//setColor(fgColor(v), bgColor(v));
		setFgBgColor(v);
		string str(CELL_WIDTH, ' ');
		if (printVal) {
			if (!v)
				str = '.';
			else
				str = v;
			str += string((CELL_WIDTH - str.size()) / 2, ' ');		//	末尾に空白パディング
			str = string(CELL_WIDTH - str.size(), ' ') + str;		//	先頭に空白パディング
		}
		cout << str;
	}
	cout << "\n";
}

void print_board()
{
	setCursorPos(0, 0);
	setColor(COL_WHITE, COL_BLACK);
	cout << "SCORE: " << g_score << "        \n\n";
	for (int y = 1; y <= BOARD_HT; ++y) {
		print_line(y, false);
		print_line(y, true);
		print_line(y, false);
	}
	cout << "\n";
}

bool isMovable()
{
	for (int y = 1; y <= BOARD_HT; ++y) {
		for (int x = 1; x <= BOARD_WD; ++x) {
			if (g_board[x][y] == 0 ||
				g_board[x][y] == g_board[x + 1][y] ||
				g_board[x][y] == g_board[x][y + 1])
			{
				return true;
			}
		}
	}
	return false;
}
int main()
{
	Player p;
	while (1) {
		g_score = 0;
		init_board();
		for (bool moved = true;;) {
			if (moved)
			{
				p.player_set_pos(g_board);
			}
			print_board();
			if (!isMovable())
			{
				break;
			}
			setColor(COL_WHITE, COL_BLACK);
			cout << "Type ←→     ";
			int c = _getch();
			//cout << c << "\n";
			if (c == 'q') break;
			if (c == ' ')
			{
				p.player_move_front(g_board);
			}
			if (c == KEY_ARROW)
			{
				int c = _getch();
				//cout << c << "\n";
				switch (c) {
				case KEY_LEFT:
					p.player_move_left(g_board);
					break;
				case KEY_RIGHT:
					p.player_move_right(g_board);
					break;
				}
			}
		}
		setColor(COL_WHITE, COL_BLACK);
		cout << "Try again ? [y/n]   ";
		int c;
		for (;;) {
			c = _getch();
			if (c == KEY_ARROW)
				_getch();
			if (c == 'y' || c == 'Y' ||
				c == 'n' || c == 'N')
			{
				break;
			}
		}
		if (c != 'y' && c != 'Y') break;
	}
	return 0;
}