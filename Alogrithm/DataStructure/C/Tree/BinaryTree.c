/*
Binary Tree:
CreateBiTree()					: 	创建二叉树
BiTreeDepth()					: 	返回二叉树的深度
CountLeaves()					:   计算叶子节点的数目
Calculate()						:	计算结果
PreOrderTraverse()				: 	前序遍历
InOrderTraverse()				:	中序遍历
PostOrderTraverse()				: 	后序遍历
LevelOrderTraverse()			:	层序遍历
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
// #define DEBUG					// 测试代码
#define TRUE 1
#define FALSE 0
#define Maxsize 100
#define Type int

// 数据存储类型
typedef union
{
	char Operator;
	double data;
} ElemType;

// 二叉树的数据结构
typedef struct node
{
	Type t;
	ElemType elem;
	struct node* lchild;
	struct node* rchild;
} BiNode;

typedef struct
{
	char operation;
	int index;
	int locate;
} Op;

static int index = 0;
Op arrayOp[Maxsize];

int isop(char op);
int sorTop(char str[], Op arrayOp[], int* index);
double strToFloat(char* str, int strBegin, int strEnd);
int isdata(char* str, int strBegin, int strEnd);
int isOperator(char* str, int strBegin, int strEnd);
void CreateBiTree(BiNode* bt, char* str, int strBegin, int strEnd, int tail);
int BiTreeDepth(BiNode* bt);
int CountLeaves(BiNode* bt);
double Calculate(BiNode* b);
void PreOrderTraverse(BiNode* bt);
void InOrderTraverse(BiNode* bt);
void PostOrderTraverse(BiNode* bt);
void print(BiNode* bt);

void child_memuBar()
{
	printf("    	   	  This is a Tree \n");
	printf("==========================================================\n");
	printf("	1) CreateSTree		2) PreOrderTraverse\n");
	printf("	3) InOrderTraverse	4) PostOrderTraverse\n");
	printf("	5) BiTreeDepth		6) CountLeaves\n");
	printf("	7) Calculate\n");
	printf("	q) Quit(q to quit)\n");
	printf("==========================================================\n");
}

int main(int argc, char const *argv[])
{
	BiNode* bt = (BiNode*)malloc(sizeof(BiNode));

#ifdef DEBUG
	char str[Maxsize];
	while (1) {
		printf("Please enter a str(q to quit): ");
		scanf("%s", str);
		fflush(stdin);
		if (strcmp("q", str) == 0) {
			break;
		}
		else {
			int tail = sorTop(str, arrayOp, &index);
			printf("%d\n", tail);
			CreateBiTree(bt, str, 0, strlen(str) - 1, tail);
			InOrderTraverse(bt);
			printf("\n");
			double result = Calculate(bt);
			printf("The result : %.3f\n", result);
		}
	}
#endif

	child_memuBar();

	int selectNum;
	printf("You Select : ");
	while (scanf("%d", &selectNum)) {
		switch (selectNum) {
		case 1: {
			char str[Maxsize];
			printf("Please enter a expression: ");
			scanf("%s", str);
			fflush(stdin);
			int tail = sorTop(str, arrayOp, &index);
			CreateBiTree(bt, str, 0, strlen(str) - 1, tail);
			printf("Ok!\n");
		}
		break;

		case 2: {
			printf("PreOrderTraverse: ");
			PreOrderTraverse(bt);
			printf("\n");
		}
		break;

		case 3: {
			printf("InOrderTraverse: ");
			InOrderTraverse(bt);
			printf("\n");
		}
		break;

		case 4: {
			printf("PostOrderTraverse: ");
			PostOrderTraverse(bt);
			printf("\n");
		}
		break;

		case 5: {
			printf("The depth of the tree is: %d\n", BiTreeDepth(bt));
		}
		break;

		case 6: {
			printf("The mumber of the tree's leaves is: %d\n", CountLeaves(bt));
		}
		break;

		case 7: {
			printf("The result is: %.2f\n", Calculate(bt));
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

int sorTop(char str[], Op arrayOp[], int* index)
{
	int j = 0;
	int i;
	int ind = 0;
	for (i = 0; str[i] != '\0'; ++i) {
		if (str[i] == '(') {
			ind++;
		}
		else if (str[i] == ')') {
			ind--;
		}
		else if (isop(str[i])) {
			arrayOp[j].operation = str[i];
			arrayOp[j].index = ind;
			arrayOp[j].locate = i;
			j++;
		}

		if (*index <= ind) {
			*index = ind;
		}
	}
	return j;
}

double strToFloat(char* str, int strBegin, int strEnd)
{
	if (str[strBegin] == '(') {
		strBegin++;
	}
	if (str[strEnd] == ')') {
		strEnd--;
	}

	// 计算小数点前有几位
	int index = 0;
	int temp = strBegin;
	double result = 0;
	for (; strBegin <= strEnd && str[strBegin] != '.'; ++strBegin) {
		index++;
	}

	// 归位
	strBegin = temp;
	for (; strBegin <= strEnd; ++strBegin) {
		if (str[strBegin] == '.') {
			continue;
		}
		index--;
		result = result + ((double)(str[strBegin] - '0')) * (pow(10.0, index));
	}

	return result;
}

int isop(char op)
{
	if (op == '+' || op == '-' || op == '*' || op == '/') {
		return TRUE;
	}
	return FALSE;
}

int isdata(char* str, int strBegin, int strEnd)
{
	int i;
	int index = 0;
	for (i = strBegin; i <= strEnd; ++i) {
		if (str[i] == '.') {
			index++;
		}
		if (isop(str[i])) {
			return FALSE;
		}
	}

	if (index == 0 || index == 1) {
		return TRUE;
	}
}

int isOperator(char* str, int strBegin, int strEnd)
{
	if ((strBegin == strEnd) && (str[strBegin] == '(' || str[strBegin] == ')' || isop(str[strBegin]))) {
		return TRUE;
	}
	else {
		return FALSE;
	}
}

void CreateBiTree(BiNode* bt, char* str, int strBegin, int strEnd, int tail)
{
	int i = 0;
	int j = 0;
	int find = 0;
	if (isdata(str, strBegin, strEnd)) {
		bt->t = 0;
		bt->elem.data = strToFloat(str, strBegin, strEnd);
		bt->lchild = NULL;
		bt->rchild = NULL;
	}
	else if (isOperator(str, strBegin, strEnd)) {
		bt->t = 1;
		bt->elem.Operator = str[i];
		bt->lchild = NULL;
		bt->rchild = NULL;
	}
	else {
		int temp;
		for (temp = 0; temp <= index; ++temp) {
			for (j = tail; j >= 0; j--)//从后往前找，才符合运算的法则，前面先算后面后算
			{
				if (arrayOp[j].index == temp && ((arrayOp[j].operation == '+') || (arrayOp[j].operation == '-')) && arrayOp[j].locate >= strBegin && arrayOp[j].locate <= strEnd)
				{
					find++;
					arrayOp[j].index = -1;//标志这个已经被找过了
					BiNode* lt = (BiNode*)malloc(sizeof(BiNode));
					BiNode* rt = (BiNode*)malloc(sizeof(BiNode));
					bt->lchild = lt;
					bt->rchild = rt;
					bt->elem.Operator = arrayOp[j].operation;
					bt->t = 1;
					CreateBiTree(bt->lchild, str, strBegin, arrayOp[j].locate - 1, tail);
					CreateBiTree(bt->rchild, str, arrayOp[j].locate + 1, strEnd, tail);
				}
			}

			if (find == 0) {
				for (j = tail; j >= 0; j--)
				{
					if (arrayOp[j].index == temp && ((arrayOp[j].operation == '*') || (arrayOp[j].operation == '/')) && arrayOp[j].locate >= strBegin && arrayOp[j].locate <= strEnd)
					{
						find++;
						arrayOp[j].index = -1;//标志这个已经被找过了
						BiNode* lt = (BiNode*)malloc(sizeof(BiNode));
						BiNode* rt = (BiNode*)malloc(sizeof(BiNode));
						bt->lchild = lt;
						bt->rchild = rt;
						bt->elem.Operator = arrayOp[j].operation;
						bt->t = 1;
						CreateBiTree(bt->lchild, str, strBegin, arrayOp[j].locate - 1, tail);
						CreateBiTree(bt->rchild, str, arrayOp[j].locate + 1, strEnd, tail);
					}
				}
			}
		}
	}
}

double Calculate(BiNode* bt)
{
	double left, right;

	if (bt == NULL) {
		return 0;
	}

	if (bt->lchild == NULL && bt->rchild == NULL) {
		return bt->elem.data;
	}

	left = Calculate(bt->lchild);
	right = Calculate(bt->rchild);
	double result;
	switch (bt->elem.Operator) {
	case '+':
		result = left + right;
		break;
	case '-':
		result = left - right;
		break;
	case '*':
		result = left * right;
		break;
	case '/':
		if (right != 0) {
			result = left / right;
		}
		else {
			exit(1);
		}
		break;
	}
	return result;
}

int BiTreeDepth(BiNode* bt)
{
	if (bt == NULL) {
		return 0;
	}

	int lh = BiTreeDepth(bt->lchild);
	int rh = BiTreeDepth(bt->rchild);

	if (lh > rh) {
		return ++lh;
	}
	else {
		return ++rh;
	}
}

int CountLeaves(BiNode* bt)
{

	static int count = 0;
	if (bt != NULL) {
		count = CountLeaves(bt->lchild);
		if (bt->lchild == NULL && bt->rchild == NULL) {
			count += 1;
		}
		count = CountLeaves(bt->rchild);
	}

	return count;
}

void PreOrderTraverse(BiNode* bt)
{
	if (bt != NULL) {
		print(bt);
		PreOrderTraverse(bt->lchild);
		PreOrderTraverse(bt->rchild);
	}
}

void InOrderTraverse(BiNode* bt)
{
	if (bt != NULL) {
		InOrderTraverse(bt->lchild);
		print(bt);
		InOrderTraverse(bt->rchild);
	}
}

void PostOrderTraverse(BiNode* bt)
{
	if (bt != NULL) {
		PostOrderTraverse(bt->lchild);
		PostOrderTraverse(bt->rchild);
		print(bt);
	}
}

void print(BiNode* bt)
{
	if (bt->t == 1) {
		printf("%c ", bt->elem.Operator);
	}
	else {
		printf("%.1f ", bt->elem.data);
	}
}