#include <iostream>
using namespace std;

//另类加法：不能使用+、等算术运算符来求两数之和
// ^ ,| 运用位运算符求出各位的值
int add(int a, int b) {
	int sum = 0;
	while (b != 0) {
		sum = a ^ b;//得到没有进位的对应位的和
		b = (a&b) << 1;	//得到有进位的位，将其变成高位的进位
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
	int ret = 0;	//保存结果
	int last = 0;	//保存进位信息
	for (int i = 0; i < 32; i++) {
		int x = (a >> i) & 1;
		int y = (b >> i) & 1;
		int cur = (x ^ y) ^ last;	//保存本为和
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
