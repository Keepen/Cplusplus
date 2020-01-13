#include <iostream>
#include <vector>
using namespace std;
//顺时针打印矩阵：
//	思路：
//		1.方向按序是：右， 下， 左， 上（循环）
//		2.行与列不同， 每次走完一轮，行要走的数目-1， 列要走的数目也要减1


class Solution {
public:
	vector<int> printMatrix(vector<vector<int> > matrix) {
		vector<int> ret;	//保存结果
		if (matrix.size() == 1 || matrix[0].size() == 1) {
			for (size_t i = 0; i < matrix.size(); ++i) {
				for (size_t j = 0; j < matrix[0].size(); ++j) {
					ret.push_back(matrix[i][j]);
				}
			}
			return ret;
		}
		int i = 0, j = 0;	//用来表示下标
		size_t num = 1;	//表示已经存放了多少元素
		size_t count_row = matrix.size() - 1;		//表示每一轮（行）需要走过的元素数目
		size_t count_col = matrix[0].size();		//每一轮列需要走过的数目
		size_t cur = 1;		//当前轮已经存放的元素数目
		int flag = 1;	//表示遍历的轨迹， 右， 下， 左， 上
		ret.push_back(matrix[i][j]);
		size_t res = matrix.size()*matrix[0].size();
		while (num < res) {
			++cur;
			//向右走
			if (flag == 1) {
				++j;
				ret.push_back(matrix[i][j]);
				if (cur >= count_col) {
					++flag;
					--count_col;	//count的值需要减 1
					if (count_col < 0) {
						count_col = 0;
					}
					cur = 0;
				}
			}
			//向下走
			else if (flag == 2) {
				++i;
				ret.push_back(matrix[i][j]);
				if (cur == count_row) {
					++flag;
					cur = 0;
					--count_row;
					if (count_row < 0) {
						count_row = 0;
					}
				}

			}
			//向左走
			else if (flag == 3) {
				--j;
				ret.push_back(matrix[i][j]);
				if (cur == count_col) {
					++flag;
					cur = 0;
					--count_col;
					if (count_col < 0) {
						count_col = 0;
					}
				}
			}
			//向上走
			else if (flag == 4) {
				--i;
				ret.push_back(matrix[i][j]);
				if (cur == count_row) {
					flag = 1;
					cur = 0;
					--count_row;
					if (count_row < 0) {
						count_row = 0;
					}
				}
			}
			++num;
		}
		return ret;
	}
};

void test() {
	vector<vector<int>> ma(4, vector<int>(4));
	int m = 1;
	for (size_t i = 0; i < ma.size(); ++i) {
		for (size_t j = 0; j < ma[0].size(); ++j) {
			ma[i][j] = m++;
		}
	}
	for (size_t i = 0; i < ma.size(); ++i) {
		for (size_t j = 0; j < ma[0].size(); ++j) {
			cout << ma[i][j] << "\t";
		}
		cout << endl;
	}
	cout << endl;
	Solution s;
	vector<int> res;// (ma.size()*ma.size());
	res = s.printMatrix(ma);
	for (size_t i = 0; i < res.size(); ++i) {
		cout << res[i] << " ";
	}

}
int main() {
	test();
	system("pause");
	return 0;
}