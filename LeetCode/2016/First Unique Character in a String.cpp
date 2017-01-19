#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int firstUniqChar(string s) {
    	/*timeout*/
    	/*int index = 0;
        for(int i = 0; i < (int)s.size(); i++) {
        	for(int j = 0; j < (int)s.size(); j++) {
        		if(s[index] == s[j] && index != j)
        		{
        			index++;
        			break;
        		}
        	}
        }
        if(index == (int)s.size())
        	return -1;
        else
        	return index;*/


    	int arr[256]{0};

    	for(auto c : s)
    		arr[(int)c]++;

    	for(int i = 0; i < (int)s.size(); i++)
    	{
    		if(arr[(int)s[i]] == 1)
    			return i;
    	}

    	return -1;


    }
};

int main()
{
	Solution su;
	string s1 = "leletcode";

	cout << su.firstUniqChar(s1) << endl;

	return 0;
}