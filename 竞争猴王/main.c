#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
//问题描述：num只猴子，终止数字是m
//	开始报数，从1开始报数，报到m时，猴子出局，剩下的猴子继续报数
//		重复上述动作，剩下最后一只猴子即为猴王
//	要求：输出出局的猴子序列以及猴王

int main() {
	int num, m;		//num -- 猴子数目；m -- 终止数字
	printf("请输入猴子数目：");
	scanf("%d", &num);
	printf("请输入出局数字：");
	scanf("%d", &m);
	int* monkey = (int*)malloc(sizeof(int) * (num + 1));
	monkey[0] = 0;
	for (int i = 1; i <= num; ++i) {
		monkey[i] = 1;		//表示每个猴子都在圈中
	}
	int count = 0;		//表示计数
	int rest = num;		//表示剩余的猴子数目
	printf("猴子的出局序列为：");
	//num只猴子，需要淘汰num - 1只猴子
	while (rest != 1) {
		for (int i = 1; i <= num; ++i) {
			if (monkey[i]) {
				count++;
				if (count == m) {
					monkey[i] = 0;		//表示已经出局
					count = 0;			//count重新复位
					--rest;
					printf("%d  ", i);
				}
			}
		}
	}

	for (int i = 1; i <= num; ++i) {
		if (monkey[i] == 1) {
			printf("\n猴王是：%d \n", i);
		}
	}
	system("pause");
	return 0;
}