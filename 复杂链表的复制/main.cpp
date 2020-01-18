#include <iostream>
using namespace std;

//���������ָ�������
//	˼·��
//		1.����ԭ�����е�ÿһ���ڵ㲢β�嵽ԭ������ȥ
//		2.�������ָ�룺cur->next->random = cur->random->next;
//		3.�ָ����������������ͷ�ڵ�

struct RandomListNode {
	int label;
	struct RandomListNode *next, *random;
	RandomListNode(int x) :
		label(x), next(NULL), random(NULL) {
	}
};

class Solution {
public:
	RandomListNode * Clone(RandomListNode* pHead)
	{
		if (!pHead) {
			return pHead;
		}
		RandomListNode* cur = pHead;
		while (cur) {
			RandomListNode* node = new RandomListNode(0);
			node->next = cur->next;
			node->label = cur->label;
			cur->next = node;
			cur = cur->next->next;
		}
		cur = pHead;
		RandomListNode* head = cur->next;
		RandomListNode* ret = cur->next;
		while (cur && cur->next) {
			if (cur->random) {
				cur->next->random = cur->random->next;
			}
			cur = cur->next->next;
		}
		cur = pHead;
		ret = cur->next;
		while (cur && cur->next) {
			cur->next = cur->next->next;
			if (ret->next) {
				ret->next = ret->next->next;
			}
			cur = cur->next;
			if (cur && cur->next->next == NULL) {
				cur->next = NULL;
			}
			ret = ret->next;
		}
		return head;
	}
};


void print(RandomListNode* head) {
	RandomListNode* cur = head;
	while (cur) {
		cout << cur->label;
		if (cur->next) {
			cout << "->";
		}
		cur = cur->next;
	}
	cout << endl;
}


void test() {
	RandomListNode n1(1);
	RandomListNode n2(2);
	RandomListNode n3(3);
	RandomListNode n4(4);
	//n1.next = &n2; //n1.random = &n3;
	//n2.next = &n3;// n2.random = &n1;
	//n3.next = &n4; n3.random = &n2;
	//n4.random = &n4;
	print(NULL);
	Solution s;
	RandomListNode* ret = s.Clone(NULL);
	print(ret);
}

int main() {
	test();
	system("pause");
	return 0;
}