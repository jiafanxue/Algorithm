#include <iostream>
#include <string>
using namespace std;
class Solution {
public:
    int getSum(int a, int b) {
        return a + b;
    }
};

int main()
{
	Solution su;
	cout << su.getSum(1, 2) << endl;
	return 0;
}