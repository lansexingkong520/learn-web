#include<stdio.h>
#include<stdlib.h>
typedef int elemtype;
typedef struct link 
{
	elemtype data;
	link *next;
}link;
typedef struct linkqueue
{
	link *font, *rear;
}linkqueue;

linkqueue q;
void Initqueue(linkqueue &q)
{
	q.font = NULL;
	q.rear = NULL;
}
void Inqueue(linkqueue &q, elemtype x)
{
	link *p;
	p = (link*)malloc(sizeof(link));
	p->data = x;
	p->next = NULL;
	if (q.rear == NULL) {
		q.font = q.rear = p;    //当链队为空
	}
	else
	{
		q.rear->next = p;
		q.rear = p;
	}	
}
elemtype Outqueue(linkqueue &q)
{
	link *p;
	if (q.font == NULL) {
		return 0;
	}
	elemtype temp = q.font->data;
	p = q.font;
	q.font = p->next;
	if (q.font == NULL) {
		q.rear = NULL;
	}
	free(p);
	return temp;
}
int empty(linkqueue &q)
{
	if (q.font == NULL)
		return 1;
	else
		return 0;
}
int main()
{

	Initqueue(q);
	int num, temp;
	printf("请输入要入队的个数：\n");
	scanf("%d", &num);
	for (int i = 0; i < num; i++) {
		scanf("%d", &temp);
		Inqueue(q, temp);
	}
	int a = Outqueue(q);
	printf("第一个出队的数：\n");
	printf("%d", a);
	return 0;
}