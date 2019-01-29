#ifndef ytime_H
#define ytime_H
namespace ytime {
	void ysleep(int);
	// void ysleep(double); 已被删除
	unsigned long long clock(void);
	void ycsleep(double);
	unsigned long long cclock(void);
};
#endif
