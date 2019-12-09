#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

//编辑距离：可以实现的操作有：插入、删除、替换
//	两个字符串a, b
//		1.a的长度是0时，a --> b, 所需的最少操作就是插入b的长度这么多个字符
//		   b --> a, 所需的最少操作就是删除b的长度这么多个字符
//		2.b的长度是0时，同理于1
//		3.中间状态：两个长度都不是0, a的前i个字符要变成b的前j个字符所需的操作是
//			在插入、删除、替换中选择最少的步骤即可。
//			f(i, j) -- 从a的前i个字符 变成 b的前j个字符所需要的最小的编辑距离
//		 f(i, j) = min{f(i, j - 1) + 1 , 删除一个字符
//					f(i - 1, j) + 1, 增加一个字符
//					f(i - 1)(j - 1) + (a[i] == b[j] ? 0 : 1)  替换一个字符，判断该位置的两个字符是否相等
//					}
//		



int distance(string& a, string& b) {
	int n = (int)a.size();
	int m = (int)b.size();
	vector<vector<int>> dp(n + 1, vector<int>(m + 1));
	//初始化第一行、第一列
	for (int i = 0; i < n + 1; ++i) {
		dp[i][0] = i;
	}
	for (int i = 0; i < m + 1; ++i) {
		dp[0][i] = i;
	}

	for (int i = 1; i < n + 1; ++i) {
		for (int j = 1; j < m + 1; ++j) {
			int d1 = dp[i][j - 1] + 1, d2 = dp[i - 1][j] + 1, d3 = dp[i - 1][j - 1];
			if (a[i - 1] != b[i - 1]) {
				d3 += 1;
			}
			dp[i][j] = min(min(d1, d2), d3);
		}
	}
	return dp[n][m];
}

int main() {
	string a, b;
	while (cin >> a >> b) {
		cout << distance(a, b) << endl;
	}
	system("pause");
	return 0;
}