/*
Question:
	There is a disorder, the number of elements is 2 * N positive integer array.

	requires:
		how can this array is divided into two elements for the N number of arrays, and make the sum of two sub-array closest.
*/
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

/*
	Answer one

	lvec and rvec are not optimal.
*/
void ArrayPartition(vector<int> vec, vector<int>& lvec, vector<int>& rvec)
{
	sort(vec.begin(), vec.end());

	int lsum = 0;
	int rsum = 0;
	int minimum;
	for(unsigned i = 0; i < vec.size(); i += 2) {
		lvec.push_back(vec[i]);
		lsum += vec[i];
	}

	for(unsigned i = 1; i < vec.size(); i += 2) {
		rvec.push_back(vec[i]);
		rsum += vec[i];
	}

	minimum = lsum - rsum > 0 ? lsum - rsum : rsum - lsum;
	int re_minmun;
	for(unsigned i = 0; i < vec.size() / 2; ++i) {
		int lhs = lvec[i];
		for(unsigned j = 0; j < vec.size() / 2; ++j) {
			int rhs = rvec[j];
			lsum = lsum - lhs + rhs;
			rsum = rsum - rhs + lhs;
			re_minmun = lsum - rsum > 0 ? lsum - rsum : rsum - lsum;
			if(re_minmun < minimum) {
				swap(lvec[i], rvec[j]);
			}
			else {
				lsum = lsum + lhs - rhs;
				rsum = rsum + rhs - lhs;
			}
		}
	}
}

/*
	Answer two
	
	isOK[i][v]表示是否可以找到i个数，使得它们之和等于v
	初始化 isOK[0][0] = true;
		   isOK[i][v] = false (i > 0, v > 0)

	Time complexity: O(N^2 * Sum)
*/
void ArrayPartition_2(vector<int> vec, vector<int>& lvec, vector<int>& rvec)
{
	int Sum = 0;
	for(unsigned i = 0; i < vec.size(); ++i) {
		Sum += vec[i];
	}

	int size = vec.size();
	int isOK[size][Sum];
	isOK[0][0] = 1;
	isOK[size][Sum] = 0;

	int n = size / 2;
	for(int k = 1; k <= 2 * n; ++k) {
		for(int i = min(k, n); i >= 1; --i) {
			for(int v = 1; v <= Sum / 2; ++v) {
				if(v >= vec[k] && isOK[i - 1][v - vec[k]]) {
					isOK[i][k] = true;
				}
			}
		}
	}
	
}

int main(int argc, char const *argv[])
{
	vector<int> vec = {1, 5, 7, 8, 9, 6, 3, 11, 20, 17};
	vector<int> lvec;
	vector<int> rvec;

	ArrayPartition(vec, lvec, rvec);

	for(unsigned i = 0; i < lvec.size(); ++i)  {
		cout << lvec[i] << " ";
	}
	cout << endl;

	for(unsigned i = 0; i < rvec.size(); ++i) {
		cout << rvec[i] << " ";
	}
	cout << endl;

	return 0;
}