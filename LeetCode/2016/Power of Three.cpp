#include <iostream>
#include <string>
#include <cmath>
using namespace std;

class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n == 0)
            return false;
        return ((log10(n) / log10(3))- (int)(log10(n) / log10(3))) > 0 ? false : true;
    }
};

int main()
{
	Solution su;

    int n = 5;

    if(su.isPowerOfThree(n))
    {
        cout << "Yes!" << endl;
    }
    else
    {
        cout << "No!" << endl;
    }

	return 0;
}