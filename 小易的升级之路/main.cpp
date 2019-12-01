#include <iostream>
#include <vector>
using namespace std;

//小易的升级之路： 小易的初始能力值start
// 有n个怪物 -- 怪物能力 < start === 小易会能力会增加怪物能力这么多
//				否则，小易的能力就会增加start和怪物能力的最大公约数这么多


int Max(int a, int b) {
	int little = a < b ? a : b;
	int max = 1;
	for (int i = 2; i <= little; ++i) {
		if (a % i == 0 && b % i == 0) {
			if (max < i) {
				max = i;
			}
		}
	}
	return max;
}

int main() {
	int n, start;
	while (cin >> n >> start) {
		vector<int> key(n, 0);
		for (int i = 0; i < n; ++i) {
			cin >> key[i];
		}
		for (int i = 0; i < n; ++i) {
			if (key[i] < start) {
				start += key[i];
			}
			else {
				start += Max(start, key[i]);
			}
		}
		cout << start << endl;
	}
	return 0;
}