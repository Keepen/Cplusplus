//����������
//	��n����ɫ�����ף�����������������������ֶ�Ӧ��ɫ��������Ŀ
//	��������������ֻ��ֻ�ֱܷ�����Ҷ����ֱܷ����ɫ
//	��������Ҫ�ö���ֻ���ײ��ܱ�֤������һ����ɫ��ͬ
//	��ɫ n [1, 13], ��ÿ�����������׵���Ŀ��������26
//����������4, [0, 7, 1, 6], [1, 5, 0, 6]
//���أ�10(���ͣ�������������ȡ2ֻ����������ȡ8ֻ)

//˼·��
//	�����������0��û��0
//	û��0��
//		�����׵���Ŀ��Ϊ0ʱ����ô������ܸ��ǵ�n����ɫ�����׵ĺͣ�
//			����sum = ���з�0�ĺ� - ��С����Ŀ + 1�� �Ϳ��Ը��ǵ����ҵ���ɫ
//	��0��
//		������Ŀ��0ʱ����Ӧ��ɫ����һֻ�ֵ�������Ҫȫ������
//	����� = ÿһ���ܹ����ǵ�������ɫ�����׵ĺ�ȡ��С�� + 1 + Ϊ0ʱ�Ķ�Ӧ��ɫ����һֻ�ֵ�������Ŀ



#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Gloves {
public:
	int findMin(int n, vector<int> left, vector<int> right) {
		int sum = 0;
		int leftSum = 0, rightSum = 0;
		int leftMin = 30, rightMin = 30;
		for (int i = 0; i < n; i++) {
			//��ĳ����ɫ����Ϊ0ֻʱ��ȫ������
			if (left[i] * right[i] == 0) {
				sum += left[i] + right[i];
			}
			//���򣬼���������ܹ����ǵ�������ɫ�Ľ�Сֵ
			else {
				leftSum += left[i];
				rightSum += right[i];
				leftMin = min(leftMin, left[i]);
				rightMin = min(rightMin, right[i]);
			}
		}
		return sum + min(leftSum + 1, rightSum + 1) + 1;
	}
};

int main() {


	system("pause");
	return 0;
}
