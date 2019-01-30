#include "../include/othertodo.h"
#include "../include/all_people.h"

namespace othertodo {
	std::vector<std::pair<people::People *, int> > Queue::_vector;
	Queue::Queue() {
	}
	Queue::~Queue() {
		for(auto p : _self_vector)
			delete p;
	}
	void Queue::add_people(people::People* p) {
		_vector.push_back(std::make_pair(p, 0));
		_self_vector.push_back(p);
	}
	void Queue::todo() {
		for(auto &pr : _vector)
			if(pr.first -> get_map()) {
				if(not pr.second) {
					pr.first->todo();
					pr.second = pr.first -> speed;
				}
				else {
					pr.second --;
				}
			}
	}
};
