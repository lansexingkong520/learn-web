#include<stdio.h>
#include<stdlib.h>
#define maxsize 100
typedef int elemtype;
typedef struct 
{
	int i, j;
	elemtype e;
}Triple;
typedef struct
{
	Triple data[maxsize + 1];
	int mu, nu, tu; //稀疏矩阵行数、列数和非零元素个数
}TSMatrix;

TSMatrix M;

void InitMatrix(TSMatrix &M)
{
	M.mu = 0;
	M.nu = 0;
	M.tu = 0;
}

void CreatMatrix(TSMatrix &M, int m, int n,int k)
{
	M.mu = m;
	M.nu = n;
	M.tu = k;
	int row, col, val;
	for(int i=0;i<k;i++) {
		printf("请输入行、列和值");
		scanf("%d %d %d", &row, &col, &val);
		M.data[i].i = row;
		M.data[i].j = col;
		M.data[i].e = val;
	}
}

void OutMatrix1(TSMatrix &M)
{
	int i;
	for (i = 0; i < M.tu; i++) {
		printf("(%d, %d, %d)\n", M.data[i].i, M.data[i].j, M.data[i].e);
	}
}

void OutMatrix2(TSMatrix &M)
{
	int i, j,k=0;
	for (i = 1; i <= M.mu; i++) {
		for (j = 1; j <= M.nu; j++) {
			if (M.data[k].i == i && M.data[k].j==j) {
				printf("%d ", M.data[k].e);
				k++;
			}
			else {
				printf("0 ");
			}
		}
		printf("\n");
	}
}
int main()
{
	InitMatrix(M);
	int m, n,k;
	printf("请输入一共的行数，列数和非零个数：\n");
	scanf("%d %d %d", &m, &n,&k);
	CreatMatrix(M, m, n,k);
	OutMatrix1(M);
	OutMatrix2(M);
	return 0;
}