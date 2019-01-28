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
		printf("\n\033[1A");
		fflush(stdout);
	}
	void clear_screen() {
		printf("\033[2J");
		fflush(stdout);
	}
	void set_to(int x, int y) {
		printf("\033[%d;%dH", x, y);
		fflush(stdout);
	}
};
