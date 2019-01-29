#include "../../include/people/player.h"
#include "../../include/cursor.h"
#include "../../include/color.h"
#include "../../include/all_map.h"
#include "../../include/all_floor.h"
#include "../../include/input.h"
#include "../../include/begin_flash.h"

namespace people {
	Player::Player():
		People(new color::Blue, '@', 3, 1000) {
	}
	Player::~Player() {
	}
	char Player::_get_face() {
		switch(_fg) {
			case 'h': return '<';
			case 'j': return 'v';
			case 'k': return '^';
			case 'l': return '>';
			default: return face;
		}
	}
	int Player::login(std::string name, std::string pass) {
		// 在接口调好之前，先用着吧， ~~不碍事~~
		int res =
			system(("python3 python/user_login.py " + name  + " " + pass + " l").c_str());
		if(res == 0) {
			FILE *read =fopen("py_output", "r");
			fscanf(read, "exp: %lld\n", &m_exp);
		}
		return res;
	}
	int Player::regis(std::string name, std::string pass) {
		// 在接口调好之前，先用着吧， ~~不碍事~~
		int res =
			system(("python3 python/user_login.py " + name  + " " + pass + " r").c_str());
		if(res == 0) {
			FILE *read =fopen("py_output", "r");
			fscanf(read, "exp: %lld\n", &m_exp);
		}
		return res;
	}
	void Player::_print_map(int high, int width) {
		cursor::clear_screen();
		cursor::set_to(0, 0);
		for(int i=-high; i<=high; i++) {
			for(int j=-width; j<=width; j++) {
				if(not i and not j) { // Player 本身
					color->change_fore();
					putchar(_get_face());
				}
				else {
					People *p = get_map()->get_people(get_pos(), i, j);
					if(p) { // 该位置有人
						p->color->change_fore();
						putchar(p->face);
					} else {
						floor::Floor *f = get_map()->get_floor(get_pos(), i, j);
						if(f) {
							f->color->change_fore();
							putchar(f->face);
						} else {
							color->reset_fore();
							putchar(' ');
						}
					}
				}
			}
			std::cout << std::endl;
		}
		color->reset_fore();
	}
	void Player::_print_info(int high, int width) {
		cursor::set_to(1, width + 1);
		printf("当前位置：%s (%d, %d)\n",
				get_map()->name.c_str(), get_pos()._x, get_pos()._y);
		cursor::set_to(2, width + 1);
		printf("Your HP: ");
		begin_flash::progress_bar(double(m_hp) / get_hpmax(), 20);
		cursor::set_to(high, 0);
		// To do something
	}
	void Player::_analyze_choose(char cs) {
		pos::Pos ps = get_pos();
		switch(cs) {
			case 'h': _fg = 'h'; move(pos::Pos(ps._x, ps._y - 1)); break;
			case 'j': _fg = 'j'; move(pos::Pos(ps._x + 1, ps._y)); break;
			case 'k': _fg = 'k'; move(pos::Pos(ps._x - 1, ps._y)); break;
			case 'l': _fg = 'l'; move(pos::Pos(ps._x, ps._y + 1)); break;
			default: _fg = ' '; break;
		}
	}
	void Player::_todo() {
		const int high = 6, width = 6; // 视野半径
		_print_map(high, width);
		begin_flash::box(pos::Pos(0, width * 2 + 1), 5, 40, 0);
		_print_info(high << 1 | 1, width << 1 | 1);
		int choose = input::ifgetch(0.2);
		if(~ choose)
			_analyze_choose(choose);
		else
			_fg = ' ';
	}
};

