#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//连续子数组的最大和：

//分析：
//	1.状态设置：以数组下下标作为某一子序列的尾部
//	2.转移方程：f(i) = max(f(i - 1) + array[i], array[i]);
//	3.由于要的是连续的子序列 -- 所以设置状态时必须是以某元素结尾的子序列

int max_add(vector<int> array) {
	int len = array.size();
	int* f = new int[len];
	int Max = array[0];
	f[0] = array[0];
	for (int i = 1; i < len; ++i) {
		f[i] = max(f[i - 1] + array[i], array[i]);
		if (Max < f[i]) {
			Max = f[i];
		}
	}
	return Max;
}


int main() {
	int n;
	while (cin >> n) {
		vector<int> key;
		for (int i = 0; i < n; ++i) {
			cin >> key[i];
		}
		cout << max_add(key) << endl;
	}
	system("pause");
	return 0;
}