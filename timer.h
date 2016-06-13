#pragma once

#include <time.h>
#include "console_util.h"
#include "common.h"

class Timer {
public:
	static Timer& GetInstance(); // ´…‘åŽ÷
	void Initialize();
	bool CheckTime(); // ´…‘åŽ÷
	void PenaltyTime(int penalty_time); // ´…‘åŽ÷
	void SwitchTimer(bool enable_flag); // ´…‘åŽ÷
	void PrintTime(); // ´…‘åŽ÷

private:
	Timer(); // ´…‘åŽ÷
	Timer(const Timer & t) {} // ´…‘åŽ÷
	~Timer() {} // ´…‘åŽ÷

	int remaining_time_;
	time_t old_time_, now_time_;
	bool enable_flag_;
	bool changed_flag_;
};