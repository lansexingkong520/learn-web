#include<stdio.h>
#include<stdlib.h>
#define LIST_INIT_SIZE 20
#define LISTINCREMENT 10
typedef int elemtpye;
typedef struct List
{
	elemtpye *list;
	int length;
	int listsize;
}List;
List L;
void initList(List &L)
{
	L.list = (elemtpye*)malloc(LIST_INIT_SIZE * sizeof(elemtpye));
	if (!L.list)
		exit(1);
	L.length = 0;
	L.listsize = LIST_INIT_SIZE;
}
void creatList(elemtpye n, List &L)
{
	int j = 0;
	printf("请将数据按升序输入！\n");
	for (int i = 0; i < n; i++) {
		printf("请输入第%d个数。\n", i+1);
		scanf("%d", &L.list[i]);
		j = i;
		while (L.list[j] < L.list[j - 1] && j>0) {
			elemtpye temp = L.list[j];
			L.list[j] = L.list[j - 1];
			L.list[j - 1] = temp;
			j--;
		}
		L.length++;
	}
}

void addList(elemtpye x, List &L)
{
	if (L.length > L.listsize) {
		L.list = (elemtpye*)realloc(L.list, 2 * L.listsize * sizeof(elemtpye));
		L.listsize += LISTINCREMENT;
	}
	int i, j;
	for (i = 0; i < L.length; i++) {
		if (x < L.list[i])
			break;
	}
	for (j = L.length - 1; j >= i; j--) {
		L.list[j + 1] = L.list[j];
	}
	L.list[j+1] = x;
	L.length++;
}
void deleteList(elemtpye x,List &L)
{
	int i, j,temp=0;
	if (L.length > 0) {
		for (i = 0; i < L.length; i++) {
			if (x == L.list[i]) {
				for (j=i; j < L.length; j++) {
					L.list[j] = L.list[j + 1];
				}
				L.length--;
				i = 0;
			}
		}
	}
	else {
		printf("此表为空。\n");
	}
}
void display(List &L)
{
	for (int i = 0; i < L.length; i++) {
		printf("%d  ", L.list[i]);
	}
	printf("\n");
}
//void traverse(List *L)
//{
//	for (int i = 0; i < L->length; i++) {
//		printf("%d  ", L->list[i]);
//	}
//}
int main()
{
	elemtpye x1, x2;
	initList(L);
	creatList(8, L);
	display(L);
	printf("现在插入数据，请输入一个数据：\n");
	scanf("%d", &x1);
	addList(x1, L);
	display(L);
	printf("现在删除数据，请输入一个数据：\n");
	scanf("%d", &x2);
	deleteList(x2, L);
	display(L);
	//traverse(L);
	return 0;
}