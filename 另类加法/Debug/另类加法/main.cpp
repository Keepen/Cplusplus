#include <iostream>
using namespace std;

//����ӷ�������ʹ��+���������������������֮��
// ^ ,| ����λ����������λ��ֵ
int add(int a, int b) {
	int sum = 0;
	while (b != 0) {
		sum = a ^ b;//�õ�û�н�λ�Ķ�Ӧλ�ĺ�
		b = (a&b) << 1;	//�õ��н�λ��λ�������ɸ�λ�Ľ�λ
	}
	return sum;
}

int add2(int a,int b) {
	if (b == 0) {
		return a;
	}
	return add2(a^b, (a&b)<<1);
}


int add3(int a, int b) {
	int ret = 0;	//������
	int last = 0;	//�����λ��Ϣ
	for (int i = 0; i < 32; i++) {
		int x = (a >> i) & 1;
		int y = (b >> i) & 1;
		int cur = (x ^ y) ^ last;	//���汾Ϊ��
		ret |= cur << i;
		last = (((x^y) && last) || ((x^last) && y) || ((y^last) && x));
	}
	return ret;
}



int main() {
	cout << add3(11, 21) << endl;
	system("pause");
	return 0;
}
