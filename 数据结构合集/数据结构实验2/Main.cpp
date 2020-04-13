#include<stdio.h>
#include<stdlib.h>
typedef int elemtype;
typedef struct LNode
{
	elemtype data;
	LNode *next;
}LNode;
LNode *L, *L1, *M,*p;
void CreatList(LNode *&L,int n)
{
	LNode *q;
	printf("请输入5个元素值，并按升序的方式输入：\n");
	p = (LNode*)malloc(sizeof(LNode));
	scanf("%d", &p->data);
	p->next = NULL;
	q = p;
	L = p;
	L->next = p->next;
	for (int i = 1; i < n; i++) {
		p = (LNode*)malloc(sizeof(LNode));
		scanf("%d", &p->data);
		p->next = NULL;
		q->next = p;
		q = p;
	}
}

void AddList(LNode *&L)
{
	elemtype n;
	printf("请输入要添加的数据：\n");
	scanf("%d", &n);
	LNode *p1 = NULL, *p2 = NULL;
	p = (LNode*)malloc(sizeof(LNode));
	p1 = L;
	if (p == NULL) {
		printf("分配空间失败。\n");
		exit(0);
	}
	p->data = n;
	while (p1!= NULL) {
		if (p1->data > n)
			break;
		else
		{
			p2 = p1;
			p1 = p1->next;
		}
	}
	if (p1 == L) {
		p->next = p1;
		L = p;
	}
	else {
		p->next = p1;
		p2->next = p;
	}
}

void DeleteList(LNode *&L, int i)
{
	LNode * ap, *cp;
	int j = 0;
	if (i < 0)
	{
		printf("被删除的序号值有错");
		exit(1);
	}
	cp = NULL;
	ap = L;
	if (L != NULL)
	{
		while (ap != NULL)
		{
			j++;
			if (j == i)
			{
				break;
			}
			cp = ap;
			ap = ap->next;
		}
		if (cp == NULL)
		{
			p = ap;
			L = ap->next;

		}
		else
		{
			p = ap;
			cp->next = ap->next;
		}
		free(p);
	}
}

elemtype FindMaxvalue(LNode *&L)
{
	p = L;
	elemtype max = 0;
	LNode * p;
	p = L;
	if (L == NULL)
	{
		printf("表为空表");
		exit(1);
	}
	while (p != NULL)
	{
		if (p->data > max)
		{
			max = p->data;
		}
		p = p->next;
	}
	return max;
}

void Display(LNode *&L)
{
	p = L;
	while (p != NULL)
	{
		printf("%d  ", p->data);
		p = p->next;
	}
	printf("\n");
}

void CreatList1(LNode *&L1, int n)
{
	LNode *q;
	printf("请输入5个元素值，并按升序的方式输入：\n");
	p = (LNode*)malloc(sizeof(LNode));
	scanf("%d", &p->data);
	p->next = NULL;
	q = p;
	L1 = p;
	L1->next = p->next;
	for (int i = 1; i < n; i++) {
		p = (LNode*)malloc(sizeof(LNode));
		scanf("%d", &p->data);
		p->next = NULL;
		q->next = p;
		q = p;
	}
}

void MergeList(LNode *&L,LNode *L1)
{
	LNode *p1, *p2;
	p1 = L;
	p2 = L1;
	M = (LNode*)malloc(sizeof(LNode));
	M->next= NULL;
	p = M;
	while (p1&&p2){
		if (p1->data < p2->data) {
			p->next = p1;
			p = p1;
			p1 = p1->next;
		}
		else {
			p->next = p2;
			p = p2;
			p2 = p2->next;
		}
		if (p1)
			p->next = p1;
		else
			p->next = p2;
	}
	M = M->next;
}

int main()
{
	CreatList(L,5);
	Display(L);
	AddList(L);
	Display(L);
	printf("请输入删除第几个数:\n");
	elemtype num;
	scanf("%d", &num);
	DeleteList(L, num);
	Display(L);
	printf("最大的数值为:%d\n", FindMaxvalue(L));
	CreatList1(L1, 5);
	MergeList(L, L1);
	Display(M);
	return 0;
}