//小Q的歌单：
//有X首长度为a的歌和Y首长度为b的歌，
//现在需要组合有长度刚好位K的歌单
//问有多少种组合方式，将结果模上1000000007

//思路：
//1.就是在长度为a的选择m首，在长度为b的中选择n首
//2.计算其组合数即可
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define MAX 1000000007

//求组合数
//在a里取b，有多少种方法
int com(int a, int b) {
	//先判断有没有0操作数
	if (a == 0 && b > a) {
		return 0;
	}
	if (b > a) {
		return 0;
	}
	if (b == 0 || b == a) {
		return 1;
	}
	//利用公式 Cab == a!/(b! * (a-b)!);
	int temp = a - b;
	int suma = 1;
	int sumb = 1;
	int sumab = 1;
	//求a的阶乘
	while (a) {
		suma = suma * a;
		a--;
	}
//	printf("suma = %d \n", suma);
	while (b) {
		sumb = sumb * b;
		b--;
	}
//	printf("sumb = %d\n", sumb);
	while (temp) {
		sumab = sumab * temp;
		temp--;
	}
//	printf("sumab = %d\n", sumab);
	int ret = 0;
	ret = suma / (sumb*sumab);
	return ret % MAX;
}


int main() {
	int x, a, y, b, k;

	printf("请依次输入：x首长度为a，y首长度为b，以及个单的长度k：\n");
	scanf("%d%d%d%d%d", &x, &a, &y, &b, &k);
	long long sum = 0;		//用来记录最后的大小
	int i = 0;
	while (i <= x) {
		//符合准则的选择方案
		if (k - (a*i) >= 0 && (k - (a*i)) % b == 0 && (k-(a*i))/b <= y) {
			long long p = com(x, i);
			long long q = com(y, (k - (a*i)) / b);
			sum += p * q;
			sum %= MAX;
		}
		++i;
	}

	printf("%lld\n", sum);
	system("pause");
	return 0;
}