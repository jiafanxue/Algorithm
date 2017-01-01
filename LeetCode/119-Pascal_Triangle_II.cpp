/*
Question:
	Given an index k, return the kth row of the Pascal's triangle.

	For example, given k = 3,
	Return [1,3,3,1].
	
	Pascal's Triangle:
	1
	1 1
	1 2 1
	1 3 3 1
	1 4 6 4 1
	1 5 10 10 5 1
	.....
*/

#include <iostream>
#include <vector> 
using namespace std;

class Solution {
public:
	vector<int> getRow(int rowIndex) {
		vector<int> vec(rowIndex + 1);
		vec[0] = 1;
		for(int i = 0; i <= rowIndex; ++i) {
			for(int j = i; j > 0; --j) {
				vec[j] += vec[j - 1];
			}
		}
		return vec;
	}
};


int main()
{
	Solution su;

	vector<int> vec = su.getRow(3);

	for(auto it = vec.begin(); it != vec.end(); ++it) {
		cout << *it << " ";
	}
	cout << endl;
	return 0;
}