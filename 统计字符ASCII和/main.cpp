#include <stdio.h>
#include <stdlib.h>

void fun(char* str) {
	char arr[128] = { 0 };	//��ʾASCII��ȫ��0
	int num = 0;	//ͳ�����ֵ���Ŀ
	int asc = 0;	//ͳ����ĸ����Ŀ
	int sum = 0;	//ͳ���ַ����ܺ�
	char* cur = str;
	char sstr[1024] = { 0 };
	while (*cur != '\0') {
		arr[*cur]++;	//��ʾĳ���ַ�����Ŀ
		cur++;
	}
	//0x30 ~ 0x39 ��  0 ~ 9 ��ASCIIֵ
	for (int i = 0x30; i < 0x40; i++) {
		num += arr[i];
	}
	for (int i = 'a',j = 'A'; i <= 'z', j <= 'Z'; ++i, ++j) {
		asc += arr[i];
		asc += arr[j];
		sum += i * arr[i] + j * arr[j];
	}
	printf("%d,%d,%d\n", num, asc, sum);
	cur = str;
	bool flag = true;
	int i = 0;
	while (*cur != '\0') {
		if (*cur == '5') {
			sstr[i++] = '5';
			break;
		}
		cur++;
	}
	cur++;
	while (*cur != '\0') {
		sstr[i++] = *cur;
		cur++;
	}
	sstr[i] = '\0';
	printf("%s\n", sstr);
}



int main() {
	char str[] = "B09D84EE33E632ADB5288437D4FCBD81";
	fun(str);
	system("pause");
	return 0;
}