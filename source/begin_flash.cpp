#include <iostream>
#include <cstring>
#include <functional>
#include "../include/ytime.h"
#include "../include/color.h"
#include "../include/cursor.h"
#include "../include/input.h"
#include "../include/begin_flash.h"
#include "../include/ascii_flash.h"

namespace begin_flash {
	Marix::Marix(pos::Coord_map<char> _map, color::Color *color):
		_map(_map), color(color) {
	}
	Marix::~Marix() {
		delete color;
	}

	void Marix::ob_print() {
		color::White wh;
		for(int t=0; t<_map.high+_map.width; t++) {
			for(int i=0; i<_map.high; i++) {
				for(int j=0; j<_map.width; j++)
					if(i + j == t) {
						wh.change_fore();
						std::cout << _map(i, j);
					} else if(i + j < t) {
						color->change_fore();
						std::cout << _map(i, j);
					}
				std::cout << std::endl;
			}
			ytime::ysleep(0.1);
			cursor::up(_map.high);
		}
		cursor::down(_map.high);
		color->reset_fore();
		input::clear();
	}

	void Marix::mid_disapeear() {
		cursor::up(_map.high);
		color::White wl;
		int rx = _map.high >> 1, ry = _map.width >> 1; // 矩阵中心坐标
		for(int t=0; t*2<_map.high+_map.width; t ++) {
			for(int i=0; i<_map.high; i++) {
				for(int j=0; j<_map.width; j++)
					if(std::abs(i - rx) + std::abs(j - ry) < t)
						std::cout << ' ';
					else if(std::abs(i - rx) + std::abs(j - ry) == t) {
						wl.change_fore();
						std::cout << _map(i, j);
					} else {
						color->change_fore();
						std::cout << _map(i, j);
					}
				std::cout << std::endl;
			}
			ytime::ysleep(0.1);
			cursor::up(_map.high);
		}
		color->reset_fore();
		input::clear();
	}

	void flash(std::string info, bool speedup) {
		// 以黑白加速闪动特效输出 [info]
		color::Color *cr[2] = {new color::Black(0), new color::White(0)};
		for(int i=0; i < (speedup?20:10); i++) {
			cr[i & 1]->change_fore();
			cursor::to_head();
			std::cout << info << std::endl;
			cursor::up();
			if(speedup)
				ytime::ysleep(0.2 - 0.01 * i);
			else
				ytime::ysleep(0.2);
		}
		input::clear();
		cr[0]->reset_fore();
		delete cr[0];
		delete cr[1];
	}

	void welcome() {
		// 欢迎界面
		cursor::clear_screen();
		cursor::set_to(0, 0);
		begin_flash::flash("Welcome to yzzl", true);
		const int flash_sl = 6;
		std::function<pos::Coord_map<char>()> flash[flash_sl]
			= {Flash1, Flash2, Flash3, Flash4, Flash5, Flash6 };
		srand(time(0));
		color::Color *color = nullptr;
		int rd = rand() % 100;
		if(rd < 60) color = new color::Green();
		else if(rd < 90) color = new color::Red();
		else color = new color::Random();
		begin_flash::Marix mar(flash[rand()%flash_sl](), color);
		mar.ob_print();
		mar.mid_disapeear();
	}

	void thanks() {
		// 鸣谢
		cursor::clear_screen();
		cursor::set_to(0, 0);
		begin_flash::flash("Yzzl 的诞生还要感谢许多人和软件、网站", false);
		cursor::down();
		const int high = 11, width = 80;
		const char s[high][width] = {
			"                                                                 ",
			"Liu Da Xia: His 'Yong Zhe Zhi Lu' inspire me to create yzzl      ",
			"    whose idea is from that.                                     ",
			"                                                                 ",
			"Ld_liaomo: help me to write lib files which needed.              ",
			"                                                                 ",
			"https://www.bootschool.net/ascii: Provide the source of the      ",
			"    opening animation which is made by ascii painting.           ",
			"                                                                 ",
			"And thank you to play this!                                      ",
			"                                                                 ",
		};
		pos::Coord_map<char> cmap(high, width);
		for(int i=0;i<high;i++)
			for(int j=0;j<width;j++)
				cmap(i, j) = s[i][j] ? s[i][j] : ' ';
		begin_flash::Marix mar(cmap, new color::Green);
		mar.ob_print();
		mar.mid_disapeear();
	}

	void progress_bar(double x, int size) {
		cursor::right(size);
		putchar('|');
		cursor::left(size + 1);
		size *= 8;
		int need;
		for(need=size*x; need>=8; need -= 8)
			printf("█"); // 完整方块
		switch(need) {
			case 1: printf("▏"); break; // 八分之一
			case 2: printf("▎"); break; // 八分之二
			case 3: printf("▍"); break; // 八分之三
			case 4: printf("▌"); break; // 八分之四
			case 5: printf("▋"); break; // 八分之五
			case 6: printf("▊"); break; // 八分之六
			case 7: printf("▉"); break; // 八分之七
		}
		puts("");
	}
};
