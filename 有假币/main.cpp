#include <iostream>
using namespace std;
//�ٱ������������
//	һ������л����һ�żٱң�������ƽ������Ƽ��β����ҵ��ٱ�
//	һ�γ��������3�ű����ҵ��ٱ�
//	1 -- 3
//	2 -- 9


int main() {
	int n;
	while (cin >> n && n) {
		int ret = 0;
		long long sum = 1;
		while (sum < n) {
			sum *= 3;
			ret++;
		}
		cout << ret << endl;
	}
	system("pause");
	return 0;
}