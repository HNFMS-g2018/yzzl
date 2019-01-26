#include "../../include/map/map.h"
#include "../../include/floor/floor.h"
#include "../../include/people/people.h"

namespace map {
	Map::Map(int high, int width):
		_floor(high, width), _people(high, width), high(high), width(width) {
	}
	Map::~Map() {
		for(int i=0;i<high;i++)
			for(int j=0;j<width;j++) {
				delete _floor(i, j);
				delete _people(i, j);
			}
	}
	int Map::people_move(people::People *p, pos::Pos ol, pos::Pos ne) {
		// 检查 [p] 的移动
		if(ne._x < 0 or ne._x > high or ne._y < 0 or ne._y > width)
			return 2; // 越界
		if(_people(ne))
			return 1; // 无法移动，该位置正忙
		_people(ol) = nullptr; // 暂时离开
		p->goin(_floor(ne)); // 尝试进入，触发事件 goin
		_people(ne) = p;
		return 0;
	}
};