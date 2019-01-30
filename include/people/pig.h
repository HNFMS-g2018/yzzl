#ifndef pig_H
#define pig_H
#include "people.h"
namespace people {
	class Pig: public People {
	protected:
		void _todo();
	public:
		Pig();
		~Pig();
	};
};
#endif
