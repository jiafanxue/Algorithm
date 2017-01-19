// 这题就是即斐波那契问题!!
#include <iostream>
using namespace std;

class Solution {
public:
	int climbStairs(int n) {
		if(n <= 0) 
			return 0;
		if(n == 1) 
			return 1;
		if(n == 2)
			return 2;

		int a = 1;
		int b = 1;
		while(n--) {
			a = (b += a) - a;
		}
		return a;
	}
};


// class Solution {
// public:
// 	int climbStairs(int n) {
// 		if(n <= 0) {
// 			return 0;
// 		}
// 		if(n == 1) 
// 			return 1;
// 		if(n == 2)
// 			return 2;

// 		int one_step_before = 2;
// 		int two_step_before = 1;
// 		int all_ways = 0;

// 		for(int i = 2; i < n; ++i) {
// 			all_ways = one_step_before + two_step_before;
// 			two_step_before = one_step_before;
// 			one_step_before = all_ways;
// 		}
// 		return all_ways;
// 	}
// };


// class Solution {
// public:
//     int climbStairs(int n) {
//  		int kinds = 0;

//  		if(n <= 0)
//  			return 0;

//  		for(int i = 0;  2 * i <= n; ++i) {
//  			int j = n - 2 * i;
//  			if(i == 0) {
//  				kinds += 1;
//  			}
//  			else {
//  				int sum_n = 1;
//  				int sum_n_m = 1;
//  				int sum_m = 1;

//  				for(int n = 0, t = 1; n < i+j; ++n, ++t) {
//  					sum_n *= t;
//  				}

//  				for(int nm = 0, t = 1; nm < j; ++nm, ++t) {
//  					sum_n_m *= t;
//  				}

//  				for(int m = 0, t = 1; m < i; ++m, ++t) {
//  					sum_m *= t;
//  				}

//  				kinds += sum_n / (sum_n_m * sum_m);
//  			}
//  		}
//  		return kinds;
//     }
// };

int main()
{
	int n = 4;

	Solution su;
	
	cout << su.climbStairs(n) << endl;

	return 0;
}