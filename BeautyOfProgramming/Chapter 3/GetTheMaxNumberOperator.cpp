/*
Question:
	Suppose there is a queue with three operations:
		1. EnQueue(v): Put v in the queue
		2. DeQueue: Causes the queue element in the queue to be deleted and return the element.
		3. MaxElement: Return the largest element int the queue.
*/
#include <iostream>
#include <climits>
using namespace std;

const int MAXN = 10;

template <typename Type>
class stack
{
public:
	stack()
	{
		stackTop = -1;
		maxStackItemIndex = -1;
	}

	void Push(Type x)
	{
		stackTop++;
		if(stackTop >= MAXN) {
			;		// 超出栈的最大存储量
		}
		else {
			stackItem[stackTop];
			if(x > Max()) {
				link2NextMaxItem[stackTop] = maxStackItemIndex;
				maxStackItemIndex = stackTop;
			}
			else {
				link2NextMaxItem[stackTop] = -1;
			}
		}
	}

	Type Pop()
	{
		Type ret;
		if(stackTop < 0) {
			ThrowException();	// 已经没有元素了，所以不能pop
		}
		else {
			ret = stackItem[stackTop];
			if(stackTop == maxStackItemIndex) {
				maxStackItemIndex = link2NextMaxItem[stackTop];
			}
			stackTop--;
		}
		return ret;
	}

	Type Max()
	{
		if(maxStackItemIndex >= 0) {
			return stackItem[maxStackItemIndex];
		}
		else {
			return -INT_MAX;
		}
	}

private:
	Type stackItem[MAXN];
	int stackTop;
	int link2NextMaxItem[MAXN];
	int maxStackItemIndex;
};

/*
	Answer two
*/
template <typename Type>
class Queue
{
public:
	Type MaxValue(Type x, Type y)
	{
		if(x > y) {
			return x;
		}
		else {
			return y;
		}
	}

	Type Queue::Max()
	{
		return MaxValue(stackA.Max(), stackB.Max());
	}

	void EnQueue(Type v)
	{
		stackB.push(v);	
	}

	Type DeQueue()
	{
		if(stackA.empty()) {
			while(!stackB.empty()) {
				stackA.push(stackB.pop());
			}
			return stackB.pop();
		}
	}

private:
 	stack stackA;
 	stack stackB;
};


int main()
{

	return 0;
}