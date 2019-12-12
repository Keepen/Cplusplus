#include <iostream>
#include <algorithm>
using namespace std;


struct Node {
	int _size;						//1.空闲分区大小
	int _start;						//2.起始地址
	struct Node* _next = nullptr;	
};

void print(Node* head);

//分配
//1.首次适应算法
void firstFit(Node* head, Node* sz) {
	Node* list = head;
	Node* last = list;
	while (list && list->_size < sz->_size) {
		last = list;
		list = list->_next;
	}
	sz->_start = list->_start;
	//如果某一结点的大小恰好等于需要的大小，就将该节点从空闲分区删除
	if (list->_size == sz->_size) {
		last->_next = list->_next;
		delete list;
		list = nullptr;
	}
	//如果某一结点的大小大于需要的大小，修改当前结点的大小即可
	else {
		list->_size -= sz->_size;
		list->_start += sz->_size;
	}
}

//2.循环首次适应：返回本次遍历之后的指针走向
Node* cycleFirstFit(Node* head, Node* cur, Node* sz) {
	Node* list = cur;
	Node* last = cur;
	while (list->_size < sz->_size) {
		last = list;
		list = list->_next;
		if (!list) {
			list = head;
		}
	}
	sz->_start = list->_start;
	if (list->_size == sz->_size) {
		if (list->_next == nullptr) {
			delete list;
			list = nullptr;
			last->_next = nullptr;
		}
		else {
			last->_next = list->_next;
			delete list;
			list = nullptr;
		}
	}
	else {
		list->_size -= sz->_size;
	}
	return list;
}

//3.最佳适应
void fittest(Node* head, Node* sz) {
	Node* list = head;
	Node* last = list;
	while (list && list->_size <= sz->_size) {
		last = list;
		list = list->_next;
	}
	sz->_start = list->_start;
	//如果某一结点的大小恰好等于需要的大小，就将该节点从空闲分区删除
	if (list->_size == sz->_size) {
		last->_next = list->_next;
		delete list;
		list = nullptr;
	}
	//如果某一结点的大小大于需要的大小，修改当前结点的大小即可
	else {
		list->_size -= sz->_size;
		list->_start += sz->_size;
	}
}

//4.最坏适应
void baddest(Node* head, Node* sz) {
	Node* list = head;
	Node* last = head;
	while (list->_next) {
		last = list;
		list = list->_next;
	}
	sz->_start = list->_start;
	//直接找到最大的，进行分配
	if (sz->_size == list->_size) {
		last->_next = nullptr;
		delete list;
		list = nullptr;
	}
	else {
		list->_size -= sz->_size;
		list->_start += sz->_size;
	}
}

//回收
void Recycle(Node* head, int start, int size) {
	int last = start + size;
	Node* cur = head;
	bool flag_up = false;
	bool flag_down = false;
	//上邻空闲分区
	while (cur) {
		if (cur->_start + cur->_size == start) {
			cur->_size += size;
			flag_up = true;
			break;
		}
		cur = cur->_next;
	}
	cur = head;
	//判断是否下邻空闲分区
	while (cur) {
		if (last == cur->_start) {
			cur->_start = start;
			cur->_size += size;
			flag_down = true;
			break;
		}
		cur = cur->_next;
	}


	Node* node = (Node*)malloc(sizeof(Node));
	if (!flag_up && !flag_down) {
		//上下均不邻空闲分区
		node->_size = size;
		node->_start = start;
		//直接头插到空闲分区链表中
		node->_next = head;
		head = node;
	}
	//判断分区是否有黏着在一起 -- 即是否需要合并
	cur = head;
	Node* las = head;
	while (cur->_next) {
		Node* del = head;
		if (cur->_start + cur->_size == cur->_next->_start) {
			las = cur->_next->_next;	//当前分区的下一个的下一个
			del = cur->_next;
			cur->_size += cur->_next->_size;
			cur->_next = cur->_next->_next;
			cout << "进去" << endl;
			delete del;
			del = nullptr;		//如果有黏着在一起的分区，将其合并，删除下分区
			cur = las;
		}
		else {
			cur = cur->_next;
		}
	}
	print(head);
}


//地址递增排序
Node* Addr(Node* head) {
	Node* cur = head->_next;
	Node* newHead = new Node;
	newHead->_size = head->_size;
	newHead->_start = head->_start;
	while (cur) {
		Node* newCur = newHead;	//用来遍历新的有序链表
		Node* nlast = newHead;
		bool flag = false;	//表示每一次插入是否成功的标志
		while (newCur) {
			if (cur->_start < newCur->_start) {
				Node* node = new Node;
				node->_size = cur->_size;
				node->_start = cur->_start;
				node->_next = newCur;
				nlast->_next = node;
				flag = true;
				break;	//找到响应的位置了，赋值后跳出循环，将原链表的下一个结点进行拷贝
			}
			else {
				nlast = newCur;
				newCur = newCur->_next;
			}
		}
		if (!flag) {
			Node* node = new Node;
			node->_size = cur->_size;
			node->_start = cur->_start;
			nlast->_next = node;
		}
		cur = cur->_next;
	}
	return newHead;
}

