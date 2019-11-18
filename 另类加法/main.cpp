#include <iostream>
using namespace std;
class UnusualAdd {
public:
	int addAB(int A, int B) {
		// write code here
		int ret = 0;
		int last = 0;       //保存进位信息
		for (int i = 0; i < 32; i++) {
			int x = (A >> i) & 0x01;
			int y = (B >> i) & 0x01;
			int cur = ((x ^ y) ^ last) << i;    //保存本位和
			ret = (ret | cur);// | (last << i);
			last = (((x^y) && last) || ((x^last) && y) || ((y^last) && x) || (x&&y&&last));
		}
		return ret;
	}
};


int main() {
	UnusualAdd s;
	cout << s.addAB(1, 2) << endl;
	system("pause");
	return 0;
}