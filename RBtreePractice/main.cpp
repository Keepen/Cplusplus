#include <iostream>
using namespace std;
//红黑树：本质上还是一棵二叉搜索树
//	性质：
//		1.根节点是黑色的
//		2.对于任意节点，从该节点到其后代叶节点路径上的黑色结点数目均相同
//      3.不能有连续的红色结点出现

enum Color{RED, BLACK};

template<class Key, class Value>
struct RBTNode {
	//每个结点信息都是一个键值对
	pair<Key, Value> _data;
	typedef RBTNode<Key, Value> Node;
	typedef Node* pNode;
	pNode _left;
	pNode _right;
	pNode _parent;
	Color _color;
	RBTNode(const pair<Key, Value>& data = pair<Key, Value>()) :
		_data(data),
		_left(nullptr),
		_right(nullptr),
		_parent(nullptr),
		_color(RED)
	{}
};


template <class Key,class Value>
class RBTree {
public:
	typedef RBTNode<Key, Value> Node;
	typedef Node* pNode;
	RBTree() :_header(new Node) {
		_header->_color = BLACK;
		_header->_left = _header;
		_header->_parent = nullptr;
		_header->_right = _header;
	}

	//1.左边的左边高：右旋
	void RotateRight(pNode node) {
		pNode subL = node->_left;
		pNode subLR = subL->_right;

		node->_left = subLR;
		subL->_right = node;
		if (subLR) {
			subLR->_parent = node;
		}

		//判断是否是根节点
		if (node == _header->_parent) {
			_header->_parent = subL;
			subL = _header->_parent;
		}
		else {
			pNode parent = node->_parent;
			if (parent->_left == node) {
				parent->_left = subL;
			}
			else {
				parent->_right = subL;
			}
			subL->_parent = parent;
		}
		node->_parent = subL;
	}

	//2.右边的右边高：左旋
	void RotateLeft(pNode node) {
		pNode subR = node->_right;
		pNode subRL = subR->_left;

		node->_right = subRL;
		subR->_left = node;
		if (subRL) {
			subRL->_parent = node;
		}

		//判断是否是根节点
		if (node == _header->_parent) {
			_header->_parent = subR;
			subR = _header->_parent;
		}
		else {
			pNode parent = node->_parent;
			if (parent->_left == node) {
				parent->_left = subR;
			}
			else {
				parent->_right = subR;
			}
			subR->_parent = parent;
		}
		node->_parent = subR;
	}

	//3.左边的右边高：先左旋，再右旋
	void RotateLR(pNode node) {
		pNode subL = node->_left;
		pNode subLR = subL->_right;
		RotateLeft(subL);
		RotateRight(node);
	}

	//4.右边的左边高：先右旋，再左旋
	void RotateRL(pNode node) {
		pNode subR = node->_right;
		pNode subRL = subR->_left;
		RotateRight(subR);
		RotateLeft(node);
	}

