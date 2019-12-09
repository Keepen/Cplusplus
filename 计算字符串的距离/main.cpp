#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

//�༭���룺����ʵ�ֵĲ����У����롢ɾ�����滻
//	�����ַ���a, b
//		1.a�ĳ�����0ʱ��a --> b, ��������ٲ������ǲ���b�ĳ�����ô����ַ�
//		   b --> a, ��������ٲ�������ɾ��b�ĳ�����ô����ַ�
//		2.b�ĳ�����0ʱ��ͬ����1
//		3.�м�״̬���������ȶ�����0, a��ǰi���ַ�Ҫ���b��ǰj���ַ�����Ĳ�����
//			�ڲ��롢ɾ�����滻��ѡ�����ٵĲ��輴�ɡ�
//			f(i, j) -- ��a��ǰi���ַ� ��� b��ǰj���ַ�����Ҫ����С�ı༭����
//		 f(i, j) = min{f(i, j - 1) + 1 , ɾ��һ���ַ�
//					f(i - 1, j) + 1, ����һ���ַ�
//					f(i - 1)(j - 1) + (a[i] == b[j] ? 0 : 1)  �滻һ���ַ����жϸ�λ�õ������ַ��Ƿ����
//					}
//		



int distance(string& a, string& b) {
	int n = (int)a.size();
	int m = (int)b.size();
	vector<vector<int>> dp(n + 1, vector<int>(m + 1));
	//��ʼ����һ�С���һ��
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