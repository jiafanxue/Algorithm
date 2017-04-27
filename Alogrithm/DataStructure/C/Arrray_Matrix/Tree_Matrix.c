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
#include <string.h>
// 辅助宏定义
#define Print_Status(x) printf(x + '\n')
#define IS_NOT_NULL(ptr) ((ptr))
#define IS_NULL(ptr) (!(ptr))
// 栈的顺序存储表示
#define FALSE 0
#define TRUE 1
// 稀疏矩阵三原数组顺序存储表示
#define MAXSIZE 12500				// 假设非零元素个数的最大值为12500
#define MAXRC 10
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
	SIZEERROR						// 大小错误
} Status;

Status CreateSMatrix(TSMatrix* M);						// 创建一个稀疏矩阵
Status DestroySMatrix(TSMatrix* M);						// 摧毁一个稀疏矩阵
void PrintSMatrix(TSMatrix M); 							// 输出一个稀疏矩阵
Status CopySMatrix(TSMatrix M, TSMatrix* T);			// 由稀疏矩阵M复制得到T
Status AddSMatrix(TSMatrix M, TSMatrix N, TSMatrix* Q);	// 两个稀疏矩阵相加
Status SubtSMatrix(TSMatrix M, TSMatrix N, TSMatrix* Q);// 两个稀疏矩阵相减
Status MultSMatrix(TSMatrix M, TSMatrix N, TSMatrix* Q);// 两个稀疏矩阵相乘
Status TransposeSMatrix(TSMatrix M, TSMatrix* T);		// 稀疏矩阵的转置

void child_memuBar()
{
	printf("    	   	  This is a Matrix \n");
	printf("==========================================================\n");
	printf("	1) CreateSMatrix	2) DestroySMatrix\n");
	printf("	3) PrintSMatrix		4) AddSMatrix\n");
	printf("	5) SubtSMatrix		6) MultSMatrix\n");
	printf("	7) TransposeSMatrix\n");
	printf("	q) Quit(q to quit)\n");
	printf("==========================================================\n");
}

int main(int argc, char const *argv[])
{
	child_memuBar();

	TSMatrix* m = (TSMatrix*)malloc(sizeof(TSMatrix));

	int selectNum;
	printf("You Select : ");
	while (scanf("%d", &selectNum)) {
		switch (selectNum) {
		case 1: {
			CreateSMatrix(m);
		}
		break;

		case 2: {
			if (m != NULL) {
				DestroySMatrix(m);
			}
		}
		break;

		case 3: {
			PrintSMatrix(*m);
		}
		break;

		case 4: {
			TSMatrix* n = (TSMatrix*)malloc(sizeof(TSMatrix));
			TSMatrix* t = (TSMatrix*)malloc(sizeof(TSMatrix));
			CreateSMatrix(n);
			if (AddSMatrix(*m, *n, t)) {
				PrintSMatrix(*t);
			}
			else {
				printf("Error!\n");
			}
			printf("\n");
		}
		break;

		case 5: {
			TSMatrix* n = (TSMatrix*)malloc(sizeof(TSMatrix));
			TSMatrix* t = (TSMatrix*)malloc(sizeof(TSMatrix));
			CreateSMatrix(n);
			if (SubtSMatrix(*m, *n, t)) {
				PrintSMatrix(*t);
			}
			else {
				printf("Error!\n");
			}
			printf("\n");
		}
		break;

		case 6: {
			TSMatrix* n = (TSMatrix*)malloc(sizeof(TSMatrix));
			TSMatrix* t = (TSMatrix*)malloc(sizeof(TSMatrix));
			CreateSMatrix(n);
			if (MultSMatrix(*m, *n, t)) {
				PrintSMatrix(*t);
			}
			else {
				printf("Error!\n");
			}
			printf("\n");
		}
		break;

		case 7: {
			TSMatrix* t = (TSMatrix*)malloc(sizeof(TSMatrix));
			if (TransposeSMatrix(*m, t)) {
				PrintSMatrix(*t);
			}
			else {
				printf("Error!\n");
			}
			printf("\n");
		}
		break;

		default:
			break;
		}
		printf("\n\n");
		child_memuBar();
		printf("You Select : ");
		fflush(stdin);
	}

	return 0;
}

