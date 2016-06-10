#pragma once

#include <Windows.h>
#include <string>
#include <iostream>

using namespace std;

//		�F��`
#define		COL_BLACK	0x00
#define		COL_DARK_BLUE		0x01
#define		COL_DARK_GREEN	0x02
#define		COL_DARK_CYAN		0x03
#define		COL_DARK_RED		0x04
#define		COL_DARK_VIOLET	0x05
#define		COL_DARK_YELLOW	0x06
#define		COL_GRAY	0x07
#define		COL_LIGHT_GRAY		0x08
#define		COL_BLUE		0x09
#define		COL_GREEN	0x0a
#define		COL_CYAN		0x0b
#define		COL_RED		0x0c
#define		COL_VIOLET	0x0d
#define		COL_YELLOW	0x0e
#define		COL_WHITE	0x0f
#define		COL_INTENSITY		0x08		//	���P�x�}�X�N
#define		COL_RED_MASK		0x04
#define		COL_GREEN_MASK	0x02
#define		COL_BLUE_MASK	0x01

#define	KEY_ARROW 0xe0
#define	KEY_UP 0x48
#define	KEY_LEFT 0x4b
#define	KEY_RIGHT 0x4d
#define	KEY_DOWN 0x50
#define KEY_SPACE 0x20
#define KEY_BACK 0x08
#define KEY_ENTER 0x0d

// �����F�w��
void SetColor(int col);
// �����F�Ɣw�i�F�w��
void SetColor(int fg, int bg);
// �J�[�\���ʒu�w��
void SetCursorPosition(int x, int y);
// �J�[�\����\���ݒ� TRUE=�\��,FALSE=��\��
void SetCursorDisplay(BOOL bVisible);

void SetBufferSize(int x, int y);