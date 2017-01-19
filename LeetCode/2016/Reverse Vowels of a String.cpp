#include <iostream>
#include <string>
#include <cmath>
using namespace std;

class Solution {
public:
    string reverseVowels(string s) {
        int i = 0;
        int j = s.size() - 1;
        while(i < j) {
            i = s.find_first_of("aeiouAEIOU", i);
            j = s.find_last_of("aeiouAEIOU", j);
            if(i < j) {
                swap(s[i++], s[j--]);
            }
        }
        return s;
    }
};

int main()
{
	Solution su;

    string str = "leetcode";

    cout << su.reverseVowels(str) << endl;

	return 0;
}