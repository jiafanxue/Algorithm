#include <iostream>
using namespace std;

class Solution {
public:
    bool isUgly(int num) {
        if(num <= 0)
            return false;
        if(num == 1 || num == 2 || num == 3 || num == 5)
            return true;
        if(num % 2 == 0)
            return isUgly(num / 2);
        else if(num % 3 == 0)
            return isUgly(num / 3);
        else if(num % 5 == 0)
            return isUgly(num / 5);
        else
            return false;
    }
};
int main()
{
	Solution su;

    int num = 34;

	if(su.isUgly(num))
    {
        cout << "Yes!" << endl;
    }
    else
    {
        cout << "No!" << endl;
    }

	return 0;
}