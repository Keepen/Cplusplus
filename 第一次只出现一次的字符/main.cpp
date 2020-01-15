#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;
class Solution {
public:
	int FirstNotRepeatingChar(string str) {
		unordered_map<char, int> s;
		for (auto& e : str) {
			s[e]++;
		}
		for (size_t i = 0; i < str.size(); ++i) {
			if (s[str[i]] == 1) {
				return i;
			}
		}
		return -1;
	}
};

int main() {
	system("pause");
	return 0;
}