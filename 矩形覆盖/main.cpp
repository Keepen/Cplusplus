//���ǿ�����2 * 1��С���κ��Ż�������ȥ���Ǹ���ľ��Ρ�������n��2 * 1��С�������ص��ظ���һ��2*n�Ĵ���Σ��ܹ��ж����ַ�����
#include <iostream>
using namespace std;


//�������������̣�
//	���Ժ��ŷţ�Ҳ�������ŷ�
//	����F��n�� = F��n - 1�� + F��n - 2����

class Solution {
public:
	int rectCover(int number) {
		if (number < 3) {
			return number;
		}
		int left = 1, right = 2;
		int ret = 0;
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
		cout << s.rectCover(number) << endl;
	}
	system("pause");
	return 0;
}