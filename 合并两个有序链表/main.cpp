#include <iostream>
using namespace std;

//链表结点
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
		val(x), next(nullptr) {
	}
};
class Solution {
public:
	ListNode * Merge(ListNode* pHead1, ListNode* pHead2)
	{
		ListNode* p1 = pHead1, *p2 = pHead2;
		ListNode* ret = new ListNode(1);
		ListNode* cur_ret = ret;// = ret->next;
		ListNode* cur = nullptr;
		while (p1 && p2) {
			if (p1->val <= p2->val) {
				cur = p1->next;
				cur_ret->next = p1;
				cur_ret = p1;
				p1 = cur;
			}
			else {
				cur = p2->next;
				cur_ret->next = p2;
				cur_ret = p2;
				p2 = cur;
			}
		}
		if (!p1) {
			cur_ret->next = p2;
		}
		else {
			cur_ret->next = p1;
		}
		return ret->next;
	}
};

void print(ListNode* head) {
	ListNode* cur = head;
	if (cur == nullptr) {
		return;
	}
	while (cur) {
		cout << cur->val << "->";
		cur = cur->next;
	}
	cout << endl;
	return;
}
void test() {
	cout << "请输入链表1的结点数目:" << endl;
	ListNode* p1 = new ListNode(0);
	ListNode* p1_cur = p1;
	int n1;
	cin >> n1;
	while (n1--) {
		ListNode* node = new ListNode(0);
		cin >> node->val;
		p1_cur->next = node;
		p1_cur = p1_cur->next;
	}
	cout << "请输入链表2的结点数目：" << endl;
	ListNode* p2 = new ListNode(0);
	ListNode* p2_cur = p2;
	int n2;
	cin >> n2;
	while (n2--) {
		ListNode* node = new ListNode(0);
		cin >> node->val;
		p2_cur->next = node;
		p2_cur = p2_cur->next;
	}
	//print(p1->next);
	//print(p2->next);
	Solution s;
	ListNode* ret = s.Merge(p1->next, p2->next);
	print(ret);
}



int main() {
	test();
	system("pause");
	return 0;
}