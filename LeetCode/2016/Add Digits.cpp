#include <iostream>
#include <string>
using namespace std;
class Solution {
public:
    int addDigits(int num) {
        return ((num - 1) % 9) + 1;
    }
};


int main()
{
	Solution su;
	cout << su.addDigits() << endl;
	return 0;
}