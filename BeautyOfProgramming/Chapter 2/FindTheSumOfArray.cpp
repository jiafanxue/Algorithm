/*
Question:
	Find an array of two numbers, so that the sum of these two figures is equal to a give value.

	e.g.
		5,6,1,4,7,9,8

		1,5,6,7,8,9
*/
#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>
using namespace std;

/*
	Answer one
	Time complexity: O(N^2)
*/
pair<int, int> FindTheSumOfArray_1(vector<int> vec, int sum)
{
	int ia, ib;
	for(unsigned i = 0; i < vec.size(); ++i) {
		for(unsigned j = i + 1; j < vec.size(); ++j) {
			if(vec[i] + vec[j] == sum) {
				ia = vec[i];
				ib = vec[j];
				return make_pair(ia, ib);			
			}
		}
	}
	return make_pair(-1, -1);
}

/*
	Answer two
	Time complexity: O(N*log2(N))
*/
/*
 	BinarySearch 
	Time complexity: O(log2(N))
*/
bool BinarySearch(vector<int> vec, int ib)
{
	int begin = 0;
	int end = vec.size();
	while(begin < end) {
		int intermediate = (end + begin) / 2;
		if(ib < vec[intermediate]) {
			end = intermediate;
		}
		else if(ib > vec[intermediate]) {
			begin = intermediate;
		}
		else {
			return true;
		}
	}
	return false;
}

pair<int, int> FindTheSumOfArray_2(vector<int> vec, int sum)
{
	sort(vec.begin(), vec.end());
	int ia, ib;
	for(unsigned i = 0; i < vec.size(); ++i) {
		ia = vec[i];
		ib = sum - ia;
		if(BinarySearch(vec, ib)) {
			return make_pair(ia, ib);
		}
	}
	return make_pair(-1, -1);
}

/*
	Answer three
	Time complexity: O(N*log2(N))
*/
pair<int, int> FindTheSumOfArray_3(vector<int> vec, int sum)
{
	sort(vec.begin(), vec.end());
	for(unsigned i = 0, j = vec.size() - 1; i < j;) {
		if(vec[i] + vec[j] == sum) {
			return make_pair(vec[i], vec[j]);
		}
		else if(vec[i] + vec[j] < sum) {
			i++;
		}
		else {
			j--;
		}
	}
	return make_pair(-1, -1);
}

int main()
{
	int sum;
	cin >> sum;
	vector<int> vec1 = {5, 6, 1, 4, 7, 9, 8};
	vector<int> vec2 = {1, 5, 6, 7, 8, 9};
	pair<int, int> par1 = FindTheSumOfArray_1(vec1, sum);
	cout << par1.first << "+" << par1.second << "=" << sum << endl;

	pair<int, int> par2 = FindTheSumOfArray_2(vec1, sum);
	cout << par2.first << "+" << par2.second << "=" << sum << endl;

	pair<int, int> par3 = FindTheSumOfArray_3(vec1, sum);
	cout << par3.first << "+" << par3.second << "=" << sum << endl;
	return 0;
}
