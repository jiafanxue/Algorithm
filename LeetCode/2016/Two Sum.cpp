#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
        for(int i = 0; i < nums.size(); i++)
        	for(int j = i + 1; j < nums.size() ; j++)
        	{
        		if(nums[i] + nums[j] == target)
        		{
        			result.push_back(i);
        			result.push_back(j);
        		}
        	}

        return result;
    }
};

int main()
{
	vector<int> vec = {1,2,8,7};
	Solution su;
	auto t = su.twoSum(vec, 9);
	for(auto i = t.begin(); i != t.end(); i++)
	{
		cout << *i << endl;
	}

	return 0;

}