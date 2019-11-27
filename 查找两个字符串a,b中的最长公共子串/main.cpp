#include <iostream>
#include <string>
using namespace std;

void fun(string& little, string& big) {
	int num = little.size();
	int key = 1 + (num - 1) * (num + 2) / 2;    //小串的子串数目
	string::iterator head = little.begin();
	int max = 0;        //当前最大公共子串
	int last_max = 0;   //上一次最大公共子串
	string::iterator it = little.begin();
	string::iterator last_it = it;
	while (head != little.end()) {
		string::iterator tail = little.end();
		while (tail != head) {
			string tmp(head, tail);
			if (big.find(tmp) != string::npos) {
				max = tmp.size();
				it = head;
				if (last_max < max) {
					last_max = max;
					last_it = head;
				}
			}
			tail--;
		}
		head++;
	}
	while (last_max) {
		cout << *last_it;
		last_max--;
		++last_it;
	}
	cout << endl;
}

int main() {
	string s1, s2;
	while (cin >> s1 >> s2) {
		string little, max;
		if (s1.size() < s2.size()) {
			little = s1;
			max = s2;
		}
		else {
			little = s2;
			max = s1;
		}
		fun(little, max);
	}
	return 0;
}
