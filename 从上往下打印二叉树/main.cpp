#include <iostream>
#include <queue>
#include <vector>
using namespace std;

//二叉树的层序遍历：
//	思路：
//		将该节点的左右孩子入队，自己出队


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
	vector<int> PrintFromTopToBottom(TreeNode* root) {
		vector<int> ret;
		if (root == nullptr) {
			ret.resize(0);
			return ret;
		}
		queue<TreeNode*> q;
		q.push(root);
		TreeNode* cur = root;
		while (!q.empty() && cur) {
			cur = q.front();
			q.pop();
			ret.push_back(cur->val);
			if (cur->left) {
				q.push(cur->left);
			}
			if (cur->right) {
				q.push(cur->right);
			}
		}
		return ret;
	}
};


int main() {
	system("pause");
	return 0;
}