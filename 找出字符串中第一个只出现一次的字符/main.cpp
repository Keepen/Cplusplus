#include <iostream>
#include <string>
using namespace std;
int main() {
	string s;
	while (cin >> s) {
		char ret[120] = { 0 };
		for (const auto& e : s) {
			ret[e]++;
		}
		bool flag = false;
		for (const auto& e : s) {
			if (ret[e] == 1) {
				cout << e << endl;
				flag = true;
				break;
			}
		}
		if (!flag) {
			cout << -1 << endl;
		}
	}
	return 0;
}