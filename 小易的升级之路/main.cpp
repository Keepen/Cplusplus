#include <iostream>
#include <vector>
using namespace std;

//С�׵�����֮·�� С�׵ĳ�ʼ����ֵstart
// ��n������ -- �������� < start === С�׻����������ӹ���������ô��
//				����С�׵������ͻ�����start�͹������������Լ����ô��


int Max(int a, int b) {
	int little = a < b ? a : b;
	int max = 1;
	for (int i = 2; i <= little; ++i) {
		if (a % i == 0 && b % i == 0) {
			if (max < i) {
				max = i;
			}
		}
	}
	return max;
}

int main() {
	int n, start;
	while (cin >> n >> start) {
		vector<int> key(n, 0);
		for (int i = 0; i < n; ++i) {
			cin >> key[i];
		}
		for (int i = 0; i < n; ++i) {
			if (key[i] < start) {
				start += key[i];
			}
			else {
				start += Max(start, key[i]);
			}
		}
		cout << start << endl;
	}
	return 0;
}