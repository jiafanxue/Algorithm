#include <iostream>
#include <string>
#include <cmath>
using namespace std;

class Solution {
public:
    bool isHappy(int n) {
        if(n==1 || n==7) return true;
        if(n < 10) return false;
        int sum = 0;
        while(n)
        {
            int x = n % 10;
            sum += x*x;
            n = n / 10;
        }
        if(sum==1)
            return true;
        return isHappy(sum);
    }
};

int main()
{
	Solution su;

    int n = 49;

    if(su.isHappy(n))
    {
        cout << "Yes!" << endl;
    }
    else
    {
        cout << "No!" << endl;
    }

	return 0;
}