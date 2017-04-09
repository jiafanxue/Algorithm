/*
	栈和队列

	操作：
		Status InitStack		:	构造一个栈
		Status DestroyStack		:	摧毁一个栈
		Status ClearStack		: 	清空一个栈
		Status StackEmpty		: 	判断一个栈是否为空
		int StackLength			:	返回栈中元素的个数
		Status GetTop			:	返回栈顶元素
		Status Push				: 	插入元素e为新的栈顶元素
		Status Pop				: 	删除栈顶元素
		void StackTraverse	: 	遍历栈中的元素
*/
#include <stdio.h>
#include <stdlib.h>

#ifndef STACK_TYPE
#define STACK_TYPE

// 辅助宏定义
#define Print_Status(x) printf(x + '\n')
#define IS_NOT_NULL(ptr) ((ptr))
#define IS_NULL(ptr) (!(ptr))
// 栈的顺序存储表示
#define STACK_INIT_SIZE 100		// 存储空间初始分配量
#define STACKINCREMENT 10		// 存储空间分配增量
#define SElemType unsigned char 			// 定义一个元素的类型
#define FALSE 0
#define TRUE 1

#endif // STACK_TYPE

typedef enum Status
{
	ERROR,						// 错误
	OK,							// 正确
	INSERTERROR,				// 插入错误
	DELETEERROR					// 删除错误
} Status;

typedef struct
{
	SElemType* elem;			// 元素存储
	int top;					// 栈顶位置
	int length;					// 实际长度
	int lengthSize;				// 存储的最大长度
} Stack;


Status InitStack(Stack* s);				// 构造一个栈
Status DestroyStack(Stack* s);			// 摧毁一个栈
Status ClearStack(Stack* s);			// 清空一个栈
int StackEmpty(Stack s);				// 判断一个栈是否为空
int StackLength(Stack s);				// 返回栈的长度
SElemType GetTop(Stack s);				// 返回栈顶元素 
Status Push(Stack* s, SElemType e);		// 在栈顶插入元素
Status Pop(Stack* s);					// 删除栈顶元素
void StackTraverse(Stack s);			// 遍历栈元素


// 构造一个栈
Status InitStack(Stack* s)
{
	s->elem = (SElemType*)malloc( STACK_INIT_SIZE * sizeof(SElemType));
	if (IS_NULL(s->elem)) {
		Print_Status("Out Of Memory!");
		return ERROR;
	}
	s->top = 0;
	s->length = 0;
	s->lengthSize = STACK_INIT_SIZE;
	return OK;
}

// 摧毁一个栈
Status DestroyStack(Stack* s)
{
	if (IS_NOT_NULL(s->elem)) {
		free(s->elem);
		s->top = 0;
		s->length = 0;
		s->lengthSize = 0;
	}
	return OK;
}

// 清空一个线性表
Status ClearStack(Stack* s)
{
	s->top = 0;
	s->length = 0;
	return OK;
}

// 判断栈是否为空
int StackEmpty(Stack s)
{
	if(StackLength(s) == 0) {
		return TRUE;
	}
	return FALSE;
}

// 返回栈的长度
int StackLength(Stack s)
{
	return s.length;
}

// 返回栈顶元素
SElemType GetTop(Stack s)
{
	if(StackEmpty(s)) {
		return ' ';
	}
	return s.elem[s.top - 1];
}

// 在栈顶插入一个元素
Status Push(Stack* s, SElemType e)
{
	if(s->length > s->lengthSize) {
		return INSERTERROR;
	}
	s->elem[s->top++] = e;
	(s->length)++;
	return OK; 
}

// 在栈尾删除元素
Status Pop(Stack* s)
{
	if(StackEmpty(*s)) {
		return DELETEERROR;
	}
	--(s->length);
	--(s->top);
	return OK;
}

// 遍历栈中元素
void StackTraverse(Stack s)
{
	if(StackEmpty(s)) {
		return; 
	}
	for(int i = 0; i < s.top; ++i) {
		printf("%c", s.elem[i]);
	}
	printf("\n");
}