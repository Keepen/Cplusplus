// write your code here cpp
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

string sum(string a, string b) {
	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());
	string::iterator it1 = a.begin(), it2 = b.begin();
	int cur = 0, last = 0;
	string sum;
	for (; it1 != a.end() && it2 != b.end(); ++it1, ++it2) {
		cur = (*it1 - '0' + *it2 - '0' + last) % 10;
		last = (*it1 - '0' + *it2 - '0' + last) / 10;
		sum += cur + '0';
	}
	while (it1 != a.end()) {
		cur = (*it1 - '0' + last) % 10;
		last = (*it1 - '0' + last) / 10;
		sum += cur + '0';
		++it1;

	}
	while (it2 != b.end()) {
		cur = (*it2 - '0' + last) % 10;
		last = (*it2 - '0' + last) / 10;
		sum += cur + '0';
		++it2;
	}
	if (last > 0) {
		sum += last + '0';
	}
	reverse(sum.begin(), sum.end());
	return sum;
}

string fib(int n) {
	string first = "0001";
	string second = first;
	if (n == 1 || n == 2) {
		return first;
	}
	string ret;
	while (n > 1) {
		ret = sum(first, second);
		second = first;
		first = ret;
		n--;
	}
	cout << ret << endl;
	return ret;
}

int main() {
	//string s1 = "12345";
	//string s2 = "90";
	//cout << sum(s1, s2);
	int n;
	while (cin >> n) {
		vector<int> key(n, 0);
		for (int i = 0; i < n; ++i) {
			cin >> key[i];
		}
		for (int i = 0; i < n; ++i) {
			string ret = fib(key[i]);
			for (int j = ret.size() - 4; j < ret.size(); ++j) {
				cout << ret[j];
			}
		}
		cout << endl;
	}
	system("pause");
	return 0;
}
