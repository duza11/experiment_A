#pragma once

#include <time.h>
#include "console_util.h"
#include "common.h"

class Timer {
public:
	static Timer& GetInstance();
	bool CheckTime();
	void PenaltyTime(int penalty_time);
	void SwitchTimer(bool enable_flag);
	void PrintTime();

private:
	Timer();
	Timer(const Timer & t) {}
	~Timer() {}

	int remaining_time_;
	time_t old_time_, now_time_;
	bool enable_flag_;
	bool changed_flag_;
};