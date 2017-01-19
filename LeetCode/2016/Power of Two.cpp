#include <iostream>
#include <string>
#include <cmath>
using namespace std;

class Solution {
public:
    bool isPowerOfTwo(int n) {
        // return fmod((log10(n) / log10(2))- (int)(log10(n) / log10(2)), 1) == 0;
        return n > 0 && !(n & (n-1));
    }
};

int main()
{
	Solution su;

    int n = 4;

    if(su.isPowerOfTwo(n))
    {
        cout << "Yes!" << endl;
    }
    else
    {
        cout << "No!" << endl;
    }

	return 0;
}