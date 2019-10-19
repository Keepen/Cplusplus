#include <iostream>
using namespace std;
//������������ϻ���һ�ö���������
//	���ʣ�
//		1.���ڵ��Ǻ�ɫ��
//		2.��������ڵ㣬�Ӹýڵ㵽����Ҷ�ڵ�·���ϵĺ�ɫ�����Ŀ����ͬ
//      3.�����������ĺ�ɫ������

enum Color{RED, BLACK};

template<class Key, class Value>
struct RBTNode {
	//ÿ�������Ϣ����һ����ֵ��
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

	//1.��ߵ���߸ߣ�����
	void RotateRight(pNode node) {
		pNode subL = node->_left;
		pNode subLR = subL->_right;

		node->_left = subLR;
		subL->_right = node;
		if (subLR) {
			subLR->_parent = node;
		}

		//�ж��Ƿ��Ǹ��ڵ�
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

	//2.�ұߵ��ұ߸ߣ�����
	void RotateLeft(pNode node) {
		pNode subR = node->_right;
		pNode subRL = subR->_left;

		node->_right = subRL;
		subR->_left = node;
		if (subRL) {
			subRL->_parent = node;
		}

		//�ж��Ƿ��Ǹ��ڵ�
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

	//3.��ߵ��ұ߸ߣ���������������
	void RotateLR(pNode node) {
		pNode subL = node->_left;
		pNode subLR = subL->_right;
		RotateLeft(subL);
		RotateRight(node);
	}

	//4.�ұߵ���߸ߣ���������������
	void RotateRL(pNode node) {
		pNode subR = node->_right;
		pNode subRL = subR->_left;
		RotateRight(subR);
		RotateLeft(node);
	}

	bool Insert(const pair<Key, Value>& data) {
		//1.���ж��Ƿ��ǿ���
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
		//2.���ǿ��������ն��������������ʲ��ҵ����ʵ�λ�ã����в���
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
		
		//3.�ж��Ƿ��ƻ��˺���������ʣ���������ת
		//����������һ��ĺ�ɫ�ڵ�
		while (parent && parent->_color == RED) {
			pNode gparent = parent->_parent;
			if (gparent->_left == parent) {
				pNode uncle = gparent->_right;
				//1.����ڵ���ڣ���Ϊ��ɫ
				if (uncle && uncle->_color == RED) {
					//ֱ���޸ģ�parent��uncle������ɫΪ��ɫ���ٽ�gparent����ɫ�޸�Ϊ��ɫ����
					parent->_color = BLACK;
					uncle->_color = BLACK;
					gparent->_color = RED;
					cur = gparent;
					parent = cur->_parent;
				}
				//2.����ڵ㲻���ڣ����ߴ��ڵ�Ϊ��
				else {
					//�����Ƿ���Ҫ˫��
					if (cur == parent->_right) {
						RotateLeft(parent);
						swap(cur, parent);
					}
					RotateRight(gparent);
					parent->_color = BLACK;
					gparent->_color = RED;
				}
			}
			//parent���Ҳ����
			else {
				pNode uncle = gparent->_left;
				//ͬ�����ȿ�������ڵ���ڣ������Ǻ�ɫ�����
				if (uncle && uncle->_color == RED) {
					//ֱ���޸���ɫ����
					uncle->_color = BLACK;
					parent->_color = BLACK;
					gparent->_color = RED;
					cur = gparent;
					parent = cur->_parent;
				}
				//����ڵ㲻���ڣ����ߴ��ڵ���Ϊ�ڵ����
				else {
					//���ж��Ƿ���Ҫ˫���ĳ���
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
		//����ת��������ɫ�Ĺ����п���Ӱ�쵽�˸��ڵ㣬Ϊ���ڵ�������ɫ
		_header->_parent->_color = BLACK;
		_header->_left = LeftMost();
		_header->_right = RightMost();
		return true;
	}

	//�ж��Ƿ��Ǻ����
	bool IsRBTree() {
		if (_header->_parent == _header) {
			cout << "����Ҳ�Ǻ����������" << endl;
			return true;
		}
		//1.���ڵ��Ƿ��Ǻ�ɫ��
		if (_header->_parent->_color == RED) {
			cout << "���ڵ�����Ǻ�ɫ�ģ�����" << endl;
			return false;
		}
		//�ж�ÿ��·���ϵĺ�ɫ�ڵ���Ŀ�Ƿ���ͬ
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
		//�ߵ���ʱ���жϺ�ɫ������Ŀ�Ƿ���ͬ
		if (root == nullptr) {
			if (bc != count) {
				cout << "ÿ��·���ϵĺ�ɫ�����Ŀ������ͬ������" << endl;
				return false;
			}
			return true;
		}

		if (root->_color == BLACK) {
			++bc;
		}
		//�ж��Ƿ��������ĺ�ɫ���
		pNode parent = root->_parent;
		if (parent && parent->_color == root->_color && parent->_color == RED) {
			cout << "�����������ĺ�ɫ�ڵ㣡����" << endl;
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
