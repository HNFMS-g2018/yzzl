#ifndef player_H
#define player_H
#include <iostream>
#include "people.h"
namespace people {
	class Player: public People {
	protected:
		void _todo();
		int _meet(People *);
		char _fg; // 当前方向
		char _get_face();
		void _print_map(int, int);
		void _print_info(int, int);
		void _analyze_choose(char);
	public:
		int login(std::string, std::string);
		int regis(std::string, std::string);
		Player();
		~Player();
	};
};
#endif
