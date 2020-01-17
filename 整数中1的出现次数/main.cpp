#include <iostream>
using namespace std;

class Solution {
public:
	int Count1(int n) {
		int key = 0;
		while (n) {
			if (n % 10 == 1) {
				++key;
			}
			n /= 10;
		}
		return key;
	}
	int NumberOf1Between1AndN_Solution(int n)
	{
		int count = 0;
		while (n) {
			count += Count1(n);
			--n;
		}
		return count;
	}
};


int main() {
	int n;
	while (cin >> n) {
		if (n == 0) {
			break;
		}
		Solution s;
		cout << s.NumberOf1Between1AndN_Solution(n) << endl;
	}
	system("pause");
	return 0;
}