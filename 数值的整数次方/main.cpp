#include <iostream>
using namespace std;

//�����base��exponent�η�
//	������Ŀ
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