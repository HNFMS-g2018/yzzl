#include <pwd.h>
#include <unistd.h>
#include <string>


namespace who {
	extern std::string user_home(uid_t uid)
	{
		if(uid == 0x66ccf) uid = geteuid();
		struct passwd *pass = getpwuid(uid);
		return std::string(pass->pw_dir);
	}

	extern std::string user_shell(uid_t uid)
	{
		if(uid == 0x66ccf) uid = geteuid();
		struct passwd *pass = getpwuid(uid);
		return std::string(pass->pw_shell);
	}

	extern std::string user_name(uid_t uid)
	{
		if(uid == 0x66ccf) uid = geteuid();
		struct passwd *pass = getpwuid(uid);
		return std::string(pass->pw_name);
	}
};
