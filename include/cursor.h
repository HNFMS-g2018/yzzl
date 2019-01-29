#ifndef cursor_H
#define cursor_H
namespace cursor {
	void up(int=1);
	void down(int=1);
	void left(int=1);
	void right(int=1);
	void to_head();
	void clear_screen();
	void set_to(int, int);
	void back(int=1);
	void hide();
	void display();
};
#endif

