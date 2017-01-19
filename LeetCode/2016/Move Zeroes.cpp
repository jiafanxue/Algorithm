#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int zeronum = 0;
        for(int i = 0; i < (int)nums.size(); i++)
        {
            if(!nums[i])
            {
                zeronum++;
            }
            else
            {
                nums[i - zeronum] = nums[i];
            }
        }
        for(int j = nums.size() - 1;j > nums.size() - zeronum - 1;j--) 
            nums[j]=0;
    }
};

int main()
{
	vector<int> nums = {0,1,0,3,0,5};
    Solution su;
    cout << nums[1] << endl;
	for(int i = 0; i < nums.size(); i++)
    {
        cout << nums[i] << " ";
    }
    cout << " the length: " << nums.size() <<  endl;

    cout << endl;

    su.moveZeroes(nums);
    for(int i = 0; i < nums.size(); i++)
    {
        cout << nums[i] << " ";
    }
    cout << " the length: " << nums.size() <<  endl;

	return 0;
}