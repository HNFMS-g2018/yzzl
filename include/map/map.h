#ifndef map_H
#define map_H
#include "../pos.h"
#include "../othertodo.h"
namespace people {
	class People;
};
namespace floor {
	class Floor;
};
namespace map {
	class Map {
	protected:
		pos::Coord_map<floor::Floor*> _floor;
		pos::Coord_map<people::People*> _people;
		othertodo::Queue _que;
	public:
		int high, width;
		std::string name;
		int people_move(people::People*, pos::Pos, pos::Pos);
		virtual pos::Pos recieve(people::People *) = 0;
		floor::Floor *get_floor(pos::Pos, int, int);
		people::People *get_people(pos::Pos, int, int);
		Map(int, int, std::string);
		virtual ~Map();
	};
};
#endif
