#include <iostream>
#include <string>
using namespace std;
//	? 匹配一个字符
//	* 匹配0个或多个字符--数字/字母

bool match(const char* patten, const char* str) {
	//两者同时结束--匹配成功
	if (*patten == '\0' && *str == '\0') {
		return true;
	}
	//两者只有其一结束，匹配失败
	if (*patten == '\0' || *str == '\0') {
		return false;
	}
	//碰到? -- 都向后走一个字符
	if (*patten == '?' || *str == '?') {
		return match(patten + 1, str + 1);
	}
	//任意一个是* -- 不走，两者都走，只走一个
	else if (*patten == '*' || *str == '*') {
		return match(patten, str + 1) || match(patten + 1, str + 1) ||
			match(patten + 1, str);
	}
	//当前字符匹配--继续匹配下一个字符
	else if (*patten == *str) {
		return match(patten + 1, str + 1);
	}
	return false;
}

int main() {
	string s1, s2;
	while (cin >> s1 >> s2) {
		if (match(s1.c_str(), s2.c_str())) {
			cout << "true" << endl;
		}
		else {
			cout << "false" << endl;
		}
	}
	return 0;
}