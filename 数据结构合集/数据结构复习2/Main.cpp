#include<stdio.h>
#include<stdlib.h>
#define MAXQSIZE 20
typedef int elemtype;
typedef struct link
{
	elemtype *base;
	int front;
	int rear;
}link;
link q;
void creatLink(link &q)
{
	q.base = (elemtype*)malloc(sizeof(elemtype)*MAXQSIZE);
	if (!q.base) {
		exit(0);
	}
	q.rear = q.front = 0;
}
void inLink(link &q,elemtype e)
{
	q.base[q.rear] = e;
	q.rear += 1;
}

int LinkLength(link &q)
{
	return (q.rear - q.front + MAXQSIZE) % MAXQSIZE;
}
