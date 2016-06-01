#include "double_buffer.h"

DoubleBuffer::DoubleBuffer()
	: m_swapped(false)
{
	m_hCons1 = CreateConsoleScreenBuffer(
		GENERIC_READ | GENERIC_WRITE,
		0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
	m_hCons2 = CreateConsoleScreenBuffer(
		GENERIC_READ | GENERIC_WRITE,
		0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
	SetConsoleActiveScreenBuffer(m_hCons1);
	CONSOLE_CURSOR_INFO info;
	info.dwSize = 1;
	info.bVisible = FALSE;
	SetConsoleCursorInfo(m_hCons1, &info);
	SetConsoleCursorInfo(m_hCons2, &info);
}

DoubleBuffer::~DoubleBuffer()
{
	CloseHandle(m_hCons1);
	CloseHandle(m_hCons2);
}

void DoubleBuffer::setColor(int col)
{
	WORD attr = 0;
	if (col & INTENSITY)
		attr |= FOREGROUND_INTENSITY;
	if (col & RED_MASK)
		attr |= FOREGROUND_RED;
	if (col & GREEN_MASK)
		attr |= FOREGROUND_GREEN;
	if (col & BLUE_MASK)
		attr |= FOREGROUND_BLUE;
	SetConsoleTextAttribute(m_swapped ? m_hCons1 : m_hCons2, attr);
}

void DoubleBuffer::setColor(int fg, int bg)
{
	WORD attr = 0;
	if (fg & INTENSITY)
		attr |= FOREGROUND_INTENSITY;
	if (fg & RED_MASK)
		attr |= FOREGROUND_RED;
	if (fg & GREEN_MASK)
		attr |= FOREGROUND_GREEN;
	if (fg & BLUE_MASK)
		attr |= FOREGROUND_BLUE;

	if (bg & INTENSITY)
		attr |= BACKGROUND_INTENSITY;
	if (bg & RED_MASK)
		attr |= BACKGROUND_RED;
	if (bg & GREEN_MASK)
		attr |= BACKGROUND_GREEN;
	if (bg & BLUE_MASK)
		attr |= BACKGROUND_BLUE;
	SetConsoleTextAttribute(m_swapped ? m_hCons1 : m_hCons2, attr);
}

void DoubleBuffer::setCursorPos(int x, int y)
{
	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(m_swapped ? m_hCons1 : m_hCons2, pos);
}

void DoubleBuffer::write(const char *ptr)
{
	DWORD len = strlen(ptr);
	WriteConsoleA(m_swapped ? m_hCons1 : m_hCons2, ptr, len, &len, 0);
}

void DoubleBuffer::write(const wchar_t *ptr)
{
	DWORD len = wcslen(ptr);
	WriteConsoleW(m_swapped ? m_hCons1 : m_hCons2, ptr, len, &len, 0);
}

void DoubleBuffer::write(const std::string &str)
{
	DWORD len = str.size();
	WriteConsoleA(m_swapped ? m_hCons1 : m_hCons2, str.c_str(), len, &len, 0);
}

void DoubleBuffer::write(const std::wstring &str)
{
	DWORD len = str.size();
	WriteConsoleA(m_swapped ? m_hCons1 : m_hCons2, str.c_str(), len, &len, 0);
}

void DoubleBuffer::ClearScreen()
{
	DWORD   dwNumberOfCharsWritten; // 書き込まれたセル数
	COORD   coord = { 0, 0 };       //書き込みを開始する位置 x:0y:0に設定
	CONSOLE_SCREEN_BUFFER_INFO screen_info;
	::GetConsoleScreenBufferInfo(m_swapped ? m_hCons1 : m_hCons2, &screen_info);
	// バッファ内の指定した座標から指定した数の文字セル分だけ、前景色と背景色を設定
	::FillConsoleOutputAttribute(m_swapped ? m_hCons1 : m_hCons2,
		WHITE + (BLACK << 4),
		screen_info.dwSize.X * screen_info.dwSize.Y,
		coord,
		&dwNumberOfCharsWritten
	);
	// バッファ内の指定した座標から、指定した文字を指定した数だけ書き込む
	::FillConsoleOutputCharacter(
		m_swapped ? m_hCons1 : m_hCons2,
		' ',
		screen_info.dwSize.X * screen_info.dwSize.Y,
		coord,
		&dwNumberOfCharsWritten
	);
}

void DoubleBuffer::swap()
{
	if ((m_swapped = !m_swapped)) {
		SetConsoleActiveScreenBuffer(m_hCons2);
	}
	else {
		SetConsoleActiveScreenBuffer(m_hCons1);
	}
}