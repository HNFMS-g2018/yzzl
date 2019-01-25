#include "../include/all_people.h"
#include "../include/users.h"
#include "../include/begin_flash.h"
#include "../include/input.h"
#include "../include/cursor.h"

static std::string get_name(std::string name, bool hide) {
	cursor::clear_screen();
	cursor::set_to(0, 0);
	char res[11];
	begin_flash::flash("请输入" + name + "：", false);
	int ch, size = 0;
	const char *info = " qwq ";
	while(size < 10) {
		printf("----------|| %d/%d \n", size, 10);
		printf("1. %s由大写或小写字母或数字组成\n", name.c_str());
		printf("2. %s长度不超过 10\n", name.c_str());
		printf("3. 按 Enter 确认\n");
		printf("4. 按 Ctrl-H 删除\n");
		printf("%s\n", info);
		cursor::up(6);
		for(int i=0; i<size; i++)
			putchar(hide ? '*' : res[i]);
		cursor::to_head();
		ch = input::getch();
		if(ch == '\n' or ch == '\r') break;
		else if(ch == 127) { // Backspace
			if(not size)
				info = (name + "已空     ").c_str();
			else {
				size --;
				info = "             ";
			}
		} else if((ch >= 'a' and ch <= 'z') or (ch >= 'A' and ch <= 'Z')
				or (ch >= '0' and ch <= '9')) {
			res[size ++] = ch;
			info = "             ";
		} else
			info = "非法字符     ";
	}
	return (std::string)res;
}

namespace users {
	int login(people::Player *p, bool regis) {
		std::string name = get_name("用户名", false);
		if(name.empty()) {
			puts("用户名为空！");
			return 1;
		}
		std::string pass = get_name("密码", true);
		if(pass.empty()) {
			puts("密码为空！");
			return 1;
		}
		if (regis) {
			if(pass != get_name("密码", true)) {
				puts("密码不匹配！");
				return 2;
			}
			p->regis(name, pass);
		} else {
			p->login(name, pass);
		}
		return 0;
	}
};
