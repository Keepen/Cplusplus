#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
//��ʯ�����⣺
//	ÿ��ʯ���϶��б�ţ�1��2��3��4...
//	�涨��ʯ��Ĺ���
//		1.����ֻ���ǵ�ǰʯ���ŵ�Լ��
//		2.��Լ�������� 1 �� ����
//		3.������Ŀ��ʯ��ͷ�����С���������򷵻�-1��
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
				//�����Լ������֤����������ȥ
				//����ҪС�ڵ���m
				if (i + j <= m) {
					dp[i + j] = dp[i + j] < dp[i] + 1 ? dp[i + j] : dp[i] + 1;
				}
				//i/j����������һ��Լ��
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
