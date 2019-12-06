#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

//三角形：给定三条边，判断是否能构成三角形，由于数据量过大，所以只能用string型存放边的长度
//	字符串实现加减法

int isBig(string a, string b) {
	if (a.size() == b.size()) {
		string::iterator it1, it2;
		int i = 0;
		it1 = a.begin(); it2 = b.begin();
		for (; it1 != a.end(); ++it1, ++it2) {
			if (*it1 > *it2) {
				return 1;
			}
			else if (*it1 < *it2) {
				return -1;
			}
		}
		return 0;
	}
	else {
		if (a.size() > b.size()) {
			return 1;
		}
		else {
			return -1;
		}
	}
}


string add(string a, string b) {
	string ret;
	string::iterator it1, it2;
	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());
	it1 = a.begin(); it2 = b.begin();
	int cur = 0, last = 0;
	for (; it1 != a.end() && it2 != b.end(); ++it1, ++it2) {
		cur = (*it1 - '0' + *it2 - '0' + last) % 10;
		last = (*it1 - '0' + *it2 - '0' + last) / 10;
		ret += cur + '0';
	}
	while (it1 != a.end()) {
		cur = (*it1 - '0' + last) % 10;
		last = (*it1 - '0' + last) / 10;
		ret += cur + '0';
		++it1;
	}
	while (it2 != b.end()) {
		cur = (*it2 - '0' + last) % 10;
		last = (*it2 - '0' + last) / 10;
		ret += cur + '0';
		++it2;
	}
	if (last > 0) {
		ret += last + '0';
	}
	reverse(ret.begin(), ret.end());
	return ret;
}

string min(string a, string b) {
	//一定是大的减去小的
	int isEqual = isBig(a, b);
	if (isEqual == 0) {
		string tmp = "0";
		return tmp;
	}
	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());
	string ret;
	string::iterator it1, it2;
	it1 = a.begin(); it2 = b.begin();
	int cur = 0, last = 0;
	for (; it1 != a.end() && it2 != b.end(); ++it1, ++it2) {
		cur = ((*it1 - '0') - (*it2 - '0') + last) % 10;
		if (cur < 0) {
			cur = ((*it1 - '0') + 10 - (*it2 - '0') + last) % 10;
			last = -1;
		}
		else {
			last = 0;
		}
		ret += cur + '0';
	}
	while (it1 != a.end()) {
		cur = (*it1 - '0' + last) % 10;
		if (cur < 0) {
			cur = (*it1 - '0' + 10 + last) % 10;
			last = -1;
		}
		else {
			last = 0;
		}
		ret += cur + '0';
		++it1;
	}
	while (it2 != b.end()) {
		cur = (*it2 - '0' + last) % 10;
		if (cur < 0) {
			cur = (*it2 - '0' + last) % 10;
			last = -1;
		}
		else {
			last = 0;
		}
		ret += cur + '0';
		++it2;
	}
	reverse(ret.begin(), ret.end());
	string key;
	for (const auto& e : ret) {
		if (e != '0') {
			key += e;
		}
	}
	return key;
}

int main() {
	string a, b, c;
	while (cin >> a >> b >> c) {
		string plus_ab = add(a, b);
		int tmp = isBig(a, b);
		string min_ab;
		if (tmp < 0) {
			min_ab = min(b, a);
		}
		else {
			min_ab = min(a, b);
		}
		string plus_ac = add(a, c);
		string min_ac;
		tmp = isBig(a, c);
		if (tmp < 0) {
			min_ac = min(c, a);
		}
		else {
			min_ac = min(a, c);
		}
		string plus_bc = add(b, c);
		string min_bc;
		tmp = isBig(b, c);
		if (tmp < 0) {
			min_bc = min(c, b);
		}
		else {
			min_bc = min(b, c);
		}
		if (isBig(plus_ab, c) > 0 && isBig(plus_bc, a) > 0 && isBig(plus_ac, b) > 0
			&& isBig(min_ab, c) < 0 && isBig(min_ac, b) < 0 && isBig(min_bc, a) < 0) {
			cout << "Yes" << endl;
			continue;
		}
		cout << "No" << endl;

	}
	return 0;
}

