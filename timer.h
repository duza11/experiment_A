#pragma once

#include <time.h>
#include "consoleUtil.h"
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
			time(&old);
			time_limit -= (now - old);
			time_moved_flag = true;
		}
		if (time_moved_flag)
		{
			setCursorPos(60, 0);
			cout << "Žc‚èŽžŠÔF" << time_limit / 60 << "•ª" << time_limit % 60 << "•b";
			time_moved_flag = false;
		}
		return (time_limit > 0);
	}

private:
	Timer()
	{
		time_limit = TIME;
		time_moved_flag = true;
		time(&old);
		time(&now);
	}
	Timer(const Timer & t) {}
	~Timer() {}

	static Timer* timer;
	int time_limit;
	time_t old, now;
	int time_moved_flag;
};