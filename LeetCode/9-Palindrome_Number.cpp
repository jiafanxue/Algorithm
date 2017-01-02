/*
Question:
	Determine whether an integer is a palidrome.Do this without extra space.
*/
#include <iostream>
#include <string>
#include <cmath>
using namespace std;

// class Solution {
// public:
//     bool isPalindrome(int x) {
//         string num = to_string(x);
//         int size = num.size();
//         for(int i = 0; i < size / 2; ++i) {
//         	if(num[i] != num[size - i - 1]) {
//         		return false;
//         	}
//         }
//         return true;
//     }
// };

class Solution {
public:
	bool isPalindrome(int x) {
		if(x < 0 || (x != 0 && x % 10 == 0)) {
			return false;
		}
		int sum = 0;
		while(x > sum) {
			sum = sum*10 + x % 10;
			x = x/10;
		}
		return (x == sum) || (x == sum / 10);
	}
};

int main(int argc, char const *argv[])
{
	int num;
	cin >> num;
	Solution su;
	if(su.isPalindrome(num)) {
		cout << "Yes" << endl;
	}
	else {
		cout << "No" << endl;
	}

	return 0;
}