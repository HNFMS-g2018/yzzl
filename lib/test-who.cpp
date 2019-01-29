#include <iostream>
#include <string>
#include "who.h"

int main(void)
{
	std::cout << "User:  " << who::current_user_name() << std::endl;
	std::cout << "Home:  " << who::current_user_home() << std::endl;
	std::cout << "Shell: " << who::current_user_shell() << std::endl;
	std::cout << std::endl;
	std::cout << "User:  " << who::get_user_name(0) << std::endl;
	std::cout << "Home:  " << who::get_user_home(0) << std::endl;
	std::cout << "Shell: " << who::get_user_shell(0) << std::endl;
	return 0;
}
