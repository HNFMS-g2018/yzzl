#include "../../include/people/pig.h"
#include "../../include/color.h"

namespace people {
	Pig::Pig():
		People(new color::Red, 'P', 0, 100, 3, 5) {
	}
	Pig::~Pig() {
	}
	void Pig::_todo() {
		srand(time(0));
		int randx = -1 + rand()%3, randy = -1 + rand()%3;
		pos::Pos ps = get_pos();
		move(pos::Pos(ps._x + randx, ps._y + randy));
	}
	int Pig::_meet(People *p) {
		// 不打架
		p -> injured(get_fight(), this);
		return 0;
	}
};
