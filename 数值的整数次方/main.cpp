#include <iostream>
using namespace std;

//计算出base的exponent次方
//	降智题目
class Solution {
public:
	double Power(double base, int exponent) {
		double ret = pow(base, exponent);
		return ret;
	}
};

int main() {
	double a = 0;
	int b = 0;
	while (cin >> a >> b) {
		if (a == 0 && b == 0) {
			break;
		}
		Solution s;
		cout << s.Power(a, b);
	}
}