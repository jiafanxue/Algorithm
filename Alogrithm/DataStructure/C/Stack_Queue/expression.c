#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Stack.h"

#define CHAR_MAX_LENGTH	100				// 表达式最大长度
#define TRUE 1
#define FALSE 0

// 判断是否是符号
int IsOperator(char ch)
{
	char ops[] = "+-*/";
	int i;
	for (i = 0; i < 4; ++i) {
		if (ch == ops[i]) {
			return TRUE;
		}
	}
	return FALSE;
}

int Precedence(char op)
{
	if (op == '(') {
		return -1;
	}
	else if (op == '*' || op == '/') {
		return 1;
	}
	else if (op == '+' || op == '-') {
		return 0;
	}
}

void InfixToPostfix(char* infix, char* postfix)
{
	Stack mark;			// 符号栈
	InitStack(&mark);
	int infix_length = strlen(infix);
	int i;
	int j = 0;
	for (i = 0; i < infix_length; ++i) {
		if (infix[i] == '(') {
			if (infix[i - 1] >= '0' && infix[i - 1] <= '9') {
				postfix[j++] = '#';
				Push(&mark, '*');
			}
			Push(&mark, infix[i]);
		}
		else if (infix[i] == ')') {
			if (infix[i - 1] != ')') {
				postfix[j++] = '#';
			}
			while (GetTop(mark) != '(') {
				postfix[j++] = GetTop(mark);
				Pop(&mark);
			}
			Pop(&mark);
		}
		else if (!IsOperator(infix[i])) {
			postfix[j++] = infix[i];
		}
		else {
			if (infix[i - 1] != ')') {
				postfix[j++] = '#';
			}
			if (!StackEmpty(mark)) {
				while (GetTop(mark) != '(' && Precedence(infix[i]) <= Precedence(GetTop(mark))) {
					postfix[j++] = GetTop(mark);
					Pop(&mark);
					if (StackEmpty(mark)) {
						break;
					}
				}
			}
			Push(&mark, infix[i]);
		}
	}

	if (infix[infix_length - 1] != ')') {
		postfix[j++] = '#';
	}

	while (!StackEmpty(mark)) {
		char ch = GetTop(mark);
		postfix[j++] = ch;
		Pop(&mark);
	}
	DestroyStack(&mark);
	postfix[j] = 0;
}

int postfixComput(char* postfix)
{
	int postfix_length = strlen(postfix);
	int i;
	Stack tempResult;
	InitStack(&tempResult);
	char strNum[10];
	int currNum = 0;
	int tempNum = 0;
	int j = 0;
	for (i = 0; i < postfix_length; ++i) {
		switch (postfix[i]) {
		case '0':
		case '1':
		case '2':
		case '3':
		case '4':
		case '5':
		case '6':
		case '7':
		case '8':
		case '9':
			strNum[j++] = postfix[i];
			break;
		case '+':
			tempNum = (GetTop(tempResult) - '0');
			Pop(&tempResult);
			tempNum += (GetTop(tempResult) - '0');
			Pop(&tempResult);
			Push(&tempResult, tempNum + '0');
			break;
		case '-':
			tempNum = (GetTop(tempResult) - '0');
			Pop(&tempResult);
			tempNum = (GetTop(tempResult) - '0') - tempNum;
			Pop(&tempResult);
			Push(&tempResult, tempNum + '0');
			break;
		case '*':
			tempNum = (GetTop(tempResult) - '0');
			Pop(&tempResult);
			tempNum *= (GetTop(tempResult) - '0');
			Pop(&tempResult);
			Push(&tempResult, tempNum + '0');
			break;
		case '/':
			tempNum = (GetTop(tempResult) - '0');
			Pop(&tempResult);
			tempNum = (GetTop(tempResult) - '0') / tempNum;
			Pop(&tempResult);
			Push(&tempResult, tempNum + '0');
			break;
		case '#':
			strNum[j] = 0;
			currNum = atof(strNum);
			memset(strNum, 0, sizeof(strNum));
			j = 0;
			Push(&tempResult, (unsigned char)(currNum + '0'));
			break;
		}
	}
	return (GetTop(tempResult) - '0');
}

void Calculate(char* infix)
{
	char postfix[100];
	InfixToPostfix(infix, postfix);
	printf("%s = %d\n", infix, postfixComput(postfix));
}

int main(int argc, char const * argv[])
{
	char infix[CHAR_MAX_LENGTH];
	while (1) {
		printf("Please enter a expression: ");
		scanf("%s", infix);
		Calculate(infix);
	}
	return 0;
}