//我们可以用2 * 1的小矩形横着或者竖着去覆盖更大的矩形。请问用n个2 * 1的小矩形无重叠地覆盖一个2*n的大矩形，总共有多少种方法？
#include <iostream>
using namespace std;


//分析：考虑密铺：
//	可以横着放，也可以竖着放
//	所以F（n） = F（n - 1） + F（n - 2）；

class Solution {
public:
	int rectCover(int number) {
		if (number < 3) {
			return number;
		}
		int left = 1, right = 2;
		int ret = 0;
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
		cout << s.rectCover(number) << endl;
	}
	system("pause");
	return 0;
}