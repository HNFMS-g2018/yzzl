#include <cstdio>
#include <cstdlib>
#include "input.h"
#include "ytime.h"

int main(void)
{
	unsigned long long start, end, start1, end1;
	int i;

	puts("Test ysleep");
	start = ytime::clock();
	ytime::ysleep(2);
	end = ytime::clock();
	printf("sleep 2s, %lld\n", end - start);

	puts("Test ycsleep");
	start = ytime::clock();
	ytime::ycsleep(2);
	end = ytime::clock();
	printf("sleep 2s, %lld\n", end - start);

	puts("Test getch() input time(first)");
	input::getch();
	start = ytime::clock();
	start1 = ytime::cclock();
	puts("Test getch() input time(second)");
	input::getch();
	end = ytime::clock();
	end1 = ytime::cclock();

	printf("clock():  %lld - %lld = %lld\n", end, start, end - start);
	printf("cclock(): %lld - %lld = %lld\n", end1, start1, end1 - start1);

	puts("Test starndard library(getchar()) input time(first)");
	while (getchar() != '\n');
	start = ytime::clock();
	start1 = ytime::cclock();
	puts("Test starndard library(getchar()) input time(second)");
	while (getchar() != '\n');
	end = ytime::clock();
	end1 = ytime::cclock();
	printf("clock():  %lld - %lld = %lld\n", end, start, end - start);
	printf("cclock(): %lld - %lld = %lld\n", end1, start1, end1 - start1);

	puts("Test noinput time");
	start = ytime::clock();
	start1 = ytime::cclock();
	for (i = 0; i < 10000000; ++i)
		rand();
	end = ytime::clock();
	end1 = ytime::cclock();

	printf("clock():  %lld - %lld = %lld\n", end, start, end - start);
	printf("cclock(): %lld - %lld = %lld\n", end1, start1, end1 - start1);
	return 0;
}