	bool Insert(const pair<Key, Value>& data) {
		//1.先判断是否是空树
		pNode root = _header->_parent;
		if (root == nullptr) {
			pNode node = new Node;
			node->_color = BLACK;
			node->_data = data;
			node->_parent = _header;
			_header->_left = node;
			_header->_right = node;
			_header->_parent = node;
			return true;
		}
		//2.不是空树，按照二叉搜索树的性质查找到合适的位置，进行插入
		pNode cur = root;
		pNode parent = nullptr;
		while (cur) {
			if (cur->_data.first == data.first) {
				cout << "same node!!!" << endl;
				return false;
			}
			parent = cur;
			if (cur->_data.first < data.first) {
				cur = cur->_right;
			}
			else {
				cur = cur->_left;
			}
		}
		cur = new Node(data);
		if (parent->_data.first > data.first) {
			parent->_left = cur;
		}
		else {
			parent->_right = cur;
		}
		cur->_parent = parent;
		
		//3.判断是否破坏了红黑树的性质，并进行旋转
		//有两个连在一起的红色节点
		while (parent && parent->_color == RED) {
			pNode gparent = parent->_parent;
			if (gparent->_left == parent) {
				pNode uncle = gparent->_right;
				//1.叔叔节点存在，且为红色
				if (uncle && uncle->_color == RED) {
					//直接修改，parent和uncle结点的颜色为黑色，再将gparent的颜色修改为红色即可
					parent->_color = BLACK;
					uncle->_color = BLACK;
					gparent->_color = RED;
					cur = gparent;
					parent = cur->_parent;
				}
				//2.叔叔节点不存在，或者存在但为黑
				else {
					//考虑是否需要双旋
					if (cur == parent->_right) {
						RotateLeft(parent);
						swap(cur, parent);
					}
					RotateRight(gparent);
					parent->_color = BLACK;
					gparent->_color = RED;
				}
			}
			//parent在右侧情况
			else {
				pNode uncle = gparent->_left;
				//同样，先考虑叔叔节点存在，并且是红色的情况
				if (uncle && uncle->_color == RED) {
					//直接修改颜色即可
					uncle->_color = BLACK;
					parent->_color = BLACK;
					gparent->_color = RED;
					cur = gparent;
					parent = cur->_parent;
				}
				//叔叔节点不存在，或者存在但是为黑的情况
				else {
					//先判断是否需要双旋的场景
					if (cur == parent->_left) {
						RotateRight(parent);
						swap(cur, parent);
					}
					RotateLeft(gparent);
					parent->_color = BLACK;
					gparent->_color = RED;
				}
			}
		}
		//在旋转，重新着色的过程中可能影响到了根节点，为根节点重新着色
		_header->_parent->_color = BLACK;
		_header->_left = LeftMost();
		_header->_right = RightMost();
		return true;
	}

	//判断是否是红黑树
	bool IsRBTree() {
		if (_header->_parent == _header) {
			cout << "空树也是红黑树！！！" << endl;
			return true;
		}
		//1.根节点是否是黑色的
		if (_header->_parent->_color == RED) {
			cout << "根节点必须是黑色的！！！" << endl;
			return false;
		}
		//判断每条路径上的黑色节点数目是否相同
		size_t count = 0;
		pNode cur = _header->_parent;
		while (cur) {
			if (cur->_color == BLACK) {
				++count;
			}
			cur = cur->_left;
		}
		size_t bc = 0;
		return _IsRBTree(_header->_parent, bc, count);
	}
	bool _IsRBTree(pNode root, size_t bc, size_t count) {
		//走到空时，判断黑色结点的数目是否相同
		if (root == nullptr) {
			if (bc != count) {
				cout << "每条路径上的黑色结点数目必须相同！！！" << endl;
				return false;
			}
			return true;
		}

		if (root->_color == BLACK) {
			++bc;
		}
		//判断是否有连续的红色结点
		pNode parent = root->_parent;
		if (parent && parent->_color == root->_color && parent->_color == RED) {
			cout << "不能有连续的红色节点！！！" << endl;
			return false;
		}
		return _IsRBTree(root->_left, bc, count) &&
			_IsRBTree(root->_right, bc, count);
	}

    void _InOrder(pNode root) {
		if (root == nullptr) {
			return;
		}
		_InOrder(root->_left);
		cout << root->_data.first << " ";
		_InOrder(root->_right);
	}

	void InOrder() {
		_InOrder(_header->_parent);
	}


private:
	pNode LeftMost() {
		pNode cur = _header->_parent;
		while (cur->_left) {
			cur = cur->_left;
		}
		return cur;
	}

	pNode RightMost() {
		pNode cur = _header->_parent;
		while (cur->_right) {
			cur = cur->_right;
		}
		return cur;
	}
private:
	pNode _header;
};

int main() {

	RBTree<int,int> rbt;
	rbt.Insert(make_pair(1,1));
	rbt.Insert(make_pair(2,1));
	rbt.Insert(make_pair(3,1));
	rbt.Insert(make_pair(4,1));
	rbt.Insert(make_pair(5,1));
	rbt.Insert(make_pair(7,1));

	rbt.InOrder();
	cout << "\n" << rbt.IsRBTree() << endl;
	system("pause");
	return 0;
}
