#include<stdio.h>
#include<stdlib.h>
typedef struct BiTNode
{
	int data;
	struct BiTNode *lchild, *rchild;
}BiTNode;
BiTNode *p;
BiTNode * BT;
int count,a;
BiTNode * creatTree(BiTNode * BT)
{
	int ch;
	printf("请输入数字：");
	scanf("%d", &ch);
	if (ch == 0) 
		BT = NULL;
	else
	{
		BT = (BiTNode *)malloc(sizeof(BiTNode));
		BT->data = ch;
		BT->lchild = creatTree(BT->lchild);
		BT->rchild = creatTree(BT->rchild);
	}
	return BT;
}
void preorder(BiTNode *root)
{
	BiTNode   *p;
	p = root;
	if (p == NULL) {
		printf("_ ");
	}
	else {
		printf("%d ", p->data);
		preorder(p->lchild);
		preorder(p->rchild);
	}
}
void inorder(BiTNode *root)
{
	BiTNode   *p;
	p = root;
	if (p == NULL) {
		printf("_ ");
	}
	else
	{
		inorder(p->lchild);
		printf("%d ", p->data);
		inorder(p->rchild);
	}
}
void PostOrder(BiTNode *root)
{
	BiTNode   *p;
	p = root;
	if (p == NULL) {
		printf("_ ");
	}
	else
	{
		PostOrder(p->lchild);
		PostOrder(p->rchild);
		printf("%d ", p->data);
	}
}
int height(BiTNode *BT) {
	int l, r;
	if (BT == NULL)
		return 0;
	else {
		l = height(BT->lchild);
		r = height(BT->rchild);
	}
	if (l > r) {
		return l + 1;
	}
	else {
		return r + 1;
	}
}
void countLeaf(BiTNode *BT)
{
	if (BT != NULL) {
		if (BT->lchild == NULL && BT->rchild == NULL) {
			count++;
			printf("%d ", BT->data);
		}
		countLeaf(BT->lchild);
		countLeaf(BT->rchild);
	}
}
void find(BiTNode *root,int x)
{
	BiTNode *p;
	p = root;
	if (p != NULL) {
		if (p->data == x) {
			a=1;
		}
		find(p->lchild,x);
		find(p->rchild,x);
	}
}
int main()
{
	BT = creatTree(BT);
	printf("先序遍历：");
	preorder(BT);
	printf("\n");
	printf("中序遍历：");
	inorder(BT);
	printf("\n");
	printf("后序遍历：");
	PostOrder(BT);
	printf("\n");
	int num = height(BT);
	printf("层数为：%d\n", num);
	countLeaf(BT);
	printf("\n");
	printf("叶子结点个数为：%d\n", count);

	//差一个判断是否为完全二叉树。

	int x;
	printf("请输入你想查结点的值：");
	scanf("%d", &x);
	find(BT, x);
	if (a==1)
		printf("结点存在。\n");
	else
		printf("结点不存在。\n");
	return 0;
}