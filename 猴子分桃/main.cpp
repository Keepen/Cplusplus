// write your code here cpp
#include <iostream>
using namespace std;
typedef unsigned long long ull;

ull oldNum(int n, ull sum) {
	if (n == 1) {
		return 1;
	}
	ull old_sum = 0;
	int temp = n;
	while(n--){
		sum = sum - 1 - (sum - 1) / 5;
	}
	sum = sum + temp;
	return sum;
}

ull init(int n) {
	if (n == 1) {
		return 1;
	}
	ull temp = 0;
	ull sum = 0;
	while (--n > 0) {
		sum = (temp + 4) * 5 + 1;
		temp = sum - 1;
	}
	return sum;
}
void solu() {
	int n;
	while (cin >> n) {
		if (n == 0) {
			break;
		}
		ull sum = init(n);
		ull old_num = oldNum(n, sum);
		cout << sum << " ";
		cout << old_num << endl;
	}
}

int main() {
	solu();
	return 0;
}