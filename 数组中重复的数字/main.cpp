#include <iostream>
#include <unordered_map>
using namespace std;

//���ǽ������е�һ���ظ��������õ�����


class Solution {
public:
	// Parameters:
	//        numbers:     an array of integers
	//        length:      the length of array numbers
	//        duplication: (Output) the duplicated number in the array number
	// Return value:       true if the input is valid, and there are some duplications in the array number
	//                     otherwise false
	bool duplicate(int numbers[], int length, int* duplication) {
		unordered_map<int, int> key;
		for (int i = 0; i < length; ++i) {
			if (numbers[i] >= length || numbers[i] < 0) {
				return false;
			}
			key[numbers[i]]++;
		}
		for (int i = 0; i < length; ++i) {
			if (key[numbers[i]] > 1) {
				*duplication = numbers[i];
				return true;
			}
		}
		return false;
	}

	//�Ż��汾��
	/*bool duplicate(int numbers[], int length, int* duplication) {
		unordered_map<int, int> key;
		for (int i = 0; i < length; ++i) {
			if (numbers[i] >= length || numbers[i] < 0) {
				return false;
			}
			++key[numbers[i]];
			if (key[numbers[i]] > 1) {
				*duplication = numbers[i];
				return true;
			}
		}
		return false;
	}*/
};


int main() {
	system("pause");
	return 0;
}