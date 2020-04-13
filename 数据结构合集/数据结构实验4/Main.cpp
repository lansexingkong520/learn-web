#include<stdio.h>
#include<stdlib.h>
#define STACKINITSIZE 100 
#define STACKINCREMENT  10 
typedef int elemtype;
typedef struct sqstcak
{
	elemtype *base;
	elemtype *top;
	int stacksize;
}SqStack;

SqStack s;
elemtype x;

int InitStack(SqStack &s)
{
	s.base = (elemtype *)malloc(STACKINITSIZE * sizeof(elemtype));
	if (!s.base) {
		exit(0);
	}
	s.top = s.base;
	s.stacksize = STACKINITSIZE;
	return 1;
}
int push(SqStack &s, elemtype x)
{
	if (s.top - s.base >= s.stacksize) {
		s.base = (elemtype*)realloc(s.base, (s.stacksize + STACKINCREMENT) * sizeof(elemtype));
		if (!s.base) {
			exit(0);
		}
		s.top = s.base + s.stacksize;
		s.stacksize += STACKINCREMENT;
	}
	*s.top = x;
	s.top++; //*(s.top++)�������ټ�һ�������������ջ������+1
	return 1;
}
int pop(SqStack &s, elemtype x)
{
	if (s.top == s.base) {
		return 0;
	}
	x = *--s.top;
	return x;
}
int main()
{

	int num;
	InitStack(s);
	printf("������Ҫ��������ݸ�����");
	scanf("%d", &num);
	for (int i = 0; i < num; i++) {
		printf("��%d������\n", i+1);
		scanf("%d", &x);
		push(s, x);
	}
	for (int i = num; i > 0; i--) {
		elemtype temp = pop(s, x);
		printf("��%d��������%d\n", i, temp);
	}
	return 0;
}



