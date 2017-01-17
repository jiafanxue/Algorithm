/*
Question:
	A one-dimensional array elements have N integers, the array of course there are a lot of subarray, so what is the
	maximum value of the sum of the sub array.

*/
#include <iostream>
#include <climits>
#include <vector>
using namespace std;

/*
	Answer one
	Time complexity: O(N^3)
*/
int MaxSumOfSubarray_1(vector<int> vec)
{
	int length = vec.size();
	int maximum = -INT_MAX;			// 负无穷
	int sum;
	for(int i = 0; i < length; ++i) {
		for(int j = i; j < length; ++j) {
			sum = 0;
			for(int k = i; k <= j; ++k) {
				sum += vec[k];
			}
			if(sum > maximum) {
				maximum = sum;
			}
		}
	}
	return maximum;
}

/*
	Answer two
	Time complexity: O(N^2)
*/
int MaxSumOfSubarray_2(vector<int> vec)
{
	int length = vec.size();
	int maximum = -INT_MAX;
	int sum;
	for(int i = 0; i < length; ++i) {
		sum = 0;
		for(int j = i; j < length; ++j) {
			sum += vec[j]; 
			if(sum > maximum) {
				maximum = sum;
			}
		}
	}
	return maximum;
}

/*
	Answer three
	Time complexity: O(N)
*/
int MaxSumOfSubarray_3(vector<int> vec)
{
	int length = vec.size();
	int Start[length];
	int All[length];
	Start[length - 1] = vec[length - 1];
	All[length - 1] = vec[length - 1];
	for(int i = length - 2; i >= 0; --i) {
		Start[i] = max(vec[i], vec[i] + Start[i + 1]);
		All[i] = max(Start[i], All[i + 1]);	
	}
	return All[0];
}

/*
	Answer four
	Time complexity: O(N)
*/
int MaxSumOfSubarray_4(vector<int> vec)
{
	int length = vec.size();
	if(length == 1) {
		return vec[0];
	}
	int nStart = vec[length - 1];
	int nAll = vec[length - 1];
	for(int i = length - 2; i >= 0; --i) {
		nStart = max(vec[i], nStart + vec[i]);
		nAll = max(nStart, nAll);
	}
	return nAll;
}

int main(int argc, char const *argv[])
{
	vector<int> vec = {1, -2, 3, 5, -3, 2};
	vector<int> vec2 = {0, -2, 3, 5, -1, 2};
	vector<int> vec3 = {-9, -2, -3, -5, -3};

	cout << MaxSumOfSubarray_1(vec) << endl;
	cout << MaxSumOfSubarray_2(vec) << endl;
	cout << MaxSumOfSubarray_3(vec) << endl;
	cout << MaxSumOfSubarray_4(vec) << endl;
	return 0;
}