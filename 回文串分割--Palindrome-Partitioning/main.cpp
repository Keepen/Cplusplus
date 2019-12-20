#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
//回文串的分割次数：
//	分析：
//		1.定义状态：F（i） -- 表示前i个字符需要分割的次数
//		
//		2.F（i） = j < i && [j + 1, i）是回文串时，只需要找出前面分割次数最小的再 + 1就行
//		3.整体是回文串时，需要分割的次数就是0



class Solution {
public:
	//判断是否时回文串
	bool isPal(string& s, int start, int end) {
		while (start < end) {
			if (s[start] != s[end]) {
				return false;
			}
			++start;
			--end;
		}
		return true;
	}
	int minCut(string s) {
		int n = (int)s.size();
		vector<int> dp(n + 1, 0);
		for (int i = 0; i < n + 1; ++i) {
			dp[i] = i - 1;
		}
		for (int i = 1; i <= n; ++i) {
			for (int j = 0; j < i; ++j) {
				if (isPal(s, j, i - 1)) {
					dp[i] = min(dp[i], dp[j] + 1);
				}
			}
		}
		return dp[n];
	}
};

int main() {
	system("pause");
	return 0;
}
