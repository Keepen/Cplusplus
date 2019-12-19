//问题描述：
/*有 n 个物品和一个大小为 m 的背包.给定数组 A 表示每个物品的大小和数组 V 表示每个物品的价值.
问多能装入背包的总价值是多大 */

//分析：
//1.定义状态：F[i][j] -- 背包大小为j，装前i个物品的最大价值
//2.对于每一个背包来说：要么放，要么不放
//		放：F[i][j] = F[i - 1][j]
//	  不放：
//		1）够放：	F[i][j] = F[i - 1][j] + V[i]
//		2）不够放：	F[i][j] = F[i - 1][j - A[i]] + V[i]
//	  不放时的最大价值就是 1)和 2）中的较大值
//	F[i][j] 就是放与不放中的较大者
//3.最后最大值就是F[n][m]




#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
	/**
	* @param m: An integer m denotes the size of a backpack
	* @param A: Given n items with size A[i]
	* @param V: Given n items with value V[i]
	* @return: The maximum value
	*/
	int backPackII(int m, vector<int> &A, vector<int> &V) {
		// write your code here
		int num = (int)A.size();
		vector<vector<int>> dp(m + 1, vector<int>(num + 1, 0));
		for (int i = 1; i <= num; ++i) {
			for (int j = 1; j <= m; ++j) {
				if (A[i] <= j) {
					dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - A[i]]) + V[i];
				}
			}
		}
		return dp[num][m];
	}
};

//优化：
//空间复杂度可以简化为O(M) -- 一维数组，
//注意：一维数组时，需要从后往前进行赋值，否则会覆盖。




int main() {

	system("pause");
	return 0;
}