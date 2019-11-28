#include <iostream>
#include <string>
using namespace std;


//返回两个字符串中最长公共字符串的长度

int Max(string& little, string& big) {
	//int len = 0;
	int max = 0;
	int last_max = max;
	string::iterator head = little.begin();
	while (head != little.end()) {
		string::iterator tail = little.end();
		while (tail != head) {
			string tmp(head, tail);
			if (big.find(tmp) != string::npos) {
				max = tmp.size();
				if (last_max < max) {
					last_max = max;
				}
			}
			tail--;
		}
		head++;
	}
	return last_max;
}

int main() {
	string s1, s2;
	while (cin >> s1 >> s2) {
		string little, big;
		if (s1.size() < s2.size()) {
			little = s1;
			big = s2;
		}
		else {
			little = s2;
			big = s1;
		}
		cout << Max(little, big) << endl;
	}
	return 0;
}