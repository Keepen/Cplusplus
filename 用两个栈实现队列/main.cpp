#include <iostream>
#include <stack>
using namespace std;

//������ջʵ�ֶ��У�
//	˼·��һ��ջר������������Ӳ���
//		��һ��ջר������ʵ�ֳ��Ӳ���

class Solution
{
public:
	void push(int node) {
		stack1.push(node);
	}

	int pop() {
		if (!stack1.empty()) {
			while (!stack1.empty()) {
				int top = stack1.top();
				stack2.push(top);
				stack1.pop();
			}
			int top = stack2.top();
			stack2.pop();
			while (!stack2.empty()) {
				int top = stack2.top();
				stack1.push(top);
				stack2.pop();
			}
			return top;
		}
	}

private:
	stack<int> stack1;
	stack<int> stack2;
};



void test() {
	Solution s;
	s.push(1);
	s.push(2);
	s.pop();
	s.pop();
}

int main() {
	test();
	system("pause");
	return 0;
}



