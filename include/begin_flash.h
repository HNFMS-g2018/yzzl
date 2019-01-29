#ifndef begin_flash_H
#define begin_flash_H
#include <iostream>
#include "pos.h"
namespace color {
	class Color;
};
namespace begin_flash {
	class Marix {
	protected:
		pos::Coord_map<char> _map;
		color::Color *color;
	public:
		void ob_print(); // 斜向逐渐打印矩阵
		void mid_disapeear(); // 使字符矩阵中间向四周消失
		Marix(pos::Coord_map<char>, color::Color*);
		~Marix();
	};
	void welcome();
	void flash(std::string, bool);
	void thanks();
	void progress_bar(double, int);
	void box(pos::Pos, int, int, int, color::Color*);
};
#endif
