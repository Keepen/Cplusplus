#include <stdio.h>
#include <stdlib.h>

typedef struct tree {
	char data;
	struct tree* _left;
	struct tree* _right;
}tree;

tree* create(char* a, int* p) {
	if (a[*p] != '#') {
		tree* root = (tree*)malloc(sizeof(tree));
		root->data = a[*p];
		(*p)++;
		root->_left = create(a, p);
		(*p)++;
		root->_right = create(a, p);
		return root;
	}
	else {
		return NULL;
	}
}


void preorder(tree* root) {
	if (root == NULL) {
		return;
	}
	printf("%c  ", root->data);
	preorder(root->_left);
	preorder(root->_right);
}


void test() {
	tree* root;
	char* str = "124###3##";
	int p = 0;
	
	root = create(str, &p);
	preorder(root);
}

int main() {
	test();
	system("pause");
	return 0;
}