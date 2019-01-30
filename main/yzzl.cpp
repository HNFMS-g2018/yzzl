#include "../include/begin_flash.h"
#include "../include/all_people.h"
#include "../include/all_map.h"
#include "../include/users.h"
#include "../include/input.h"
#include "../include/cursor.h"

int main(int, const char **) {
	cursor::hide();
	begin_flash::welcome();
	people::Player *self = new people::Player();
	if(users::login(self))
		return 1;
	map::Map *city = new map::Maincity();
	self->join_map(city);
	while(self->get_map()) {
		self->todo();
	}
	cursor::display();
	remove("py_output");
	/* delete self; */ // emm delete city 的同时会 delete self.
	delete city;
}
