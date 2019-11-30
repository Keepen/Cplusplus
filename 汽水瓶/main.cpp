#include <iostream>
using namespace std;

// 3����ƿ���Ի�һƿ��ˮ
//	��������ˮ�������Լ�����
//	���������ϰ��һƿ��ˮ

int bottle(int n) {
	int sum = 0;
	while (n > 1) {
		int ret = n / 3;
		int left = n % 3;
		sum = sum + left;
		n = ret + left;
		if (n == 2) {
			++sum;
			break;
		}
	}
	return sum;
}

int main() {
	int n;
	while (cin >> n) {
		cout << bottle(n) << endl;
	}

	system("pause");
	return 0;
}