//分区大小递增排序
Node* upSize(Node* head) {
	Node* newHead = new Node;
	newHead->_size = head->_size;
	newHead->_start = head->_start;
	Node* cur = head;
	while (cur) {
		Node* newCur = newHead;
		Node* nlast = newCur;
		bool flag = false;
		while (cur && newCur) {
			if (cur->_size < newCur->_size) {
				Node* node = new Node;
				node->_size = cur->_size;
				node->_start = cur->_start;
				node->_next = newCur;
				nlast->_next = node;
				flag = true;
				break;
			}
			else {
				nlast = newCur;
				newCur = newCur->_next;
			}
		}
		//表示找到了链表的尾部
		if (!flag) {
			Node* node = new Node;
			node->_size = cur->_size;
			node->_start = cur->_start;
			nlast->_next = node;
		}
		cur = cur->_next;
	}
	return newHead;
}

//分区大小递减排序
Node* downSize(Node* head) {
	Node* newHead = new Node;
	newHead->_size = head->_size;
	newHead->_start = head->_start;
	Node* cur = head;
	while (cur) {
		Node* newCur = newHead;
		Node* nlast = newCur;
		bool flag = false;
		while (cur && newCur) {
			if (cur->_size > newCur->_size) {
				Node* node = new Node;
				node->_size = cur->_size;
				node->_start = cur->_start;
				node->_next = newCur;
				nlast->_next = node;
				flag = true;
				break;
			}
			else {
				nlast = newCur;
				newCur = newCur->_next;
			}
		}
		//表示找到了链表的尾部
		if (!flag) {
			Node* node = new Node;
			node->_size = cur->_size;
			node->_start = cur->_start;
			nlast->_next = node;
		}
		cur = cur->_next;
	}
	return newHead;
}

//打印空闲分区情况
void print(Node* head) {
	head = Addr(head);
	Node* cur = head;
	cout << "剩余分区情况:" << endl;
	int i = 1;
	printf("分区号\t分区大小\t起始地址\n");
	while (cur) {
		printf("%d\t%d\t\t%d\n", i++, cur->_size, cur->_start);
		cur = cur->_next;
	}
}

//录入空闲分区情况
void info(Node* head) {
	cout << "请输入当前分区的数目：" << endl;
	int n;
	cin >> n;
	int i = 1;
	Node* last = nullptr;
	while (n--) {
		Node* node = new Node;
		cout << "请输入第 " << i << "个分区的大小：";
		if (i == 1) {
			cin >> head->_size;
		}
		else {
			cin >> node->_size;
		}
		cout << "请输入第 " << i << "个分区的起始地址： ";
		if (i == 1) {
			cin >> head->_start;
		}
		else {
			cin >> node->_start;
		}
		if (i == 2) {
			head->_next = node;
			last = node;
		}
		else if (i > 2) {
			last->_next = node;
			last = node;
		}
		++i;
	}
}

void menu() {
	cout << "---------------------------------------------------" << endl;
	cout << "\t\t1.录入初始空闲分区情况" << endl;
	cout << "\t\t2.首次适应" << endl;
	cout << "\t\t3.循环首次适应" << endl;
	cout << "\t\t4.最佳适应" << endl;
	cout << "\t\t5.最坏适应" << endl;
	cout << "\t\t6.输出空闲分区情况" << endl;
	cout << "---------------------------------------------------" << endl;

}

int main() {
	menu();
	Node* head = new Node;	//分区的头节点
	Node* cur = head;	//用来记录循环首次适应每次遍历的结果

	Node* busyHead = new Node;	//用来记录每个申请的结点的大小、以及起始地址
	Node* busyLast = busyHead;
	info(head);
	print(head);
	cout << endl;
	
	cout << "请选择算法：" << endl;
	int n;
	cin >> n;
	bool flag = true;
	while (1) {
		char c = 'e';
		cout << "请选择：a.申请；r.释放；e.结束" << endl;
		cin >> c;
		if (c == 'e') {
			break;
		}
		if (c == 'a') {
			Node* sz = new Node;	//申请的大小
			cin >> sz->_size;
			if (flag) {
				busyHead->_next = sz;
				busyLast = sz;
				flag = false;
			}
			else {
				busyLast->_next = sz;
				busyLast = sz;
			}
			if (n == 2) {
				firstFit(head, sz);
				Addr(head);
			}
			else if (n == 3) {
				cur = cycleFirstFit(head, cur, sz);
				Addr(head);
			}
			else if (n == 4) {
				fittest(head, sz);
				upSize(head);
			}
			else if (n == 5) {
				baddest(head, sz);
				downSize(head);
			}
		}
		else if (c == 'r') {
			Node* cur = new Node;
			cout << "请输入释放的分区的大小:";
			cin >> cur->_size;
			Node* busyCur = busyHead->_next;
			while (busyCur) {
				if (busyCur->_size == cur->_size)
					break;
				busyCur = busyCur->_next;
			}
			Recycle(head, busyCur->_start, busyCur->_size);
		}
	}
	
	print(head);
	system("pause");
	return 0;
}