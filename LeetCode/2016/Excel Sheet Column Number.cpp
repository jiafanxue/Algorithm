#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int titleToNumber(string s) {
        int sum =0;
        int pow = 26;
        for(auto c : s)
            sum = sum*pow + c - 'A' + 1;
        return sum;
    }
};

int main()
{
	string str = "AAA";
    Solution su;
	cout << su.titleToNumber(str) << endl;

	return 0;

}