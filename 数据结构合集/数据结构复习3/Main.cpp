#include<stdio.h>
#include<stdlib.h>
typedef struct BTree
{
	int data;
	BTree *lchild,*rchild;
}BTree;
BTree *BT;
BTree *CreatTree(BTree *BT)
{
	int num;
	printf("���������֣�");
	scanf("%d", &num);
	if (num == 0) {
		BT = NULL;
	}
	else {
		BT = (BTree*)malloc(sizeof(BTree));
		BT->data = num;
		BT->lchild=CreatTree(BT->lchild);
		BT->rchild=CreatTree(BT->rchild);
	}
	return BT;
}
void preorder(BTree *root)
{
	BTree *p;
	p = root;
	if (p == NULL) {
		printf("_ ");
	}
	else {
		printf("%d ",p->data);
		preorder(p->lchild);
		preorder(p->rchild);
	}

}
void inorder(BTree *root)
{
	BTree *p;
	p = root;
	if (p == NULL) {
		printf("_ ");
	}
	else {
		inorder(p->lchild);
		printf("%d ", p->data);
		inorder(p->rchild);
	}
}
void postorder(BTree *root)
{
	BTree *p;
	p = root;
	if (p == NULL) {
		printf("_ ");
	}
	else {
		postorder(p->lchild);
		postorder(p->rchild);
		printf("%d ", p->data);
	}
}
int main()
{
	BT=CreatTree(BT);
	printf("���������");
	preorder(BT);
	printf("\n���������");
	inorder(BT);
	printf("\n���������");
	postorder(BT);
	return 0;
}