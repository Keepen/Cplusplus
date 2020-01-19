#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
	vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
		vector<int> ret;
		if (k > (int)input.size() || k <= 0) {
			return ret;
		}
		sort(input.begin(), input.end());
		size_t i = 0;
		while (k--) {
			ret.push_back(input[i++]);
		}
		return ret;
	}
};


void test() {
	int size;
	while (cin >> size) {
		vector<int> a;
		int k = 0;
		cin >> k;
		for (int i = 0; i < k; ++i) {
			a.push_back(i + 1);
		}
		Solution s;
		vector<int> ret;
		ret = s.GetLeastNumbers_Solution(a, k);
		for (auto& e : ret) {
			cout << e << " ";
		}
		cout << endl;
	}
}

int main() {
	test();
	system("pause");
	return 0;
}