#include <iostream>
using namespace std;

// 3个空瓶可以换一瓶汽水
//	换来的汽水喝完后可以继续换
//	最多可以向老板借一瓶汽水

int bottle(int n) {
	int sum = 0;
	while (n > 1) {
		int ret = n / 3;
		int left = n % 3;
		sum = sum + left;
		n = ret + left;
		if (n == 2) {
			++sum;
			break;
		}
	}
	return sum;
}

int main() {
	int n;
	while (cin >> n) {
		cout << bottle(n) << endl;
	}

	system("pause");
	return 0;
}