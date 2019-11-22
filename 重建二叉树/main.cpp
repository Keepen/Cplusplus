#include <iostream>
#include <vector>
using namespace std;

//根据先序与中序遍历还原一棵二叉树
//	思路：在先序中找到根节点，在中序中划分左右子树
//		再将左右子树的遍历结果得出，最后进行递归
//		递归的边界---数组中没有结点


struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution {
public:
	TreeNode * reConstructBinaryTree(vector<int> pre, vector<int> vin) {
		if (pre.size() == 0 || vin.size() == 0) {
			return nullptr;
		}
		TreeNode* root = (TreeNode*)malloc(sizeof(TreeNode));
		int pr = pre[0];    //获取根节点
		root->val = pr;
		int in = -1;
		for (int i = 0; i<vin.size(); ++i) {
			if (vin[i] == pr) {
				in = i;
				break;
			}
		}
		vector<int>left_pre(pre.begin() + 1, pre.end());
		vector<int>left_in(vin.begin(), vin.begin() + in);
		vector<int>right_pre(pre.begin() + in + 1, pre.end());
		vector<int>right_in(vin.begin() + in + 1, vin.end());
		root->left = reConstructBinaryTree(left_pre, left_in);
		root->right = reConstructBinaryTree(right_pre, right_in);
		return root;
	}
};

void print(TreeNode* root) {
	if (root == nullptr) {
		return;
	}
	cout << root->val << " ";
	print(root->left);
	print(root->right);
}


void test() {
	int ppre[] = { 1,2,4,7,3,5,6,8 };
	int pin[] = { 4,7,2,1,5,3,8,6 };
	vector<int> pre(ppre, ppre + sizeof(ppre) / sizeof(ppre[0]));
	vector<int> vin(pin, pin + sizeof(pin) / sizeof(pin[0]));
	Solution s;
	TreeNode* root = s.reConstructBinaryTree(pre, vin);
	print(root);
}


int main() {
	test();
	system("pause");
	return 0;
}