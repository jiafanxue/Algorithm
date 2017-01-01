/*
Question:
	Given an integer n, return the number of trailing zeroes in n!.

	Note: Your solution should be in logarithmic time complexity.
*/

#include <iostream>
using namespace std;

class Solution {
public:
    int trailingZeroes(int n) {
       	int count = 0;
       	while(n) {
       		count += n / 5;
       		n /= 5;
       	}
       	return count;
    }

    int trailingZeroes_2(int n) {
       	int count = 0;
       	for(int i = 1; i <= n; ++i) {
       		int j = i;
       		while(j % 5 == 0) {
       			count++;
       			j /= 5;
       		}
       	}
       	return count;
    }
};



int main()
{
	Solution su;

	cout << su.trailingZeroes(10) << endl;
	cout << su.trailingZeroes_2(10) << endl;

	return 0;
}