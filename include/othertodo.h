#ifndef othertodo_H
#define othertodo_H
#include <vector>
#include <utility>
namespace people {
	class People;
};
namespace othertodo {
	class Queue {
	protected:
		static std::vector<std::pair<people::People *, int> > _vector;
		std::vector<people::People *> _self_vector;
	public:
		void add_people(people::People*);
		void todo();
		Queue();
		~Queue();
	};
};
#endif
