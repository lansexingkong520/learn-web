#include<stdio.h>
#include<stdlib.h>
typedef int elemtype;
typedef struct dulink
{
	elemtype data;
	//结点的数据域,类型设定为elemtype
	struct dulink  *next, *prior;
	//定义指向直接后继和直接前驱的指针
}dulink, *DLink;
DLink p,q,D;
void creatList(DLink &D, int n)
{
	int x;
	p = (DLink)malloc(sizeof(dulink));
	D = p;
	p->prior = NULL;
	while (n) {
		q = (DLink)malloc(sizeof(dulink));
		printf("input data：");
		scanf("%d", &x);
		q->data = x;
		p->next = q;
		q->prior = p;
		p = q;
		n--;
	}
	q->next = NULL;
	D = D->next;
}
void addList(DLink &D)
{
	DLink ap, cp;
	elemtype e;
	printf("请输入要添加的数据：\n");
	scanf("%d", &e);
	p = (DLink)malloc(sizeof(dulink));
	p->data = e;
	p->next = NULL;
	ap = NULL;
	cp = D;
	while (cp != NULL) {
		if (cp->data > e)
			break;
		ap = cp;
		cp = cp->next;
	}
	if (cp->next == NULL) {
		cp->next = p;
		p->next = NULL;
		p->prior = cp;
	}
	else {
		p->next = cp;
		ap->next = p;
		p->prior = cp->prior;
		cp->prior = p;
	}
}
void deleteList(DLink &D, int i)
{
	int j = 1;
	p = D;
	while (p->next&&j<i){
		p = p->next->prior;
		j++;
	}
	if (!p->next || j > i) {
		printf("被删除的序号值有错");
		exit(1);
	}
	if (p->next->next == NULL) {
		q = p->next;
		p->next = NULL;
		free(q);
	}
	else {
		q = p->next;
		p->next = q->next;
		q->next->prior = p;
		free(q);
	}
}

void display(DLink &D) {
	p = D;
	while (p->next) {
		printf("%d ", p->data);
		p = p->next;
	}
	printf("%d \n", p->data);
}
int main()
{
	creatList(D, 5);
	display(D);
	addList(D);
	display(D);
	deleteList(D,2);
	display(D);
	return 0;
}