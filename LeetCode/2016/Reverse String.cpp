#include <iostream>
#include <string>
using namespace std;
class Solution {
public:
    string reverseString(string s) {
    	string revstring;
        for(int i = s.size() - 1; i >= 0; i--)
        {
        	revstring.push_back(s[i]);
        }

        return revstring;
    }
};

int main()
{
	Solution su;
	cout << su.reverseString("hello") << endl;
	return 0;
}