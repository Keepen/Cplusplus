#include <iostream>
using namespace std;

struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
		val(x), next(NULL) {
	}
};

//��������е�����K�����
//˼·������ָ�� -- cur�� ret
//	cur����k����ret���ߣ�
//	ע�⣺���k > ����Ľ�������ͷ��ؿ�ָ��

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