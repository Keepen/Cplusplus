#include <iostream>
#include <queue>
using namespace std;
//二叉树的镜像：
//	所有左子树变成其右子树，右子树变成左子树

//方法：
//	1.递归
//	2.迭代：层序遍历的思想 -- 利用队列

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
		val(x), left(NULL), right(NULL) {
	}
};
class Solution {
public:
	//1.递归
	/*void Mirror(TreeNode *pRoot) {
		if (pRoot == nullptr) {
			return;
		}
		TreeNode* cur = pRoot->left;
		pRoot->left = pRoot->right;
		pRoot->right = cur;
		Mirror(pRoot->left);
		Mirror(pRoot->right);
	}*/
	//2.迭代
	void Mirror(TreeNode* pRoot) {
		if (pRoot == nullptr) {
			return;
		}
		queue<TreeNode*> q;
		q.push(pRoot);
		while (!q.empty()) {
			TreeNode* parent = q.front();
			q.pop();
			if (parent->left) {
				q.push(parent->left);
			}
			if (parent->right) {
				q.push(parent->right);
			}
			TreeNode* cur = parent->left;
			parent->left = parent->right;
			parent->right = cur;
		}
	}
};

void show(TreeNode* root) {
	if (root == nullptr) {
		return;
	}
	queue<TreeNode*> q;
	q.push(root);
	while (!q.empty()) {
		TreeNode* parent = q.front();
		cout << parent->val << "  ";
		q.pop();
		if (parent->left) {
			q.push(parent->left);
		}
		if (parent->right) {
			q.push(parent->right);
		}
	}
}
void test() {
	//建立一棵二叉树：8，6，10，5，7，9，11
	TreeNode* root = new TreeNode(8);
	TreeNode* t1 = new TreeNode(6);
	TreeNode* t2 = new TreeNode(10);
	TreeNode* t3 = new TreeNode(5);
	TreeNode* t4 = new TreeNode(7);
	TreeNode* t5 = new TreeNode(9);
	TreeNode* t6 = new TreeNode(11);
	root->left = t1; root->right = t2;
	t1->left = t3; t1->right = t4;
	t2->left = t5; t2->right = t6;
	show(root);
	cout << endl;
	Solution s;
	s.Mirror(root);
	show(root);
}

int main() {
	test();
	system("pause");
	return 0;
}