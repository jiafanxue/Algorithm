#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int matrix[256] = {0};

        for(auto c : magazine) matrix[(int)c]++;
        for(auto s : ransomNote) if(--matrix[(int)s] < 0) return false;
        return true;
    }
};

int main()
{
    Solution su;
	if(!su.canConstruct("a", "b"))
    {
        cout << "false" << endl;
    }

    if(!su.canConstruct("aa", "ab"))
    {
        cout << "false" << endl;
    }

    if(su.canConstruct("aaa", "aaba"))
    {
        cout << "true" << endl;
    }

	return 0;

}