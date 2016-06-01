#include "timer.h"

Timer & Timer::GetInstance()
{
	static Timer timer;
	return timer;
}

bool Timer::CheckTime()
{
	time(&this->now_time_);
	if (old_time_ != this->now_time_)
	{
		if (this->enable_flag_)
		{
			this->remaining_time_ -= (int)(this->now_time_ - this->old_time_);
		}
		this->old_time_ = this->now_time_;
		this->changed_flag_ = true;
	}
	if (this->changed_flag_)
	{
		PrintTime();
		this->changed_flag_ = false;
	}
	return (remaining_time_ > 0);
}

void Timer::PenaltyTime(int penalty_time)
{
	this->remaining_time_ -= penalty_time;
	this->changed_flag_ = true;
}

void Timer::SwitchTimer(bool enable_flag)
{
	this->enable_flag_ = enable_flag;
}

void Timer::PrintTime()
{
	setCursorPos(60, 2);
	cout << "�c�莞�ԁF" << this->remaining_time_ / 60 << "��" << this->remaining_time_ % 60 << "�b";
	/*for (int i = 0; i < 2; i++)
	{
		DoubleBuffer::GetInstance().setCursorPos(60, 2);
		DoubleBuffer::GetInstance().write("�c�莞�ԁF" + to_string(remaining_time_ / 60) + "��" + to_string(remaining_time_ % 60) + "�b");
		DoubleBuffer::GetInstance().swap();
	}*/
}

Timer::Timer()
{
	this->remaining_time_ = REMAINING_TIME;
	time(&this->old_time_);
	time(&this->now_time_);
	this->enable_flag_ = true;
	this->changed_flag_ = true;
}
