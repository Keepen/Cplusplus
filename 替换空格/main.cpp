#include <iostream>
#include <string>
using namespace std;
//�滻�ո񣺽�Դ�ַ����еĿո� �滻�� "%20"

//����һ������string��
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

//���������Ӻ���ǰ�滻
class Solution {
public:
	void replaceSpace(char* str, int length) {
		int count = 0;	//����ͳ���ַ����пո����Ŀ
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