// 创建一个稀疏矩阵
Status CreateSMatrix(TSMatrix* M)
{
	int select;
	printf("Whether the file is entered? 1 or 0\n");
	scanf("%d", &select);
	if (select) {
		printf("Please enter the filename: ");
		char filename[20];
		char suffix[5] = ".txt";
		scanf("%s", filename);
		strcpy(filename + strlen(filename), suffix);
		FILE* fp = fopen(filename, "r");
		if (!fp) {
			perror("File opening failed");
			return EXIT_FAILURE;
		}

		int k = 1;
		int begin = 0;
		char StrLine[10];
		while ((fgets(StrLine, 10, fp)) != NULL) {
			if (begin == 0) {
				M->mu = StrLine[0] - '0';
				M->nu = StrLine[2] - '0';
				M->tu = StrLine[4] - '0';
				begin++;
			}
			else {
				M->data[k].i = StrLine[0] - '0';
				M->data[k].j = StrLine[2] - '0';
				M->data[k].e = StrLine[4] - '0';
				k++;
			}
		}
		fclose(fp);
		// printf("%d %d %d\n", M->mu, M->nu, M->tu);
	}
	else {
		int mu, nu, tu;
		printf("Please enter the mu and nu and tu: ");
		scanf("%d %d %d", &mu, &nu, &tu);
		M->mu = mu, M->nu = nu, M->tu = tu;
		for (int k = 1; k <= M->tu; ++k) {
			printf("Please enter i, j index and data: ");
			if (scanf("%d %d %d", &(M->data[k]).i, &(M->data[k]).j, &(M->data[k]).e) == 3) {
				;
			}
			else {
				k--;
			}
		}
	}
	return OK;
}

// 摧毁一个稀疏矩阵
Status DestroySMatrix(TSMatrix* M)
{
	M = NULL;
	return OK;
}

// 输出一个稀疏矩阵
void PrintSMatrix(TSMatrix M)
{
	for (int i = 0; i < M.mu; ++i) {
		for (int j = 0; j < M.nu; ++j) {
			int boolen = FALSE;
			for (int k = 1; k <= M.tu; ++k) {
				if (M.data[k].i - 1 == i && M.data[k].j - 1 == j) {
					printf("%d ", M.data[k].e);
					boolen = TRUE;
					break;
				}
				else {
					continue;
				}
			}
			if (!boolen) {
				printf("0 ");
			}
		}
		printf("\n");
	}
}

// 由稀疏矩阵M复制得到T
Status CopySMatrix(TSMatrix M, TSMatrix* T)
{
	if (T == NULL) {
		return ERROR;
	}

	T->mu = M.mu;
	T->nu = M.nu;
	T->tu = M.tu;

	for (int i = 1; i <= T->tu; ++i) {
		T->data[i].i = M.data[i].i;
		T->data[i].j = M.data[i].j;
		T->data[i].e = M.data[i].e;
	}

	return OK;
}

// 两个稀疏矩阵相加
Status AddSMatrix(TSMatrix M, TSMatrix N, TSMatrix* Q)
{
	if (Q == NULL) {
		return ERROR;
	}

	if (M.mu != N.mu && M.nu != N.nu) {
		return ERROR;
	}

	Q->mu = M.mu;
	Q->nu = M.nu;
	Q->tu = 0;

	int tu_num = 0;
	for (int i = 0; i < M.mu; ++i) {
		for (int j = 0; j < M.nu; ++j) {
			int M_n = 0;
			int N_n = 0;
			for (int k = 1; k <= M.tu; ++k) {
				if (M.data[k].i - 1 == i && M.data[k].j - 1 == j) {
					M_n = M.data[k].e;
					break;
				}
				else {
					continue;
				}
			}

			for (int k = 1; k <= N.tu; ++k) {
				if (N.data[k].i - 1 == i && N.data[k].j - 1 == j) {
					N_n = N.data[k].e;
					break;
				}
				else {
					continue;
				}
			}

			int Q_n = M_n + N_n;
			if (Q_n != 0) {
				Q->data[tu_num + 1].i = i + 1;
				Q->data[tu_num + 1].j = j + 1;
				Q->data[tu_num + 1].e = Q_n;
				++tu_num;
			}
		}
	}
	Q->tu = tu_num;
	return OK;
}

