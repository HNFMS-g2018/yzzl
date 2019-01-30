#ifndef othertodo_H
#define othertodo_H
#include <vector>
namespace people {
	class People;
};
namespace othertodo {
	class Queue {
	protected:
		static std::vector<people::People *> _vector;
	public:
		void add_people(people::People*);
		void todo();
		Queue();
	};
};
#endif
