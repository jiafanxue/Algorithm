/*
	Author: Xefvan

	实现串（堆分配存储表示）
	
	基本操作：
		Status StrAssign()			: 生成一个其值等于串常量chars的串T
		int StrLength()				: 返回S的元素个数，称为串的长度
		int StrCompare()			: 若S>T，则返回值>0，若S=T，则返回值=0；若S<T,则返回值<0
		Status ClearString()		: 将S清除为空串，并释放S所占空间
		HString SubString()			: 返回串S的第pos个字符起长度为len的子串
*/

#include <stdio.h>
#include <stdlib.h>
#define Print_State(x) printf(x)
#define OVERFLOW 		0		// 分配内存失败
#define OUTOFINDEX 		0		// 下标越界
#define LIST_INIT_SIZE 	100		// 顺序存储的初始化大小为100
#define ElemType 		int
#define TRUE 			1
#define FALSE 			0

// 参数操作基本返回状态
typedef enum Status {
	ERROR,						// 错误
	OK,							// 正确
	INSERTERROR,				// 插入失败
	DELETEERROR					// 删除失败
} Status;

// 穿的对分配存储表示
typedef struct 
{
	char* ch;
	int length;
}HString;


int main(int argc, char const *argv[])
{
	
	return 0;
}


