#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> temp;
            



        return temp;
    }
};

int main()
{
	vector<int> vec = {1,2,2,7}, vec2 = {2,2};
	Solution su;
	vector<int> temp = su.intersection(vec, vec2);
    for(auto i = temp.begin(); i != temp.end(); i++)
    {
        cout << *i << " ";
    }
    cout << endl;

	return 0;

}