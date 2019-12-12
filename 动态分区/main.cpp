#include <iostream>
#include <algorithm>
using namespace std;


struct Node {
	int _size;						//1.���з�����С
	int _start;						//2.��ʼ��ַ
	struct Node* _next = nullptr;	
};

void print(Node* head);

//����
//1.�״���Ӧ�㷨
void firstFit(Node* head, Node* sz) {
	Node* list = head;
	Node* last = list;
	while (list && list->_size < sz->_size) {
		last = list;
		list = list->_next;
	}
	sz->_start = list->_start;
	//���ĳһ���Ĵ�Сǡ�õ�����Ҫ�Ĵ�С���ͽ��ýڵ�ӿ��з���ɾ��
	if (list->_size == sz->_size) {
		last->_next = list->_next;
		delete list;
		list = nullptr;
	}
	//���ĳһ���Ĵ�С������Ҫ�Ĵ�С���޸ĵ�ǰ���Ĵ�С����
	else {
		list->_size -= sz->_size;
		list->_start += sz->_size;
	}
}

//2.ѭ���״���Ӧ�����ر��α���֮���ָ������
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

//3.�����Ӧ
void fittest(Node* head, Node* sz) {
	Node* list = head;
	Node* last = list;
	while (list && list->_size <= sz->_size) {
		last = list;
		list = list->_next;
	}
	sz->_start = list->_start;
	//���ĳһ���Ĵ�Сǡ�õ�����Ҫ�Ĵ�С���ͽ��ýڵ�ӿ��з���ɾ��
	if (list->_size == sz->_size) {
		last->_next = list->_next;
		delete list;
		list = nullptr;
	}
	//���ĳһ���Ĵ�С������Ҫ�Ĵ�С���޸ĵ�ǰ���Ĵ�С����
	else {
		list->_size -= sz->_size;
		list->_start += sz->_size;
	}
}

//4.���Ӧ
void baddest(Node* head, Node* sz) {
	Node* list = head;
	Node* last = head;
	while (list->_next) {
		last = list;
		list = list->_next;
	}
	sz->_start = list->_start;
	//ֱ���ҵ����ģ����з���
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

//����
void Recycle(Node* head, int start, int size) {
	int last = start + size;
	Node* cur = head;
	bool flag_up = false;
	bool flag_down = false;
	//���ڿ��з���
	while (cur) {
		if (cur->_start + cur->_size == start) {
			cur->_size += size;
			flag_up = true;
			break;
		}
		cur = cur->_next;
	}
	cur = head;
	//�ж��Ƿ����ڿ��з���
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
		//���¾����ڿ��з���
		node->_size = size;
		node->_start = start;
		//ֱ��ͷ�嵽���з���������
		node->_next = head;
		head = node;
	}
	//�жϷ����Ƿ��������һ�� -- ���Ƿ���Ҫ�ϲ�
	cur = head;
	Node* las = head;
	while (cur->_next) {
		Node* del = head;
		if (cur->_start + cur->_size == cur->_next->_start) {
			las = cur->_next->_next;	//��ǰ��������һ������һ��
			del = cur->_next;
			cur->_size += cur->_next->_size;
			cur->_next = cur->_next->_next;
			cout << "��ȥ" << endl;
			delete del;
			del = nullptr;		//����������һ��ķ���������ϲ���ɾ���·���
			cur = las;
		}
		else {
			cur = cur->_next;
		}
	}
	print(head);
}


//��ַ��������
Node* Addr(Node* head) {
	Node* cur = head->_next;
	Node* newHead = new Node;
	newHead->_size = head->_size;
	newHead->_start = head->_start;
	while (cur) {
		Node* newCur = newHead;	//���������µ���������
		Node* nlast = newHead;
		bool flag = false;	//��ʾÿһ�β����Ƿ�ɹ��ı�־
		while (newCur) {
			if (cur->_start < newCur->_start) {
				Node* node = new Node;
				node->_size = cur->_size;
				node->_start = cur->_start;
				node->_next = newCur;
				nlast->_next = node;
				flag = true;
				break;	//�ҵ���Ӧ��λ���ˣ���ֵ������ѭ������ԭ�������һ�������п���
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

//������С��������
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
		//��ʾ�ҵ��������β��
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

//������С�ݼ�����
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
		//��ʾ�ҵ��������β��
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

//��ӡ���з������
void print(Node* head) {
	head = Addr(head);
	Node* cur = head;
	cout << "ʣ��������:" << endl;
	int i = 1;
	printf("������\t������С\t��ʼ��ַ\n");
	while (cur) {
		printf("%d\t%d\t\t%d\n", i++, cur->_size, cur->_start);
		cur = cur->_next;
	}
}

//¼����з������
void info(Node* head) {
	cout << "�����뵱ǰ��������Ŀ��" << endl;
	int n;
	cin >> n;
	int i = 1;
	Node* last = nullptr;
	while (n--) {
		Node* node = new Node;
		cout << "������� " << i << "�������Ĵ�С��";
		if (i == 1) {
			cin >> head->_size;
		}
		else {
			cin >> node->_size;
		}
		cout << "������� " << i << "����������ʼ��ַ�� ";
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
	cout << "\t\t1.¼���ʼ���з������" << endl;
	cout << "\t\t2.�״���Ӧ" << endl;
	cout << "\t\t3.ѭ���״���Ӧ" << endl;
	cout << "\t\t4.�����Ӧ" << endl;
	cout << "\t\t5.���Ӧ" << endl;
	cout << "\t\t6.������з������" << endl;
	cout << "---------------------------------------------------" << endl;

}

int main() {
	menu();
	Node* head = new Node;	//������ͷ�ڵ�
	Node* cur = head;	//������¼ѭ���״���Ӧÿ�α����Ľ��

	Node* busyHead = new Node;	//������¼ÿ������Ľ��Ĵ�С���Լ���ʼ��ַ
	Node* busyLast = busyHead;
	info(head);
	print(head);
	cout << endl;
	
	cout << "��ѡ���㷨��" << endl;
	int n;
	cin >> n;
	bool flag = true;
	while (1) {
		char c = 'e';
		cout << "��ѡ��a.���룻r.�ͷţ�e.����" << endl;
		cin >> c;
		if (c == 'e') {
			break;
		}
		if (c == 'a') {
			Node* sz = new Node;	//����Ĵ�С
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
			cout << "�������ͷŵķ����Ĵ�С:";
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