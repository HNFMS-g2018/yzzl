#ifndef pig_H
#define pig_H
#include "people.h"
namespace people {
	class Pig: public People {
	protected:
		void _todo();
		int _meet(People *);
	public:
		Pig();
		~Pig();
	};
};
#endif
