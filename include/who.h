#ifndef WHO_H_
#define WHO_H_

#include <unistd.h>
#include <string>

namespace who {
	std::string user_home(uid_t uid = 0x66ccf);
	std::string user_shell(uid_t uid = 0x66ccf);
	std::string user_name(uid_t uid = 0x66ccf);
};

#endif /* WHO_H_ */
