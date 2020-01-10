#include <iostream>
#include <vector>
using namespace std;

//问题描述：调整数组中的数字使得奇数全部位于偶数前面
//	不能改变数字的相对位置，奇数与奇数之间，偶数与偶数之间

//分析：先拷贝整个数组
//	先调整奇数：顺序遍历数组中的数字
//	再调整偶数：倒序遍历数组中的数字
class Solution {
public:
	void reOrderArray(vector<int> &array) {
		vector<int> tmp(array);
		int k = 0;
		size_t sz = array.size();
		for (int i = 0; i < array.size(); ++i) {
			if (tmp[i] & 1) {
				array[k] = tmp[i];
				++k;
			}
		}
		k = 1;
		for (int i = sz - 1; i >= 0; --i) {
			if (tmp[i] % 2 == 0) {
				array[sz - k] = tmp[i];
				++k;
			}
		}
	}
};


int main() {

	system("pause");
	return 0;
}