#pragma once

#include <time.h>
#include "console_util.h"
#include "common.h"

class Timer {
public:
	static Timer& get_instance()
	{
		static Timer timer;
		return timer;
	}

	bool timer_check()
	{
		time(&now);
		if (old != now)
		{
			if (timer_flag)
			{
				time_limit -= (int)(now - old);
			}
			old = now;
			time_moved_flag = true;
		}
		if (time_moved_flag)
		{
			timer_print();
			time_moved_flag = false;
		}
		return (time_limit > 0);
	}

	void timer_penalty(int pen_time)
	{
		time_limit -= pen_time;
		time_moved_flag = true;
	}

	void timer_switch(bool timer_flag)
	{
		this->timer_flag = timer_flag;
	}

	void timer_print()
	{
		setCursorPos(60, 0);
		cout << "Žc‚èŽžŠÔF" << time_limit / 60 << "•ª" << time_limit % 60 << "•b";
	}

private:
	Timer()
	{
		time_limit = TIME;
		time_moved_flag = true;
		timer_flag = true;
		time(&old);
		time(&now);
	}
	Timer(const Timer & t) {}
	~Timer() {}

	int time_limit;
	bool timer_flag = true;
	time_t old, now;
	int time_moved_flag;
};