#include <iostream>
#include <vector>
#include <stack>
#include <map>
using namespace std;

//��ά���飺0---��ͨ��
//		   1---����ͨ��
//	�����ͨ����·��--·��ֻ��һ��




void solu() {
	int n, m;
	while (cin >> n >> m) {
		vector<int> vm(m, 0);
		vector<vector<int>> ret(n, vm);
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				cin >> ret[i][j];
			}
		}
		stack<pair<int, int>> s;
		int i = 0, j = 0;
		while (!(i == n - 1 && j == m - 1)) {
			if (ret[i][j] == 0) {
				s.push(make_pair(i, j));
				if (i < n - 1 && ret[i + 1][j] == 0) {
					++i;//��ѡ�����ߣ�
				}
				//�±�û��·���ұ���·�����ұ���
				else if (j < m - 1 && ret[i][j + 1] == 0) {
					++j;
				}
				//û��·�����ݵ���һ�γ��ֲַ�·�ڵ�ʱ��
				else {
					pair<int, int> tmp = s.top();
					i = tmp.first;
					j = tmp.second;
					while ((i < n - 1 && j < m - 1 && (ret[i][j + 1] == 1 || ret[i + 1][j] == 1))
						|| (i == n - 1 && j != m - 1)
						|| (j == m - 1 && i != n - 1)) {
						s.pop();
						tmp = s.top();
						i = tmp.first;
						j = tmp.second;
					}
					//�޸�·��Ϊ�����ߡ�
					++j;
				}
			}
		}
		s.push(make_pair(n - 1, m - 1));
		stack<pair<int, int>> result;
		while (!s.empty()) {
			result.push(s.top());
			s.pop();
		}
		while (!result.empty()) {
			pair<int, int> tmp = result.top();
			cout << "(" << tmp.first << "," << tmp.second << ")" << endl;
			result.pop();
		}
	}
}
int main() {
	solu();
	return 0;
}