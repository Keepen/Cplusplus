//������������3~A��2�������ƣ���С����һ��
//	�������¹��򣺸��ӡ����ӡ����ӡ�˳�ӣ�����5���ƣ���ը��������
//	�ȽϹ���
//		1.������ͬ�Ĳſ��ԱȽ�
//		2.������ը�����Ժ��κ��ƱȽϣ��������
//		3.������ͬ���Ƚ������С
//	�����
//		1.���ԱȽϣ� �����������
//		2.�����ԱȽϣ����ERROR	



#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;
vector<string> maps;



int pos(string& a) {
	for (size_t i = 0; i<maps.size(); i++) {
		if (maps[i] == a) {
			return i;
		}
	}
	return -1;
}

void solu() {
	maps.push_back("3");
	maps.push_back("4");
	maps.push_back("5");
	maps.push_back("6");
	maps.push_back("7");
	maps.push_back("8");
	maps.push_back("9");
	maps.push_back("10");
	maps.push_back("J");
	maps.push_back("Q");
	maps.push_back("K");
	maps.push_back("A");
	maps.push_back("joker");
	maps.push_back("JOKER");


	string key;
	while (getline(cin, key)) {
		vector<string> poke1, poke2;
		int ret = 0;
		bool flag = true;
		//���Ʒ���
		string tmp;
		for (size_t i = 0; i < key.size(); i++) {
			if (i == key.size() - 1) {
				tmp += key[i];
				poke2.push_back(tmp);
			}
			//string tmp;
			if (key[i] == '-') {
				flag = false;
				poke1.push_back(tmp);
				tmp.clear();
				continue;
			}
			if (flag) {
				if (key[i] != ' ') {
					tmp += key[i];
				}
				else {
					poke1.push_back(tmp);
					tmp.clear();
				}
			}
			if (!flag) {
				if (key[i] != ' ') {
					tmp += key[i];
				}
				else {
					poke2.push_back(tmp);
					tmp.clear();
				}
			}
		}
		//�ж����Ƶ�����
		//�����൱���Ƚ�����
		bool joker = false;
		bool boom = false;
		if (poke1.size() == poke2.size()) {
			ret = pos(poke1[0]) - pos(poke2[0]);
		}
		//�������ȣ��Ƚ��Ƿ��ж���
		else if (poke1.size() == 2 || poke2.size() == 2) {
			if ((poke1[0] == "joker" && poke1[1] == "JOKER") ||
				(poke1[0] == "JOKER" && poke1[1] == "joker")) {
				ret = 1;
				joker = true;
			}
			if ((poke2[0] == "joker" && poke2[1] == "JOKER") ||
				(poke2[0] == "JOKER" && poke2[1] == "joker")) {
				ret = -1;
				joker = true;
			}
		}
		//�������ȣ�����û�ж������ж��Ƿ���ը��
		if (!joker && (poke1.size() == 4 || poke2.size() == 4) && poke1.size() != poke2.size()) {
			if (poke1.size() == 4) {
				ret = 1;
			}
			if (poke2.size() == 4) {
				ret = -1;
			}
		}
		//������ͬ������û��һ���Ƕ�������ը��
		else if (!joker && !boom && poke1.size() != poke2.size()) {
			ret = -1000;
		}
		//cout << "p1size()" << poke1.size() << endl;
		//cout << "p2size()" << poke2.size() << endl;
		//cout << "joker:" << joker << endl;
		//cout << ret << endl;
		if (ret > 0) {
			for (size_t i = 0; i<poke1.size() - 1; i++) {
				cout << poke1[i] << " ";
			}
			cout << poke1[poke1.size() - 1] << endl;
			continue;
		}
		else if (ret < 0 && ret != -1000) {
			for (size_t i = 0; i<poke2.size() - 1; i++) {
				cout << poke2[i] << " ";
			}
			cout << poke2[poke2.size() - 1] << endl;
			continue;
		}
		else {
			cout << "ERROR" << endl;
			continue;
		}
	}
}

int main() {
	solu();
	return 0;
}
