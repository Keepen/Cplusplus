#include <iostream>
using namespace std;

//��Ŀ���������n��쳲��������У���0����0
//	1.�ݹ飺�򵥣������Ӷȴ�
//	2.ѭ������ʡʱ��

class Solution {
public:
	int Fibonacci(int n) {
		if (n == 0) {
			return 0;
		}
		else if (n == 1 || n == 2) {
			return 1;
		}
		int last = 1, second = 1;
		int tmp = n;
		int ret = 0;
		while (tmp >= 3) {
			ret = last + second;
			second = last;
			last = ret;
			--tmp;
		}
		return ret;
	}
};


int main() {
	int n;
	while (cin >> n) {
		Solution s;
		cout << s.Fibonacci(n) << endl;
	}
	system("pause");
	return 0;
}