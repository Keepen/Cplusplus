#include <iostream>
using namespace std;
//����һ������һ����Ҳ����������̨��
//	������number�� �� ��������
//	�������������һ����һ���������һ����������������������֮�;�������
//		�������һ��������쳲��������е�����
//		״̬ת�Ʒ��̣�
//			F(n) = F(n - 1) + F(n - 2);
//	���������1.�ݹ�
//			 2.ѭ�������Ӷ�С


class Solution {
public:
	int jumpFloor(int number) {
		if (number < 3) {
			return number;
		}
		int left = 1, right = 2, ret = 0;
		while (number >= 3) {
			ret = left + right;
			left = right;
			right = ret;
			--number;
		}
		return ret;
	}
};

int main() {
	Solution s;
	int number;
	while (cin >> number) {
		if (number == 0) {
			break;
		}
		cout << s.jumpFloor(number) << endl;
	}
	system("pause");
	return 0;
}