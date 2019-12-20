#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
//���Ĵ��ķָ������
//	������
//		1.����״̬��F��i�� -- ��ʾǰi���ַ���Ҫ�ָ�Ĵ���
//		
//		2.F��i�� = j < i && [j + 1, i���ǻ��Ĵ�ʱ��ֻ��Ҫ�ҳ�ǰ��ָ������С���� + 1����
//		3.�����ǻ��Ĵ�ʱ����Ҫ�ָ�Ĵ�������0



class Solution {
public:
	//�ж��Ƿ�ʱ���Ĵ�
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
