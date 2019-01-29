#include <pwd.h>
#include <unistd.h>
#include <string>

namespace who {
	extern std::string get_user_home(uid_t uid)
	{
		struct passwd *pass = getpwuid(uid);
		return std::string(pass->pw_dir);
	}

	extern std::string get_user_shell(uid_t uid)
	{
		struct passwd *pass = getpwuid(uid);
		return std::string(pass->pw_shell);
	}

	extern std::string get_user_name(uid_t uid)
	{
		struct passwd *pass = getpwuid(uid);
		return std::string(pass->pw_name);
	}

	extern std::string current_user_name(void)
	{
		return get_user_name(geteuid());
	}

	extern std::string current_user_shell(void)
	{
		return get_user_shell(geteuid());
	}

	extern std::string current_user_home(void)
	{
		return get_user_home(geteuid());
	}
};
