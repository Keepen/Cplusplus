#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
//����������numֻ���ӣ���ֹ������m
//	��ʼ��������1��ʼ����������mʱ�����ӳ��֣�ʣ�µĺ��Ӽ�������
//		�ظ�����������ʣ�����һֻ���Ӽ�Ϊ����
//	Ҫ��������ֵĺ��������Լ�����

int main() {
	int num, m;		//num -- ������Ŀ��m -- ��ֹ����
	printf("�����������Ŀ��");
	scanf("%d", &num);
	printf("������������֣�");
	scanf("%d", &m);
	int* monkey = (int*)malloc(sizeof(int) * (num + 1));
	monkey[0] = 0;
	for (int i = 1; i <= num; ++i) {
		monkey[i] = 1;		//��ʾÿ�����Ӷ���Ȧ��
	}
	int count = 0;		//��ʾ����
	int rest = num;		//��ʾʣ��ĺ�����Ŀ
	printf("���ӵĳ�������Ϊ��");
	//numֻ���ӣ���Ҫ��̭num - 1ֻ����
	while (rest != 1) {
		for (int i = 1; i <= num; ++i) {
			if (monkey[i]) {
				count++;
				if (count == m) {
					monkey[i] = 0;		//��ʾ�Ѿ�����
					count = 0;			//count���¸�λ
					--rest;
					printf("%d  ", i);
				}
			}
		}
	}

	for (int i = 1; i <= num; ++i) {
		if (monkey[i] == 1) {
			printf("\n�����ǣ�%d \n", i);
		}
	}
	system("pause");
	return 0;
}