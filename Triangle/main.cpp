#include <iostream>
#include <algorithm>
#include <vector>
//���Ǿ��󣺴ӵ�һ�е����һ�е����·����
//	ÿһ��Ԫ��ֻ�������·��������·��ƶ���


using namespace std;
class Solution {
public:
	int minimumTotal(vector<vector<int> > &triangle) {
		vector<vector<int>> dp(triangle.size() + 1,
			vector<int>(triangle.size() + 1, 0));
		for (int i = 1; i < triangle.size() + 1; ++i) {
			for (int j = 1; j <= i; ++j) {
				if (j == 1) {
					dp[i][j] = dp[i - 1][j] + triangle[i - 1][j - 1];
				}
				else if (j == i) {
					dp[i][j] = dp[i - 1][j - 1] + triangle[i - 1][j - 1];
				}
				else {
					dp[i][j] = min(dp[i - 1][j], dp[i - 1][j - 1]) + triangle[i - 1][j - 1];
				}
			}
		}
		int min = dp[triangle.size()][1];
		for (int i = triangle.size(), j = 1; j < triangle[triangle.size() - 1].size() + 1; ++j) {
			if (min > dp[i][j]) {
				min = dp[i][j];
			}
		}
		return min;
	}
};


int main() {

	system("pause");
	return 0;
}