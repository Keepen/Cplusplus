#include <iostream>
using namespace std;

struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
		val(x), next(NULL) {
	}
};

//输出链表中倒数第K个结点
//思路：快慢指针 -- cur， ret
//	cur先走k步，ret再走，
//	注意：如果k > 链表的结点总数就返回空指针

class Solution {
public:
	ListNode * FindKthToTail(ListNode* pListHead, unsigned int k) {
		ListNode* cur = pListHead, *ret = pListHead;
		unsigned int num = k;
		bool flag = true;
		while (cur) {
			if (num) {
				--num;
				cur = cur->next;
			}
			else {
				flag = false;
				cur = cur->next;
				ret = ret->next;
			}
		}
		if (flag && num) {
			return nullptr;
		}
		return ret;
	}
};

int main() {
	system("pause");
	return 0;
}