//问题描述：
//	有n种颜色的手套，先用两个数组来存放左右手对应颜色的手套数目
//	现需拿手套若干只，只能分辨出左右而不能分辨出颜色
//	问最少需要拿多少只手套才能保证至少有一对颜色相同
//	颜色 n [1, 13], 且每个数组内手套的数目均不超过26
//测试样例：4, [0, 7, 1, 6], [1, 5, 0, 6]
//返回：10(解释：可以左手手套取2只，右手手套取8只)

//思路：
//	两种情况：有0和没有0
//	没有0：
//		当手套的数目不为0时，那么就求出能覆盖到n种颜色的手套的和：
//			即，sum = 所有非0的和 - 最小的数目 + 1； 就可以覆盖到左右的颜色
//	有0：
//		手套数目是0时，对应颜色的另一只手的手套需要全部拿走
//	最后结果 = 每一堆能够覆盖到所有颜色的手套的和取较小者 + 1 + 为0时的对应颜色的另一只手的手套数目



#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Gloves {
public:
	int findMin(int n, vector<int> left, vector<int> right) {
		int sum = 0;
		int leftSum = 0, rightSum = 0;
		int leftMin = 30, rightMin = 30;
		for (int i = 0; i < n; i++) {
			//当某种颜色手套为0只时，全部拿走
			if (left[i] * right[i] == 0) {
				sum += left[i] + right[i];
			}
			//否则，计算出两堆能够覆盖到所有颜色的较小值
			else {
				leftSum += left[i];
				rightSum += right[i];
				leftMin = min(leftMin, left[i]);
				rightMin = min(rightMin, right[i]);
			}
		}
		return sum + min(leftSum + 1, rightSum + 1) + 1;
	}
};

int main() {


	system("pause");
	return 0;
}
