#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
string add(string& addend, string& augend) {
	string ret;
	reverse(addend.begin(), addend.end());
	reverse(augend.begin(), augend.end());
	string::iterator it1 = addend.begin();
	string::iterator it2 = augend.begin(); 
	char arr[] = { '0','1','2','3','4','5','6','7','8','9' };
	int temp = 0;	//计算本位和
	int last = 0;	//计算进位
	while (it1 != addend.end() && it2 != augend.end()) {
		temp = *it1 - 0x30 + *it2 - 0x30 + last;	//本位和
		ret += arr[temp % 10];		//本位加进位	
		last = temp / 10;			//进位
		++it1;
		++it2;
	}
	if (it1 == addend.end()) {
		while (it2 != augend.end()) {
			temp = *it2 - 0x30 + last;
			ret += arr[(temp % 10) % 10];
			last = temp / 10;
			++it2;
		}
	}
	else if (it2 == augend.end()) {
		while (it1 != addend.end()) {
			temp = *it1 - 0x30 + last;
			ret += arr[temp % 10];
			last = temp / 10;
			++it1;
		}
	}
	if (last != 0) {
		ret += arr[last];
	}
	reverse(ret.begin(), ret.end());
	return ret;
}

int main() {
	string addend, augend;
	while (cin >> addend >> augend) {
		cout << add(addend, augend) << endl;
	}
	return 0;
}