#include <iostream>
#include <vector>
#include <stack>
#include <map>
using namespace std;

//二维数组：0---能通过
//		   1---不能通过
//	输出能通过的路径--路径只有一条




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
					++i;//首选向下走；
				}
				//下边没有路，右边有路，向右边走
				else if (j < m - 1 && ret[i][j + 1] == 0) {
					++j;
				}
				//没有路，回溯到上一次出现分岔路口的时候
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
					//修改路径为向右走。
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