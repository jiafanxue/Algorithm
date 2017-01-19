#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        int array[256]{0};

        if(s.size() != t.size())
        	return false;

        for(auto c : s) {
        	array[(int)c]++;
        }

        for(auto c2 : t) {
        	if(--array[(int)c2] < 0)
        		return false;
        }
        return true;
    }
};






int main()
{
	string s1 = "array";
	string s2 = "rray";

	string s3 = "anagram";
	string s4 = "nagaram";

	string s5 = "rat";
	string s6 = "rats";

	Solution su;

	if(su.isAnagram(s3,s4))
	{
		cout << "true" << endl;
	}
	else
	{
		cout << "false" << endl;
	}


	return 0;
}