#include <iostream>
#include <string>
using namespace std;
//替换空格：将源字符串中的空格 替换成 "%20"

//方法一：利用string类
class solution {
public:
	void replaceSpace(char* str, int length) {
		string key;
		while (str) {
			if (*str == ' ') {
				key += "%20";
			}
			else {
				key += *str;
			}
			str++;
		}
		auto ret = key.c_str();
		strcpy(str, ret);
	}
};

//方法二：从后向前替换
class Solution {
public:
	void replaceSpace(char* str, int length) {
		int count = 0;	//用来统计字符串中空格的数目
		for (int i = 0; i<length; i++) {
			if (str[i] == ' ') {
				count++;
			}
		}
		for (int i = length - 1; i >= 0; i--) {
			if (str[i] == ' ') {
				count--;
				str[i + 2 * count] = '%';
				str[i + 2 * count + 1] = '2';
				str[i + 2 * count + 2] = '0';
			}
			else {
				str[i + 2 * count] = str[i];
			}
		}
	}
};


int main() {

	system("pause");
	return 0;
}