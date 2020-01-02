#include <iostream>
#include <vector>
#include<stdio.h>
#include<windows.h>
using namespace std;
//����������ɫ
// 0-�� 1-�� 2-�� 3-ǳ�� 4-�� 5-�� 6-�� 7-�� 8-�� 9-���� 
//10-���� 11-��ǳ��  12-���� 13-���� 14-���� 15-���� 
void SetColor(int color);
//��ɫ���� 
void SetColor(int color)
{
	HANDLE winHandle; //��� 
	winHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	//����������ɫ
	SetConsoleTextAttribute(winHandle, color | 1);
}
class Banker {
private:
	vector<vector<int>> allocation;		//�ѷ������
	vector<vector<int>> need;			//�������
	vector<int> available;				//������Դ��
	vector<int> security;				//��ȫ����
	int pro;		//������Ŀ
	int res;		//��Դ��Ŀ
public:
	//0.�˵�
	void menu() {
		cout << "--------���м��㷨---------" << endl;
		cout << "	1.¼����Ϣ" << endl;
		cout << "	2.��ȫ�Լ��" << endl;
		cout << "	3.������Դ����" << endl;
		cout << "	4.�˳�" << endl;
		cout << "--------------------------" << endl;
	}
	void Process() {
		while (1) {
			int fun = 0;
			menu();
			cout << "��ѡ���ܣ�";
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
					cout << "��״̬����ȫ������" << endl;
				}
				print();
			}
			else if (fun == 3) {
				while (1) {
				cout << "---------------------------------------" << endl;
					Request();
					print();
					cout << "�����Ƿ�Ҫ����y / n" << endl;
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
				cout << "ллʹ�ã�����" << endl;
				cout << "---------------------------------------" << endl;
				return;
			}
		}
	}


	//1.¼�������Ϣ
	void input() {
		cout << "¼�������Ŀ��";
		cin >> pro;
		cout << "¼����Դ��Ŀ";
		cin >> res;
		allocation.resize(pro,vector<int>(res,0));
		need.resize(pro,vector<int>(res,0));
		available.resize(res);
		cout << "¼���ѷ������";
		for (int i = 0; i < pro; ++i) {
			for (int j = 0; j < res; ++j) {
				cin >> allocation[i][j];
			}
		}
		cout << "¼���������";
		for (int i = 0; i < pro; ++i) {
			for (int j = 0; j < res; ++j) {
				cin >> need[i][j];
			}
		}
		cout << "¼�������Դ�����";
		for (int i = 0; i < res; ++i) {
			cin >> available[i];
		}
	}
	//2.��ȫ�Լ��
	bool securityCheck() {
		security.resize(0);
		int rest = 0;
		vector<int> work(available);	//����������ʼֵ == avaliable
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
				int res_temp = 0;		//��¼��ǰĳ�����м�����Դ���Եõ�����
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
		//����finish���飬����в�����Ҫ��ľ�ֱ�ӷ���false��
		for (int i = 0; i < pro; ++i) {
			if (!finish[i]) {
				return false;
			}
		}
		cout << "��״̬��ȫ����ȫ����Ϊ��";
		for (int i = 0; i < pro; ++i) {
			cout << "p" << security[i] << " ";
		}
		cout << endl;
		return true;

	}
	//3.������Դ����
	void Request() {
		int id;		//������Դ�Ľ��̱��
		vector<int> request;
		request.resize(res);
		cout << "������������Դ�Ľ��̱�ţ�";
		cin >> id;
		cout << "����������ĸ�����Դ��Ŀ��";
		for (int i = 0; i < res; ++i) {
			cin >> request[i];
		}
		vector<vector<int>> allo_temp(allocation);
		vector<vector<int>> need_temp(need);
		vector<int> avail_temp(available);
		for (int i = 0; i < res; ++i) {
			if (request[i] > available[i]) {
				cout << "������Դ����������Դ��Ŀ�������������󣡣���" << endl;
				return;
			}
		}
		//������Դ��Ŀ���㹻����������Ŀ���޸�allo��need����
		for (int i = 0; i < res; ++i) {
			allo_temp[id][i] += request[i];
			int minus = need_temp[id][i] - request[i];	//�ж����� - �����Ƿ����˸���
			if (minus < 0) {
				cout << "������Դ��Ŀ�������裬�ʲ����䣡����" << endl;
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
		//�����ȫ�Լ��ͨ������ҪΪ�������Դ
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
		cout << "������ȫ���󣬲����ҵ�һ����ȫ���У��ʲ��ܷ��䣡����" << endl;
	}

	void print() {
		cout << "�ѷ������ \t\t�������" << endl;
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
		cout << "�ֿ��ã�" << endl;
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