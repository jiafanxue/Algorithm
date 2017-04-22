/*
	三元矩阵（顺序存储）

	基本操作：
		CreateSMatrix()				: 创建稀疏矩阵
		DestroySMatrix()			: 摧毁稀疏矩阵
		PrintSMatrix()				: 输出稀疏矩阵
		CopySMatrix()				: 由稀疏矩阵M复制得到T
		AddSMatrix()				: 两个稀疏矩阵相加
		SubtSMatrix()				: 两个稀疏矩阵相减
		MultSMatrix()				: 两个稀疏矩阵相乘
		TransposeSMatrix()			: 稀疏矩阵的转置
*/

#include <stdio.h>
#include <stdlib.h>
// 辅助宏定义
#define Print_Status(x) printf(x + '\n')
#define IS_NOT_NULL(ptr) ((ptr))
#define IS_NULL(ptr) (!(ptr))
// 栈的顺序存储表示
#define FALSE 0
#define TRUE 1
// 稀疏矩阵三原数组顺序存储表示
#define MAXSIZE 12500				// 假设非零元素个数的最大值为12500
#define Elemtype int 				// 元素类型为整形

typedef struct Triple
{
	int i, j;						// 该非零元的行下标和列下标
	Elemtype e;
} Triple;

typedef struct TSMatrix
{
	Triple data[MAXSIZE + 1];		// 非零三元组表，data[0]未用
	int mu, nu, tu;					// 矩阵行数，列数和非零元个数
} TSMatrix;

typedef enum Status
{
	ERROR,							// 错误
	OK,								// 正确
	INSERTERROR,					// 插入错误
	DELETEERROR						// 删除错误
} Status;

Status CreateSMatrix(TSMatrix* M);			// 创建一个稀疏矩阵
Status DestroySMatrix(TSMatrix* M);			// 摧毁一个稀疏矩阵
void PrintSMatrix(TSMatrix M); 				// 输出一个稀疏矩阵


int main(int argc, char const *argv[])
{
	TSMatrix* m = (TSMatrix*)malloc(sizeof(TSMatrix));
	CreateSMatrix(m);
	return 0;
}

// 创建一个稀疏矩阵
Status CreateSMatrix(TSMatrix* M)
{
	int mu, nu, tu;
	printf("Please enter the mu and nu and tu: ");
	scanf("%d %d %d", &mu, &nu, &tu);
	M->mu = mu, M->nu = nu, M->tu = tu;

	int num;
	printf("How much elements do you want to insert?\n");
	scanf("%d", &num);

	for (int k = 0; k < num; ++k) {
		scanf("%d", (M->data[k]).i);
	}

	return OK;
}

// 输出一个稀疏矩阵
void PrintSMatrix(TSMatrix M)
{

}