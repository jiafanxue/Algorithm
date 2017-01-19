#include <iostream>
#include <cmath>
using namespace std;

class Solution {
public:
    bool isPowerOfFour(int num) {
    	if(num <= 0) 
    		return false;
    	return (log10(num) / log10(4) - (int)(log10(num) / log10(4)) > 0 ? false : true); 
    }
};

int main()
{
	Solution su;

	int n = 5;

	if(su.isPowerOfFour(n)) {
		cout << "Yes" << endl;
	}
	else {
		cout << "No" << endl;
	}

	return 0;
}