// 两个稀疏矩阵相减
Status SubtSMatrix(TSMatrix M, TSMatrix N, TSMatrix* Q)
{
	if (Q == NULL) {
		return ERROR;
	}

	if (M.mu != N.mu && M.nu != N.nu) {
		return ERROR;
	}

	Q->mu = M.mu;
	Q->nu = M.nu;
	Q->tu = 0;

	int tu_num = 0;
	for (int i = 0; i < M.mu; ++i) {
		for (int j = 0; j < M.nu; ++j) {
			int M_n = 0;
			int N_n = 0;
			for (int k = 1; k <= M.tu; ++k) {
				if (M.data[k].i - 1 == i && M.data[k].j - 1 == j) {
					M_n = M.data[k].e;
					break;
				}
				else {
					continue;
				}
			}

			for (int k = 1; k <= N.tu; ++k) {
				if (N.data[k].i - 1 == i && N.data[k].j - 1 == j) {
					N_n = N.data[k].e;
					break;
				}
				else {
					continue;
				}
			}

			int Q_n = M_n - N_n;
			if (Q_n != 0) {
				Q->data[tu_num + 1].i = i + 1;
				Q->data[tu_num + 1].j = j + 1;
				Q->data[tu_num + 1].e = Q_n;
				++tu_num;
			}
		}
	}
	Q->tu = tu_num;
	return OK;
}

// 两个稀疏矩阵相乘
Status MultSMatrix(TSMatrix M, TSMatrix N, TSMatrix* Q)
{
	if (Q == NULL) {
		return ERROR;
	}

	if (M.mu != N.nu && M.nu != N.mu) {
		return ERROR;
	}

	Q->mu = M.mu;
	Q->nu = N.nu;
	Q->tu = 0;

	Elemtype M_tmp[M.mu][M.nu];
	Elemtype N_tmp[N.mu][N.nu];
	for (int i = 0; i < M.mu; ++i) {
		for (int j = 0; j < M.nu; ++j) {
			M_tmp[i][j] = 0;
		}
	}

	if (M.tu) {
		for (int k = 1; k <= M.tu; ++k) {
			M_tmp[M.data[k].i - 1][M.data[k].j - 1] = M.data[k].e;
		}
	}

	for (int i = 0; i < N.mu; ++i) {
		for (int j = 0; j < N.nu; ++j) {
			N_tmp[i][j] = 0;
		}
	}

	if (N.tu) {
		for (int k = 1; k <= N.tu; ++k) {
			N_tmp[N.data[k].i - 1][N.data[k].j - 1] = N.data[k].e;
		}
	}

	int k = 1;
	for (int i = 0; i < Q->mu; ++i) {
		for (int j = 0; j < Q->nu; ++j) {
			int c = 0;
			for (int q = 0; q < M.nu; ++q) {
				c += M_tmp[i][q] * N_tmp[q][j];
			}
			if (c != 0) {
				Q->data[k + 1].i = i + 1;
				Q->data[k + 1].j = j + 1;
				Q->data[k + 1].e = c;
				++k;
			}
		}
	}
	Q->tu = k;

	return OK;
}

// 稀疏矩阵的转置
Status TransposeSMatrix(TSMatrix M, TSMatrix* T)
{
	if (T == NULL) {
		return ERROR;
	}

	T->mu = M.nu;
	T->nu = M.mu;
	T->tu = M.tu;

	if (T->tu) {
		int q = 1;
		for (int col = 1; col <= M.nu; ++col) {
			for (int p = 1; p <= M.tu; ++p) {
				if (M.data[p].j == col) {
					T->data[q].i = M.data[p].j;
					T->data[q].j = M.data[p].i;
					T->data[q].e = M.data[p].e;
					++q;
				}
			}
		}
	}
	return OK;
}