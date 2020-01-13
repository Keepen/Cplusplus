#include <iostream>
#include <vector>
using namespace std;
//˳ʱ���ӡ����
//	˼·��
//		1.�������ǣ��ң� �£� �� �ϣ�ѭ����
//		2.�����в�ͬ�� ÿ������һ�֣���Ҫ�ߵ���Ŀ-1�� ��Ҫ�ߵ���ĿҲҪ��1


class Solution {
public:
	vector<int> printMatrix(vector<vector<int> > matrix) {
		vector<int> ret;	//������
		if (matrix.size() == 1 || matrix[0].size() == 1) {
			for (size_t i = 0; i < matrix.size(); ++i) {
				for (size_t j = 0; j < matrix[0].size(); ++j) {
					ret.push_back(matrix[i][j]);
				}
			}
			return ret;
		}
		int i = 0, j = 0;	//������ʾ�±�
		size_t num = 1;	//��ʾ�Ѿ�����˶���Ԫ��
		size_t count_row = matrix.size() - 1;		//��ʾÿһ�֣��У���Ҫ�߹���Ԫ����Ŀ
		size_t count_col = matrix[0].size();		//ÿһ������Ҫ�߹�����Ŀ
		size_t cur = 1;		//��ǰ���Ѿ���ŵ�Ԫ����Ŀ
		int flag = 1;	//��ʾ�����Ĺ켣�� �ң� �£� �� ��
		ret.push_back(matrix[i][j]);
		size_t res = matrix.size()*matrix[0].size();
		while (num < res) {
			++cur;
			//������
			if (flag == 1) {
				++j;
				ret.push_back(matrix[i][j]);
				if (cur >= count_col) {
					++flag;
					--count_col;	//count��ֵ��Ҫ�� 1
					if (count_col < 0) {
						count_col = 0;
					}
					cur = 0;
				}
			}
			//������
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
			//������
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
			//������
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