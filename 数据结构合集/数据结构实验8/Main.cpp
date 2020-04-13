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
	printf("���������֣�");
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
	printf("���������");
	preorder(BT);
	printf("\n");
	printf("���������");
	inorder(BT);
	printf("\n");
	printf("���������");
	PostOrder(BT);
	printf("\n");
	int num = height(BT);
	printf("����Ϊ��%d\n", num);
	countLeaf(BT);
	printf("\n");
	printf("Ҷ�ӽ�����Ϊ��%d\n", count);

	//��һ���ж��Ƿ�Ϊ��ȫ��������

	int x;
	printf("��������������ֵ��");
	scanf("%d", &x);
	find(BT, x);
	if (a==1)
		printf("�����ڡ�\n");
	else
		printf("��㲻���ڡ�\n");
	return 0;
}