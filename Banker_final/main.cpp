#include <iostream>
#include <vector>
#include<stdio.h>
#include<windows.h>
using namespace std;
//设置文字颜色
// 0-黑 1-蓝 2-绿 3-浅绿 4-红 5-紫 6-黄 7-白 8-灰 9-淡蓝 
//10-淡绿 11-淡浅绿  12-淡红 13-淡紫 14-淡黄 15-亮白 
void SetColor(int color);
//颜色函数 
void SetColor(int color)
{
	HANDLE winHandle; //句柄 
	winHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	//设置文字颜色
	SetConsoleTextAttribute(winHandle, color | 1);
}
class Banker {
private:
	vector<vector<int>> allocation;		//已分配矩阵
	vector<vector<int>> need;			//需求矩阵
	vector<int> available;				//可用资源数
	vector<int> security;				//安全序列
	int pro;		//进程数目
	int res;		//资源数目
public:
	//0.菜单
	void menu() {
		cout << "--------银行家算法---------" << endl;
		cout << "	1.录入信息" << endl;
		cout << "	2.安全性检测" << endl;
		cout << "	3.进程资源请求" << endl;
		cout << "	4.退出" << endl;
		cout << "--------------------------" << endl;
	}
	void Process() {
		while (1) {
			int fun = 0;
			menu();
			cout << "请选择功能：";
			cin >> fun;
			if (fun == 1) {
				cout << "---------------------------------------" << endl;
				input();
				print();
			}
			else if (fun == 2) {
				cout << "---------------------------------------" << endl;
				bool flag = securityCheck();
				if (!flag) {
					cout << "该状态不安全！！！" << endl;
				}
				print();
			}
			else if (fun == 3) {
				while (1) {
				cout << "---------------------------------------" << endl;
					Request();
					print();
					cout << "请问是否还要请求：y / n" << endl;
					char ret;
					cin >> ret;
					if (ret == 'y') {
						continue;
					}
					else {
						break;
					}
				}
			}
			else if (fun == 4) {
				cout << "谢谢使用！！！" << endl;
				cout << "---------------------------------------" << endl;
				return;
			}
		}
	}


	//1.录入进程信息
	void input() {
		cout << "录入进程数目：";
		cin >> pro;
		cout << "录入资源数目";
		cin >> res;
		allocation.resize(pro,vector<int>(res,0));
		need.resize(pro,vector<int>(res,0));
		available.resize(res);
		cout << "录入已分配矩阵：";
		for (int i = 0; i < pro; ++i) {
			for (int j = 0; j < res; ++j) {
				cin >> allocation[i][j];
			}
		}
		cout << "录入需求矩阵：";
		for (int i = 0; i < pro; ++i) {
			for (int j = 0; j < res; ++j) {
				cin >> need[i][j];
			}
		}
		cout << "录入可用资源情况：";
		for (int i = 0; i < res; ++i) {
			cin >> available[i];
		}
	}
	//2.安全性检测
	bool securityCheck() {
		security.resize(0);
		int rest = 0;
		vector<int> work(available);	//工作向量初始值 == avaliable
		for (auto& e : work) {
			cout << "work" << e << " ";
		}
		cout << endl;
		vector<bool> finish(pro);
		for (int i = 0; i < pro; ++i) {
			finish[i] = false;
		}
		while (rest != pro) {
			++rest;
			for (int i = 0; i < pro; ++i) {
				int res_temp = 0;		//记录当前某进程有几类资源可以得到满足
				if (!finish[i]) {
					for (int j = 0; j < res; ++j) {
						if (work[j] >= need[i][j]) {
							res_temp++;
						}
					}
					if (res_temp == res) {
						finish[i] = true;
						security.push_back(i);
						for (int m = 0; m < res; ++m) {
							work[m] += allocation[i][m];
						}
					}
				}
			}
		}
		//遍历finish数组，如果有不满足要求的就直接返回false；
		for (int i = 0; i < pro; ++i) {
			if (!finish[i]) {
				return false;
			}
		}
		cout << "该状态安全，安全序列为：";
		for (int i = 0; i < pro; ++i) {
			cout << "p" << security[i] << " ";
		}
		cout << endl;
		return true;

	}
	//3.进程资源请求
	void Request() {
		int id;		//请求资源的进程编号
		vector<int> request;
		request.resize(res);
		cout << "请输入请求资源的进程编号：";
		cin >> id;
		cout << "请输入请求的各类资源数目：";
		for (int i = 0; i < res; ++i) {
			cin >> request[i];
		}
		vector<vector<int>> allo_temp(allocation);
		vector<vector<int>> need_temp(need);
		vector<int> avail_temp(available);
		for (int i = 0; i < res; ++i) {
			if (request[i] > available[i]) {
				cout << "请求资源大于现有资源数目，不能满足请求！！！" << endl;
				return;
			}
		}
		//现有资源数目，足够满足请求数目，修改allo和need矩阵
		for (int i = 0; i < res; ++i) {
			allo_temp[id][i] += request[i];
			int minus = need_temp[id][i] - request[i];	//判断需求 - 请求是否变成了负数
			if (minus < 0) {
				cout << "请求资源数目大于所需，故不分配！！！" << endl;
				return;
			}
			need_temp[id][i] = minus;
			avail_temp[i] -= request[i];
		}
		Banker ban_temp = *this;
		ban_temp.allocation = allo_temp;
		ban_temp.need = need_temp;
		ban_temp.available = avail_temp;
		bool flag = ban_temp.securityCheck();
		//如果安全性检测通过，就要为其分配资源
		if (flag) {
			for (int j = 0; j < res; ++j) {
				need[id][j] = need_temp[id][j];
				if (need[id][j] == 0) {
					available[j] += allocation[id][j];
					allocation[id][j] = 0;
				}
				else {
					allocation[id][j] += request[j];
					available[j] = avail_temp[j];
				}
				security[j] = ban_temp.security[j];
			}
			return;
		}
		cout << "经过安全检测后，不能找到一个安全序列，故不能分配！！！" << endl;
	}

	void print() {
		cout << "已分配矩阵 \t\t需求矩阵" << endl;
		for (int i = 0; i < pro; ++i) {
			for (int j = 0; j < res; ++j) {
				cout << allocation[i][j] << "  ";
			}
			cout << "\t\t";
			for (int j = 0; j < res; ++j) {
				cout << need[i][j] << " ";
			}
			cout << endl;
		}
		cout << "现可用：" << endl;
		for (int i = 0; i < res; ++i) {
			cout << available[i] << " ";
		}
		cout << endl;
	}
};

int main() {
	SetColor(10);
	Banker ban;
	ban.Process();
	system("pause");
	return 0;
};