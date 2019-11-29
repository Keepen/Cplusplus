#include <iostream>
#include <string>
using namespace std;
//	? ƥ��һ���ַ�
//	* ƥ��0�������ַ�--����/��ĸ

bool match(const char* patten, const char* str) {
	//����ͬʱ����--ƥ��ɹ�
	if (*patten == '\0' && *str == '\0') {
		return true;
	}
	//����ֻ����һ������ƥ��ʧ��
	if (*patten == '\0' || *str == '\0') {
		return false;
	}
	//����? -- �������һ���ַ�
	if (*patten == '?' || *str == '?') {
		return match(patten + 1, str + 1);
	}
	//����һ����* -- ���ߣ����߶��ߣ�ֻ��һ��
	else if (*patten == '*' || *str == '*') {
		return match(patten, str + 1) || match(patten + 1, str + 1) ||
			match(patten + 1, str);
	}
	//��ǰ�ַ�ƥ��--����ƥ����һ���ַ�
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