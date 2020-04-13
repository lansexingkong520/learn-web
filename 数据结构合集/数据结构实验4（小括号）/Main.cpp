#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAXSIZE 20
typedef struct {
	char data[MAXSIZE];
	int top;
}SeqStack;

SeqStack *s;

void initSeqStack(SeqStack *&s)
{
	s = (SeqStack*)malloc(sizeof(SeqStack));
	s->top = -1;
}
void pushSeqStack(SeqStack &s, char x)
{
	if (s.top == MAXSIZE - 1)
		printf("the stack is full!\n");
	else {
		s.top++;
		s.data[s.top] = x;
	}
}
char getSeqStack(SeqStack &s)
{
	char x;
	if (s.top == -1) {
		printf("the stack is empty!\n");
		return '-1';
	}
	else {
		x = s.data[s.top];
		return x;
	}
}
void popSeqStack(SeqStack &s)
{
	char x;
	if (s.top == -1)
		printf("the stack is empty!\n");
	else {
		x = s.data[s.top];
		s.top--;
	}
}
void correct(char array[])
{
	initSeqStack(s);
	char x;
	int i = 0;
	while (array[i]!='\0'){
		if (array[i] == '(') {
			pushSeqStack(*s, array[i]);
			i++;
		}
		else if (array[i] == ')') {
			x = getSeqStack(*s);
			if (array[i] == ')'&&x == '(') {
				popSeqStack(*s);
				i++;
			}
			else
				break;
		}
		else
		{
			i++;
		}
	}
	if (s->top != -1)
		printf("��ƥ��!\n");
	else
		printf("ƥ��!\n");
}
int main()
{
	char array[20];
	printf("��������ʽ���ʽ������������Ӣ�ķ���!\n");
	gets_s(array);
	correct(array);
	return 0;
}