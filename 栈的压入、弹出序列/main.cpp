#include <iostream>
#include <vector>
#include <unordered_map>
#include <stack>
using namespace std;
//����һ����ջ���У�һ����ջ���С��жϳ�ջ�����Ƿ�Ϸ�
//	˼·��
//		1.������ջ���У��õ�ÿһ��Ԫ������ջ���е��±�
//		2.�����±�֮ǰ��Ԫ��ȫ����ջ
//			��ջ�Ĺ���
//				1��ջ������Ԫ����Ϊ��ջ��ʼ�±�
//				2���߽��ǣ������±�Ϊֹ��������Ԫ�ص��±꣩
//		3.�ж�ջ�����ջԪ�أ���ͬ��ֱ�ӷ��ش���

class Solution {
public:
	bool IsPopOrder(vector<int> pushV, vector<int> popV) {
		unordered_map<int, int> key;
		for (size_t i = 0; i < pushV.size(); ++i) {
			key[pushV[i]] = i;
		}
		stack<int> s;
		int count = 0;
		for (size_t i = 0; i < popV.size(); ++i) {
			int num = key[popV[i]];		//��¼��ǰ�ĳ�ջ��������ջ�����е��±�
			if (num >= count) {
				for (int j = count; j <= num; ++j) {
					++count;
					s.push(pushV[j]);
				}
			}
			if (popV[i] == s.top()) {
				s.pop();
			}
			else {
				return false;
			}
		}
		return true;
	}
};

void test() {
	vector<int> push(5);
	for (size_t i = 0; i < push.size(); ++i) {
		push[i] = i + 1;
	}
	vector<int> pop;
	pop.push_back(4);
	pop.push_back(3);
	pop.push_back(5);
	pop.push_back(1);
	pop.push_back(2);

	Solution s;
	cout << s.IsPopOrder(push, pop);
}


int main() {
	test();
	system("pause");
	return 0;
}