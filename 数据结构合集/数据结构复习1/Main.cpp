#include<stdio.h>
#include<stdlib.h>
typedef int elemtype;
typedef struct LNode
{
	elemtype data;
	LNode *next;
}LNode;
LNode *L,*p;
void initLNode(LNode *&L)
{
	LNode *q;
	p = (LNode*)malloc(sizeof(LNode));
	printf("请输入5个数：\n");
	scanf("%d", &p->data);
	p->next = NULL;
	q = p;
	L = p;
	L->next = p->next;
	p = p->next;
	for (int i = 1; i < 5; i++) {
		p = (LNode*)malloc(sizeof(LNode));
		scanf("%d", &p->data);
		p->next = NULL;
		q->next = p;
		q = p;
	}
}
void AddLNode(LNode *&L)
{
	elemtype num;
	printf("\n请输入你要增加的数：\n");
	scanf("%d", &num);
	LNode *p1, *p2;
	p = (LNode*)malloc(sizeof(LNode));
	p->data = num;
	p1 = L;
	while (p1 != NULL) {
		if (p1->data > num)
			break;
		else {
			p2 = p1;
			p1 = p1->next;
		}
	}
	if (p1 == L) {
		L = p;
		p->next = p1;
	}
	else {
		p->next = p1;
		p2->next = p;
	}
}
void DeleteLNode(LNode *&L)
{
	int x;
	printf("\n请输入你想删除的元素位置：\n");
	scanf("%d", &x);
	LNode *ap=NULL, *cp=NULL;
	ap = L;
	for (int i = 1; i < x; i++) {
		cp = ap;
		ap = ap->next;
	}
	if (ap != L) {
		cp->next = ap->next;
	}
	else {
		L = ap->next;
	}
}
void display(LNode *&L)
{
	p = L;
	while (p != NULL) {
		printf("%d  ", p->data);
		p = p->next;
	}
}

int main()
{
	initLNode(L);
	display(L);
	AddLNode(L);
	display(L);
	DeleteLNode(L);
	display(L);
	return 0;
}