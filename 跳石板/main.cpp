#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
//跳石板问题：
//	每个石板上都有编号：1，2，3，4...
//	规定跳石板的规则：
//		1.步数只能是当前石板编号的约数
//		2.该约数不能是 1 或 自身。
//		3.能跳到目标石板就返回最小步数；否则返回-1；
typedef unsigned int u_int;
#define MAX 1000000

int solu() {
	int n, m;
	cin >> n >> m;
	vector<int> dp(m + 1, MAX);
	dp[n] = 0;
	for (int i = n; i < m + 1; i++) {
		for (int j = 2; j * j <= i; j++) {
			if (i % j == 0) {
				//如果是约数，就证明可以跳过去
				//并且要小于等于m
				if (i + j <= m) {
					dp[i + j] = dp[i + j] < dp[i] + 1 ? dp[i + j] : dp[i] + 1;
				}
				//i/j即是它的另一个约数
				if (i + i / j <= m) {
					dp[i + i / j] = dp[i + i / j] < dp[i] + 1 ? dp[i + i / j] : dp[i] + 1;
				}
			}
		}
	}
	if (dp[m] == MAX) {
		return -1;
	}
	return dp[m];
}


int main() {

	cout << solu() << endl;
	system("pause");
	return 0;
}
