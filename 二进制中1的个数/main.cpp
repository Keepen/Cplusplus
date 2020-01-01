#include <iostream>
using namespace std;
class Solution {
public:
	int  NumberOf1(int n) {
		int ret = 0;
		for (int i = 0; i < 32; ++i) {
			if ((n >> i) & 1) {
				++ret;
			}
		}
		return ret;
	}
};

int main() {
	Solution s;
	int n;
	while (cin >> n) {
		cout << s.NumberOf1(n) << endl;
	}
	system("pause");
	return 0;
}