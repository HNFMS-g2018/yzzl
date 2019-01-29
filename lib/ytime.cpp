#include <sys/time.h>
#include <unistd.h>
#include "../include/ytime.h"
#include "../include/input.h"
#include <ctime>
#include <cstdio>

namespace ytime {
	void ysleep(double time) {
		// 休眠 [time] 秒
		unsigned long long end = clock() + (unsigned long long)(time * 1000);
		while(clock() < end)
			if(input::kbhit() and input::getch() == '~') // 期间不允许用户输入
				break;
	}

	void ycsleep(double time)
	{
		/*
		 * ysleep的标准库实现，在延迟两秒时和ysleep有1微秒的差距。
		 * ysleep:  2000ms
		 * ycsleep: 2001ms
		 */
		clock_t end = std::clock() + time * CLOCKS_PER_SEC;
		while (std::clock() < end);
	}

	unsigned long long clock(void) {
		// 获取程序运行时间（毫秒）
		struct timeval tv;
		struct timezone tz;
		gettimeofday(&tv, &tz);
		return tv.tv_sec * 1000 + tv.tv_usec / 1000;
	}

	unsigned long long cclock(void)
	{
		/*
		 * ytime::clock的标准库实现。
		 *
		 * ==========================================
		 * W A R N I N G :
		 * 不可和getch()一同使用。会被阻塞导致无法计时。
		 * ==========================================
		 */
		return (unsigned long long)
			((double)std::clock() * 1000.0 / CLOCKS_PER_SEC);
	}
};
