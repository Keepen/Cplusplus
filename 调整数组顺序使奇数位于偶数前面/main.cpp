#include <iostream>
#include <vector>
using namespace std;

//�������������������е�����ʹ������ȫ��λ��ż��ǰ��
//	���ܸı����ֵ����λ�ã�����������֮�䣬ż����ż��֮��

//�������ȿ�����������
//	�ȵ���������˳����������е�����
//	�ٵ���ż����������������е�����
class Solution {
public:
	void reOrderArray(vector<int> &array) {
		vector<int> tmp(array);
		int k = 0;
		size_t sz = array.size();
		for (int i = 0; i < array.size(); ++i) {
			if (tmp[i] & 1) {
				array[k] = tmp[i];
				++k;
			}
		}
		k = 1;
		for (int i = sz - 1; i >= 0; --i) {
			if (tmp[i] % 2 == 0) {
				array[sz - k] = tmp[i];
				++k;
			}
		}
	}
};


int main() {

	system("pause");
	return 0;
}