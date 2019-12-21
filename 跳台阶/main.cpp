#include <iostream>
using namespace std;
//青蛙一次能跳一级，也可以跳两级台阶
//	问跳到number级 的 方法总数
//	分析：考虑最后一步跳一级，和最后一步跳两级的情况，两种情况之和就是总数
//		该题就是一个类似于斐波那契数列的问题
//		状态转移方程：
//			F(n) = F(n - 1) + F(n - 2);
//	解决方案：1.递归
//			 2.循环：复杂度小


class Solution {
public:
	int jumpFloor(int number) {
		if (number < 3) {
			return number;
		}
		int left = 1, right = 2, ret = 0;
		while (number >= 3) {
			ret = left + right;
			left = right;
			right = ret;
			--number;
		}
		return ret;
	}
};

int main() {
	Solution s;
	int number;
	while (cin >> number) {
		if (number == 0) {
			break;
		}
		cout << s.jumpFloor(number) << endl;
	}
	system("pause");
	return 0;
}