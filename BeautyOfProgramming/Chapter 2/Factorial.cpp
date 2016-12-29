/*
Question:
	factorial:
		1. Give a integer "N", calculate the factorial of N. And count the number of "0" at the end.
		2. Find the position of the least significant bit "1" in the binary representation of N!.

	阶乘：
		1. 给定一个N，那么N的阶乘N!末尾有多少个0呢？例如：N=10，N!=362800，N!的末尾有两个0
		2. 求N!的二进制表示中最低位1的位置
	
		  1 	  if n = 0
	n! = 
		  n(n-1)! if n > 0
*/
#include <iostream>
using namespace std;

/*
	Answer one:
*/
int CountZero_1(int N)
{
	int ret = 0;
	for(int i = 1; i <= N; ++i) {
		int j = i;
		while(j % 5 == 0) {
			ret++;
			j /= 5;
		}
	}
	return ret;
}

int CountZero_2(int N)
{
	int ret = 0;
	while(N) {
		ret += N / 5;
		N /= 5;
	}
	return ret;
}

/*
	Answer two:
*/
int LowestOne_1(int N)
{
	int ret = 0;
	while(N) {
		N >>= 1;
		ret += N;
	}
	return ret;
}

int main()
{

	int a = 10;

	cout << CountZero_1(a) << endl;
	cout << CountZero_2(a) << endl;

	cout << "=====================" << endl;

	int b =3;
	cout << LowestOne_1(b) << endl;
	return 0;
}