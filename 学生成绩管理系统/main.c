#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<windows.h>                       //system("cls");����ʱ�� 
int M = 0;
#define N 10
struct Student
{
	long long int num;                    //ѧ�� 
	char name[20];                        //����  
	char sex[3];                          //�༶ 
	float score[3];                       //���� 
	float total;					      //�ܷ� 
	float aver;                           //ƽ���� 
}stu[N];


int main()
{
	system("color 0B");
	void transform();								//ת������ 
	transform();
	return 0;
}

void print1()										//�����ҳ�� 
{
	int i;

	printf("\n\n\n		------------ѧ���ɼ�����ϵͳ------------\n\n");
	printf("			   1.���롢���ѧ����Ϣ\n\n");
	printf("			   2.����ѧ����Ϣ\n\n");
	printf("			   3.�ɼ�����\n\n");
	printf("			   4.ѧ������\n\n");
	printf("			   5.���ص���ҳ��\n\n");
	printf("			   6.�˳�ѧ���ɼ�����ϵͳ\n\n\n");
}


void input()         						//�������뺯�� 
{
	int i, j;

	for (i = 0; i<N; i++)
	{
		char a;
		printf("\n\n\n			-----������ѧ������Ϣ-----\n\n\n");
		printf("			������ѧ�ţ�");
		scanf("%I64d", &stu[i].num);
		printf("\n\n");
		printf("			������������");
		scanf(" %s", &stu[i].name);
		printf("\n\n");
		printf("			�������Ա�");
		scanf(" %s", &stu[i].sex);
		printf("\n\n");
		printf("			��      ����");
		scanf("%f", &stu[i].score[0]);
		printf("\n\n");
		printf("			Ӣ      �");
		scanf("%f", &stu[i].score[1]);
		printf("\n\n");
		printf("			��  ��  ����");
		scanf("%f", &stu[i].score[2]);
		printf("\n\n");
		stu[i].total = stu[i].score[0] + stu[i].score[1] + stu[i].score[2];
		stu[i].aver = (stu[i].score[0] + stu[i].score[1] + stu[i].score[2]) / 3.0; M++;
		printf("			�Ƿ��������y or n��");
		getchar();
		a = getchar();
		if (a == 'n')break;
		if (a == 'y')continue;
		system("cls");
		system("cls");
	}
}


void print2()                       //������������Ϣ���� 
{
	system("cls");
	int i;
	printf("-------------------------------------------------------------------------------");
	printf("\n");
	printf(" ѧ��    ����      �Ա�       ��ѧ      Ӣ��     �����     �ܷ�     ƽ����\n");
	printf("-------------------------------------------------------------------------------");
	printf("\n");
	for (i = 0; i<M; i++)
	{
		printf("%-10I64d%-10s%-10s%-10.2f%-10.2f%-10.2f%-10.2f%-10.2f", stu[i].num, stu[i].name, stu[i].sex, stu[i].score[0], stu[i].score[1], stu[i].score[2], stu[i].total, stu[i].aver);
		printf("\n");

	}
}


void print3() 								//����ѧ����Ϣ������� 
{
	printf("\n\n\n\n\n\n\n");
	printf("			������Ҫ��ѯѧ����ѧ�ţ�");
	long long int k;
	int i, j, n;
	scanf("%I64d", &k);
	printf("\n\n");
	for (j = 0, i = 0; j<M, i<M; j++, i++)
	{
		if (k == stu[i].num)
			n = i;
	}
	printf("-------------------------------------------------------------------------------");
	printf("\n");
	printf(" ѧ��    ����      �Ա�       ��ѧ      Ӣ��     �����     �ܷ�     ƽ����\n");
	printf("-------------------------------------------------------------------------------");
	printf("\n");
	printf("%-10I64d%-10s%-10s%-10.2f%-10.2f%-10.2f%-10.2f%-10.2f", stu[n].num, stu[n].name, stu[n].sex, stu[n].score[0], stu[n].score[1], stu[n].score[2], stu[n].total, stu[n].aver);
}


void order1()									//��ƽ���ɼ����� 
{
	printf("\n\n");
	printf("\n\n		        -----����ƽ���ɼ�����-----\n\n\n");
	int i, j;
	struct Student tem;								//ð�ݷ����� 
	for (j = 0; j<M - 1; j++)
	{
		for (i = 0; i<M - j - 1; i++)
		{
			if (stu[i].aver<stu[i + 1].aver)
			{
				tem = stu[i]; stu[i] = stu[i + 1]; stu[i + 1] = tem;
			}
		}
	}
	printf("-------------------------------------------------------------------------------");
	printf("\n");
	printf(" ѧ��    ����      �Ա�       ��ѧ      Ӣ��     �����     �ܷ�     ƽ����\n");
	printf("-------------------------------------------------------------------------------");
	printf("\n");
	for (i = 0; i<M; i++)
	{
		printf("%-10I64d%-10s%-10s%-10.2f%-10.2f%-10.2f%-10.2f%-10.2f", stu[i].num, stu[i].name, stu[i].sex, stu[i].score[0], stu[i].score[1], stu[i].score[2], stu[i].total, stu[i].aver);
		printf("\n");

	}

}


void order2()										//����ѧ������ 
{
	printf("\n\n");
	printf("\n\n			    -----����ѧ������-----\n\n\n");
	int i, j;
	struct Student tem;								//ð�ݷ����� 
	for (j = 0; j<M - 1; j++)
	{
		for (i = 0; i<M - j - 1; i++)
		{
			if (stu[i].num>stu[i + 1].num)
			{
				tem = stu[i]; stu[i] = stu[i + 1]; stu[i + 1] = tem;
			}
		}
	}
	printf("-------------------------------------------------------------------------------");
	printf("\n");
	printf(" ѧ��    ����      �Ա�       ��ѧ      Ӣ��     �����     �ܷ�     ƽ����\n");
	printf("-------------------------------------------------------------------------------");
	printf("\n");
	for (i = 0; i<M; i++)
	{
		printf("%-10I64d%-10s%-10s%-10.2f%-10.2f%-10.2f%-10.2f%-10.2f", stu[i].num, stu[i].name, stu[i].sex, stu[i].score[0], stu[i].score[1], stu[i].score[2], stu[i].total, stu[i].aver);
		printf("\n");

	}
}

void transform()
{
	void input();
	void print1();							//��ҳ�� 
	void print2();							//�����������Ϣ 
	void print3();							//������Ϣ��� 
	void order1();							//����ƽ���ɼ����� 
	void order2();
	print1();
	int a, j;

	for (j = 0; j<100; j++)
	{
		printf("\n\n			   ��ѡ��");
		scanf("%d", &a);
		if (a>6 || a<0)printf("\n		   �������!\n");
		if (a == 6) { system("cls"); printf("\n\n\n			��лʹ��ѧ���ɼ�����ϵͳ!\n\n\n				�ټ���\n\n\n\n\n\n"); break; }
		switch (a)
		{
		case 1: {system("cls"); input(); print2(); }break;
		case 2: {system("cls"); print3(); }break;
		case 3: {system("cls"); order1(); }break;
		case 4: {system("cls"); order2(); }break;
		case 5: {system("cls"); print1(); }break;
		}

	}
}
