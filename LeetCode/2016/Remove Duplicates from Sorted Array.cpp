#include <iostream>
#include <vector>
using namespace std;

// class Solution {
// public:
// 	int removeDuplicates(vector<int>& nums) {
// 		if(nums.size() == 0)
// 			return 0;
// 		if(nums.size() == 1)
// 			return 1;
// 		int count = 0;
// 		vector<int> temp = nums;
// 		for(unsigned i = 0, j = 0; i < temp.size() - 1; ++i) {
// 			if(temp[j] == temp[i + 1]) {
// 				nums.erase(nums.begin() + i);
// 			}
// 			else {
// 				count++;
// 				j = i + 1;
// 			}
// 		}

// 		return count + 1;
// 		// return nums.size();
// 	}
// };

class Solution
{
public:
	int removeDuplicates(vector<int>& nums) {
		int i = 0;
		for(int n : nums) {
			if(!i || n > nums[i-1]) {
				nums[i++] = n;
			}
		}
		return i;
	}
};

int main()
{
	vector<int> vec = {1,1,3,4,5,5,7,7};

	Solution su;

	cout << su.removeDuplicates(vec) << endl;

	for(auto n : vec) {
		cout << n << " ";
	}

	return 0;
}