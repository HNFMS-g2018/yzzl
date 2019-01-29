#include <iostream>
#include <string>
#include "who.h"

int main(void)
{
	std::cout << "User:  " << who::user_name() << std::endl;
	std::cout << "Home:  " << who::user_home() << std::endl;
	std::cout << "Shell: " << who::user_shell() << std::endl;
	std::cout << std::endl;
	std::cout << "User:  " << who::user_name(0) << std::endl;
	std::cout << "Home:  " << who::user_home(0) << std::endl;
	std::cout << "Shell: " << who::user_shell(0) << std::endl;
	return 0;
}
