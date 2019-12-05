#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//��������������ͣ�

//������
//	1.״̬���ã����������±���Ϊĳһ�����е�β��
//	2.ת�Ʒ��̣�f(i) = max(f(i - 1) + array[i], array[i]);
//	3.����Ҫ���������������� -- ��������״̬ʱ��������ĳԪ�ؽ�β��������

int max_add(vector<int> array) {
	int len = array.size();
	int* f = new int[len];
	int Max = array[0];
	f[0] = array[0];
	for (int i = 1; i < len; ++i) {
		f[i] = max(f[i - 1] + array[i], array[i]);
		if (Max < f[i]) {
			Max = f[i];
		}
	}
	return Max;
}


int main() {
	int n;
	while (cin >> n) {
		vector<int> key;
		for (int i = 0; i < n; ++i) {
			cin >> key[i];
		}
		cout << max_add(key) << endl;
	}
	system("pause");
	return 0;
}