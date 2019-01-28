#ifndef player_H
#define player_H
#include <iostream>
#include "people.h"
namespace people {
	class Player: public People {
	protected:
		void _todo();
		char _fg; // 当前方向
		char _get_face();
		void _print_map();
		void _print_info();
		void _analyze_choose(char);
	public:
		int login(std::string, std::string);
		int regis(std::string, std::string);
		Player();
		~Player();
	};
};
#endif
