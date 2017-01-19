#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
    	int start = -1;
    	int lenNum = 0;
       	vector<int> dict(256, -1);
       	for(int i = 0; i < (int)s.length(); i++)
       	{
       		if(dict[s[i]] > start)
       			start = dict[s[i]];
       		dict[s[i]] = i;
       		lenNum = max(lenNum, i - start);
        }
        return lenNum;
    }
};

int main()
{
	Solution su;
	cout << su.lengthOfLongestSubstring("abcabcacb") << endl;
	cout << su.lengthOfLongestSubstring("bbbbb") << endl;
	cout << su.lengthOfLongestSubstring("pwwkew") << endl;

	return 0;
}