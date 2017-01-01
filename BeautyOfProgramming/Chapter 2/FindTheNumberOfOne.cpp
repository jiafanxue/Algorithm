/*
Question:
	Given a decimal positive integer N, write down all integers from 1 to N, and then count
the number of all occurrences of "1"
	1. Please write a function f(N) that returns the number of occurrences of "1" between 1 and N
	2. What is the maximum N that satisfies the condition "f(N) = N"?

	给定一个十进制的正整数N，写出所有从1到N的整数，然后数一下其中出现的所有"1"的个数
	1. 写出一个函数f(N),返回1到N之间出现的“1”的个数，比如f(12) = 5
	2. 满足条件“f(N) = N"的最大的N是多少？
*/

#include <iostream>
#include <cmath>
using namespace std;

/*
	Answer 1
	Time complexity : O(N) × 计算一个整数数字里面“1”的个数的复杂度 = O(N*lgN)
*/
template <typename T>
T FindTheNumberOfOne_1(T N)
{
	T iCount = 0;
	for(T i = 1; i <= N; ++i) {
		T j = i;
		while(j != 0) {
			iCount += ((j % 10) == 1) ? 1 : 0;
			j /= 10;	
		}
	}
	return iCount;
}

/*
	Answer 2
	Time complexity: O(ln(N) / ln(10) + 1)
*/
template <typename T>
T FindTheNumberOfOne_2(T N)
{
	T iCount = 0;
	T iFactor = 1;
	T iLowerNum = 0;
	T iCurrNum = 0;
	T iHigerNum = 0;

	while(N / iFactor != 0) {
		iLowerNum = N - (N / iFactor) * iFactor;
		iCurrNum = (N / iFactor) % 10;
		iHigerNum = N / (iFactor * 10);

		switch(iCurrNum) {
			case 0:
				iCount += iHigerNum * iFactor;
				break;
			case 1:
				iCount += iHigerNum * iFactor + iLowerNum + 1;
				break;
			default:
				iCount += (iHigerNum + 1) * iFactor;
				break;
		}
		iFactor *= 10;
	}

	return iCount;
}


int main()
{
	int N;
	cout << "Please enter an integer: ";
	cin >> N;
	cout << FindTheNumberOfOne_1(N) << endl;
	cout << FindTheNumberOfOne_2(N) << endl;
	return 0;
}