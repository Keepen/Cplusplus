#include <iostream>
#include <vector>
#include <unordered_map>
#include <stack>
using namespace std;
//给定一个入栈序列，一个出栈序列。判断出栈序列是否合法
//	思路：
//		1.遍历出栈序列，得到每一个元素在入栈序列的下标
//		2.将改下标之前的元素全部入栈
//			入栈的规则：
//				1）栈内已有元素作为入栈起始下标
//				2）边界是，到该下标为止（包含该元素的下标）
//		3.判断栈顶与出栈元素，不同则直接返回错误

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
			int num = key[popV[i]];		//记录当前的出栈数字在入栈序列中的下标
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