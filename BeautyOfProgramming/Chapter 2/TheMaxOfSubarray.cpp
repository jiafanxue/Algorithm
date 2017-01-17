/*
Question:
	Give an array of integers of length N, use only multiplication to compute the largest set of products in any (N - 1)
	number of combinations.
*/
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

/*
	Answer one
	Time complexity: O(N*log2(N))
	
	The Algorithm is so bad!!!
*/
int TheMaxOfSubarray_1(vector<int> vec)
{
	sort(vec.begin(), vec.end());
	int sum = 1;
	for(unsigned i = 1; i < vec.size(); ++i) {
		sum *= vec[i];
	}
	return sum;
}

/*
	Answer two
	The complexity: O(N)
*/
int TheMaxOfSubarray_2(vector<int> vec)
{
	int size = vec.size();
	int* pArray = new int[size];			// Sum of max 	
	int* sArray = new int[size + 1];		// sum of before i
	int* tArray = new int[size + 1];		// sum of behind i

	sArray[0] = 1;
	tArray[size + 1] = 1;
	for(unsigned i = 1; i <= vec.size(); ++i) {
		sArray[i] = sArray[i - 1] * vec[i - 1];
		tArray[i] = tArray[i + 1] * vec[i];
		pArray[i] = sArray[i - 1] * tArray[i + 1];
	}

	int sum = pArray[1];
	for(int i = 1; i < size; ++i) {
		if(sum < pArray[i]) {
			sum = pArray[i];
		}
	}	
	return sum;
}

int main(int argc, char const *argv[])
{
	vector<int> vec = {4, 3, 6, 1, 9, 2, 8, 5, 7, 10};
	cout << TheMaxOfSubarray_1(vec) << endl;
	cout << TheMaxOfSubarray_2(vec) << endl;
	return 0;
}