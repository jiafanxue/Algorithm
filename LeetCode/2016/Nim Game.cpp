#include <iostream>
#include <string>
using namespace std;
class Solution {
public:
    bool canWinNim(int n) {
        return n % 4 == 0;
    }
};

int main()
{
	Solution su;
	if(su.canWinNim(5))
    {
        cout << "You are Winner!" << endl;
    }
    else
    {
        cout << "You are not Winner!" << endl;
    }
	return 0;
}