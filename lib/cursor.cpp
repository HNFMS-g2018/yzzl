#include <cstdio>
#include "../include/cursor.h"

/*
 * Warning:
 * fflush(stdout) is necessary because the control sequence may
 * be buffered in memory without flush.
 */

namespace cursor {
	void up(int times) {
		printf("\033[%dA", times);
		fflush(stdout);
	}
	void down(int times) {
		printf("\033[%dB", times);
		fflush(stdout);
	}
	void left(int times) {
		printf("\033[%dD", times);
		fflush(stdout);
	}
	void right(int times) {
		printf("\033[%dC", times);
		fflush(stdout);
	}
	void to_head() {
		putchar('\r');
		fflush(stdout);
	}
	void clear_screen() {
		printf("\033[2J");
		fflush(stdout);
	}
	void set_to(int x, int y) {
		// 以 (0, 0) 为原点
		printf("\033[%d;%dH", x + 1, y + 1);
		fflush(stdout);
	}
	void back(int times) {
		// 回退（删除） [times] 个字符
		while(times --)
			putchar('\b');
		fflush(stdout);
	}
	void hide() {
		// 隐藏光标
		printf("\033[?25l");
		fflush(stdout);
	}
	void display() {
		// 显示光标
		printf("\033[?25h");
		fflush(stdout);
	}
};
