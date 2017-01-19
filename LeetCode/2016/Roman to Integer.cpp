#include <iostream>
#include <string>
#include <map>
using namespace std;

class Solution {
public:
    int romanToInt(string s) {
    	map<char, int> map1;
    	map1['I'] = 1;
    	map1['V'] = 5;
    	map1['X'] = 10;
    	map1['L'] = 50;
    	map1['C'] = 100;
    	map1['D'] = 500;
    	map1['M'] = 1000;

    	int result = 0;
    	int cursum = 0;
    	int index = s.size() - 1;
    	int presum = 0;
    	while(index >= 0)
    	{
    		cursum = map1[s[index]];
    		if(cursum >= presum)
    			result += map1[s[index]];
    		else
    			result -= map1[s[index]];
    		presum = cursum;
    		index--;
    	}
    	return result;
    }
};

int main(int argc, char const *argv[])
{

	Solution su;
	string str("DCL");
	cout << su.romanToInt(str) << endl;
	return 0;
}