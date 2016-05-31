#include "timer.h"

Timer & Timer::GetInstance()
{
	static Timer timer;
	return timer;
}

bool Timer::CheckTime()
{
	time(&now_time_);
	if (old_time_ != now_time_)
	{
		if (enable_flag_)
		{
			remaining_time_ -= (int)(now_time_ - old_time_);
		}
		old_time_ = now_time_;
		changed_flag_ = true;
	}
	if (changed_flag_)
	{
		PrintTime();
		changed_flag_ = false;
	}
	return (remaining_time_ > 0);
}

void Timer::PenaltyTime(int penalty_time)
{
	remaining_time_ -= penalty_time;
	changed_flag_ = true;
}

void Timer::SwitchTimer(bool enable_flag)
{
	this->enable_flag_ = enable_flag;
}

void Timer::PrintTime()
{
	setCursorPos(60, 0);
	cout << "Žc‚èŽžŠÔF" << remaining_time_ / 60 << "•ª" << remaining_time_ % 60 << "•b";
}

Timer::Timer()
{
	remaining_time_ = REMAINING_TIME;
	time(&old_time_);
	time(&now_time_);
	enable_flag_ = true;
	changed_flag_ = true;
}
