#ifndef WHO_H_
#define WHO_H_

#include <unistd.h>
#include <string>

namespace who {
	std::string get_user_home(uid_t uid);
	std::string get_user_shell(uid_t uid);
	std::string get_user_name(uid_t uid);

	std::string current_user_name(void);
	std::string current_user_shell(void);
	std::string current_user_home(void);
};

#endif /* WHO_H_ */
