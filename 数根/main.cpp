// write your code here cpp
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

//���� -- һ�����ֵĸ�λ����֮��
//	һ�����ֵĸ�λ����֮������һλ�� -- ��Ϊ����������
//	��λ����֮�ͳ���һλ��--����������������--ֱ�����һλ����
//����
//	24 -- 6
//	39 -- 3


string _sum(string a, char b) {
	string sum;
	string::iterator it = a.end() - 1;
	int cur = 0, last = 0;

	cur = (*it - '0' + b - '0' + last) % 10;
	last += (*it - '0' + b - '0') / 10;
	sum += cur + '0';
	while (it != a.begin()) {
		--it;
		cur = (*it - '0' + last) % 10;
		last = (*it - '0' + last) / 10;
		sum += cur + '0';
	}
	if (last > 0) {
		sum += last + '0';
	}
	reverse(sum.begin(), sum.end());
	return sum;
}


string num_sum(string num) {
	string sum;
	size_t i = 0;
	sum += num[i];
	for (i = 1; i < num.size(); ++i) {
		sum = _sum(sum, num[i]);
	}
	//cout << "sum:  " << sum << endl;
	return sum;
}

string num_root(string num) {
	while (num.size() > 1) {
		num = num_sum(num);
	}
	return num;
}

int main() {
	string num;
	while (cin >> num) {
		cout << num_root(num) << endl;
	}
	return 0;
}