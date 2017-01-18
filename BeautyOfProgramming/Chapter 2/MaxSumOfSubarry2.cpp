/*
Question:
	A two-dimensional array elements have N*M integers, the array of course there are a lot of subarray, so what is the
	maximum value of the sum of the sub array.
*/
#include <iostream>
#include <vector>
using namespace std;

/*
	Answer one

	A: 二维数组
	n: 行数
	m: 列数
*/
int MaxSum_1(int* A, int n, int m)
{
	int maximum = -INT_MAX;
	for(int i_min = 1; i_min <= n; ++i_min) {
		for(int i_max = i_min; i_max <= n; ++i_max) {
			for(int j_min = 1; j_min <= m; ++j_min) {
				for(int j_max = j_min; j_max <= m; ++j_max) {
					maximum = max(maximum, Sum(A, i_min, i_max, j_min, j_max));	// Sum 表示求和
				}
			}
		}
	}
	return maximum;
}

/*
	Answer two

	A: 二维数组
	n: 行数
	m: 列数
*/
int MaxSum_2(int* A, int n, int m)
{
	int maximum = -INT_MAX;
	for(int a = 1; a <= n; ++a) {
		for(int c = a; c <= n; ++c) {
			int Start = BC(a, c, m);			// 表示在第a行和第c行之间的第i列的所有元素之和
			int All = BC(a, c, m);
			for(int i = m - 1; i >= 1; --i) {
				if(Start < 0) {
					Start = 0;
				}
				Start += BC(a, c, i);
				if(Start > All) {
					All = Start;
				}
				if(All > maximum) {
					maximum = All;
				}
			}
		}
	}
	return maximum;
}

int main()
{


	return 0;
}