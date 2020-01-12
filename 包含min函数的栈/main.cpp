#include <iostream>
#include <stack>
using namespace std;
class Solution {
public:
	stack<int> s;
	stack<int> least;
	void push(int value) {
		if (s.empty()) {
			s.push(value);
			least.push(value);
		}
		else {
			s.push(value);
			if (least.top() >= value) {
				least.push(value);
			}
			else {
				least.push(least.top());
			}
		}
	}
	void pop() {
		if (!s.empty()) {
			s.pop();
			least.pop();
		}
	}
	int top() {
		return s.top();
	}
	int min() {
		return least.top();
	}
};

void test() {
	Solution s;
	s.push(3);
	cout << s.min() << "  ";
	s.push(4);
	cout << s.min() << "  ";
	s.push(2);
	cout << s.min() << "  ";
	s.push(3);
	cout << s.min() << "  ";
	s.pop();
	cout << s.min() << "  ";
	s.pop();
	cout << s.min() << "  ";
	s.pop();
	cout << s.min() << "  ";
	s.push(0);
	cout << s.min() << "  ";
}

int main() {
	test();
	system("pause");
	return 0;
}