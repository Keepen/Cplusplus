// write your code here cpp
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

//每一个数字的译码都是四位数字 -- 对应的斐波那契数
//	不够四位--前边补0
//	超过四位--只取最后四位

int fib(int n) {
	if (n == 1) {
		return 1;
	}
	int first = 1, second = 1, ret;
	while (n > 1) {
		ret = (first + second) % 10000;
		second = first;
		first = ret;
		--n;
	}
	return ret;
}

int main() {
	int n;
	while (cin >> n) {
		vector<int> key(n, 0);
		for (int i = 0; i < n; ++i) {
			cin >> key[i];
		}
		for (int i = 0; i < n; ++i) {
			int tmp = fib(key[i]);
			if (tmp < 1000) {
				if (tmp < 100) {
					if (tmp < 10) {
						cout << "000" << tmp;
					}
					else {
						cout << "00" << tmp;
					}
				}
				else {
					cout << "0" << tmp;
				}

			}
			else {
				cout << tmp;
			}
		}
		cout << endl;
	}
}
