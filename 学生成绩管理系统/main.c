#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<windows.h>                       //system("cls");清屏时用 
int M = 0;
#define N 10
struct Student
{
	long long int num;                    //学号 
	char name[20];                        //姓名  
	char sex[3];                          //班级 
	float score[3];                       //分数 
	float total;					      //总分 
	float aver;                           //平均分 
}stu[N];


int main()
{
	system("color 0B");
	void transform();								//转换函数 
	transform();
	return 0;
}

void print1()										//输出首页表 
{
	int i;

	printf("\n\n\n		------------学生成绩管理系统------------\n\n");
	printf("			   1.输入、输出学生信息\n\n");
	printf("			   2.查找学生信息\n\n");
	printf("			   3.成绩排名\n\n");
	printf("			   4.学号排名\n\n");
	printf("			   5.返回到此页面\n\n");
	printf("			   6.退出学生成绩管理系统\n\n\n");
}


void input()         						//定义输入函数 
{
	int i, j;

	for (i = 0; i<N; i++)
	{
		char a;
		printf("\n\n\n			-----请输入学生的信息-----\n\n\n");
		printf("			请输入学号：");
		scanf("%I64d", &stu[i].num);
		printf("\n\n");
		printf("			请输入姓名：");
		scanf(" %s", &stu[i].name);
		printf("\n\n");
		printf("			请输入性别：");
		scanf(" %s", &stu[i].sex);
		printf("\n\n");
		printf("			高      数：");
		scanf("%f", &stu[i].score[0]);
		printf("\n\n");
		printf("			英      语：");
		scanf("%f", &stu[i].score[1]);
		printf("\n\n");
		printf("			计  算  机：");
		scanf("%f", &stu[i].score[2]);
		printf("\n\n");
		stu[i].total = stu[i].score[0] + stu[i].score[1] + stu[i].score[2];
		stu[i].aver = (stu[i].score[0] + stu[i].score[1] + stu[i].score[2]) / 3.0; M++;
		printf("			是否继续输入y or n：");
		getchar();
		a = getchar();
		if (a == 'n')break;
		if (a == 'y')continue;
		system("cls");
		system("cls");
	}
}


void print2()                       //输出所输入的信息函数 
{
	system("cls");
	int i;
	printf("-------------------------------------------------------------------------------");
	printf("\n");
	printf(" 学号    姓名      性别       数学      英语     计算机     总分     平均分\n");
	printf("-------------------------------------------------------------------------------");
	printf("\n");
	for (i = 0; i<M; i++)
	{
		printf("%-10I64d%-10s%-10s%-10.2f%-10.2f%-10.2f%-10.2f%-10.2f", stu[i].num, stu[i].name, stu[i].sex, stu[i].score[0], stu[i].score[1], stu[i].score[2], stu[i].total, stu[i].aver);
		printf("\n");

	}
}


void print3() 								//查找学生信息输出函数 
{
	printf("\n\n\n\n\n\n\n");
	printf("			请输入要查询学生的学号：");
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
	printf(" 学号    姓名      性别       数学      英语     计算机     总分     平均分\n");
	printf("-------------------------------------------------------------------------------");
	printf("\n");
	printf("%-10I64d%-10s%-10s%-10.2f%-10.2f%-10.2f%-10.2f%-10.2f", stu[n].num, stu[n].name, stu[n].sex, stu[n].score[0], stu[n].score[1], stu[n].score[2], stu[n].total, stu[n].aver);
}


void order1()									//按平均成绩排序 
{
	printf("\n\n");
	printf("\n\n		        -----按照平均成绩排序-----\n\n\n");
	int i, j;
	struct Student tem;								//冒泡法排序 
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
	printf(" 学号    姓名      性别       数学      英语     计算机     总分     平均分\n");
	printf("-------------------------------------------------------------------------------");
	printf("\n");
	for (i = 0; i<M; i++)
	{
		printf("%-10I64d%-10s%-10s%-10.2f%-10.2f%-10.2f%-10.2f%-10.2f", stu[i].num, stu[i].name, stu[i].sex, stu[i].score[0], stu[i].score[1], stu[i].score[2], stu[i].total, stu[i].aver);
		printf("\n");

	}

}


void order2()										//按照学号排序 
{
	printf("\n\n");
	printf("\n\n			    -----按照学号排序-----\n\n\n");
	int i, j;
	struct Student tem;								//冒泡法排序 
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
	printf(" 学号    姓名      性别       数学      英语     计算机     总分     平均分\n");
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
	void print1();							//首页表 
	void print2();							//输入输出的信息 
	void print3();							//查找信息输出 
	void order1();							//按照平均成绩排序 
	void order2();
	print1();
	int a, j;

	for (j = 0; j<100; j++)
	{
		printf("\n\n			   请选择：");
		scanf("%d", &a);
		if (a>6 || a<0)printf("\n		   输入错误!\n");
		if (a == 6) { system("cls"); printf("\n\n\n			感谢使用学生成绩管理系统!\n\n\n				再见！\n\n\n\n\n\n"); break; }
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
