#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
    int singleNumber(vector<int>& nums) {
    	for(int i = 1; i < (int)nums.size(); ++i) 
    		nums[0] ^= nums[i];
    	return nums[0];  
    }
};


int main()
{
	vector<int> nums = {1,1,2,2,3,4,4,5,5};
	Solution su;
	cout << su.singleNumber(nums) << endl;
	return 0;
}