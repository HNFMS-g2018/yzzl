#ifndef people_H
#define people_H
#include <queue>
#include "../pos.h"
namespace floor {
	class Floor;
};
namespace map {
	class Map;
};
namespace color {
	class Color;
};
namespace people {
	class People {
	protected:
		std::queue<map::Map *> _map;
		std::queue<pos::Pos> _pos;
		virtual void _todo() = 0;
		virtual int _meet(People *) = 0;
		int _lv;
		long long _hpmax, _fight;
	public:
		color::Color *color;
		char face;
		long long m_exp, m_hp;
		int clever;
		int speed;
		int goin(floor::Floor *); // 事件：进入地面
		int move(pos::Pos); // 在 Map 中移动到某位置
		void todo(); // 观察，作出决策
		void join_map(map::Map *);
		void leave_map();
		pos::Pos get_pos();
		map::Map *get_map();
		long long get_hpmax();
		long long get_fight();
		int meet(People *);
		void injured(long long, People *);
		People(color::Color*, char, int, long long, long long, int);
		virtual ~People();
	};
};
#endif
