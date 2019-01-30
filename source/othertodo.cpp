#include "../include/othertodo.h"
#include "../include/all_people.h"

namespace othertodo {
	std::vector<people::People *> Queue::_vector;
	Queue::Queue() {
	}
	void Queue::add_people(people::People* p) {
		_vector.push_back(p);
	}
	void Queue::todo() {
		for(auto p : _vector) {
			p->todo();
		}
	}
};
