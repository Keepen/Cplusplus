#include <iostream>
using namespace std;
//假币质量比真比轻
//	一堆真币中混进了一张假币，问用天平最快最多称几次才能找到假币
//	一次称重最多在3张币中找到假币
//	1 -- 3
//	2 -- 9


int main() {
	int n;
	while (cin >> n && n) {
		int ret = 0;
		long long sum = 1;
		while (sum < n) {
			sum *= 3;
			ret++;
		}
		cout << ret << endl;
	}
	system("pause");
	return 0;
}