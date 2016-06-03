#pragma once

#include <Windows.h>
#include <string>

class DoubleBuffer
{
public:
	enum {
		BLACK = 0x00,
		DARK_BLUE = 0x01,
		DARK_GREEN = 0x02,
		DARK_CYAN = 0x03,
		DARK_RED = 0x04,
		DARK_VIOLET = 0x05,
		DARK_YELLOW = 0x06,
		GRAY = 0x07,
		LIGHT_GRAY = 0x08,
		BLUE = 0x09,
		GREEN = 0x0a,
		CYAN = 0x0b,
		RED = 0x0c,
		VIOLET = 0x0d,
		YELLOW = 0x0e,
		WHITE = 0x0f,
		INTENSITY = 0x08,		//	���P�x�}�X�N
		RED_MASK = 0x04,
		GREEN_MASK = 0x02,
		BLUE_MASK = 0x01,
	};


public:
	static DoubleBuffer &GetInstance()
	{
		static DoubleBuffer double_buffer;
		return double_buffer;
	}
	void setColor(int);
	void setColor(int, int);
	void setCursorPos(int, int);
	void write(const char *);
	void write(const wchar_t *);
	void write(const std::string &);
	void write(const std::wstring &);
	void ClearScreen();
	void swap();

private:
	DoubleBuffer();
	DoubleBuffer(const DoubleBuffer &DoubleBuffer) {}
	~DoubleBuffer();

	bool m_swapped;
	HANDLE m_hCons1;		//	�R���\�[���n���h�����̂P
	HANDLE m_hCons2;		//	�R���\�[���n���h�����̂Q
};