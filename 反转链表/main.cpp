#include <iostream>
using namespace std;

struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
		val(x), next(NULL) {
	}
};
class Solution {
public:
	ListNode * ReverseList(ListNode* pHead) {
		ListNode* pre = nullptr;
		ListNode* cur = pHead;
		ListNode* next = pHead->next;
		while (cur) {
			cur->next = pre;
			pre = cur;
			cur = next;
			next = next->next;
		}
		return pre;
	}
};

int main() {
	system("pause");
	return 0;
}