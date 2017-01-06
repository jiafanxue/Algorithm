/*
Question:
	Give some points, find the closest point pair.	
*/
#include <iostream>
using namespace std;

/*
	One-dimensional
	Time complexity: 0(N^2)
*/
double MinDifference_1(double arr[], int n)
{
	if(n < 2) {
		return 0;
	}

	double fMinDiff = fabs(arr[0] - arr[1]);
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < n; ++j) {
			double tmp = fabs(arr[i] - arr[j]);
			if(fMinDiff > tmp) {
				fMinDiff = tmp;
			}
		} 
	}

	return fMinDiff;
}

/*
	Other answer
	Time complexity: 0(N*log2(N))
*/
double MinDifference_2(double arr[], int n)
{
	if(n < 2) {
		return 0;
	}
	Sort(arr, arr + n);

	double fMinDiff = arr[1] - arr[0];
	for(int i = 2; i < n; ++i) {
		double tmp = arr[i] - arr[i - 1];
		if(fMinDiff > tmp) {
			fMinDiff = tmp;
		}
	}

	return fMinDiff;
}



int main(int argc, char const *argv[])
{
	
	return 0;
}