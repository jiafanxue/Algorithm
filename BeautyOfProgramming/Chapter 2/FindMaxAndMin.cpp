/*
Question:
	Find the maximum and minmun number from array.
*/

#include <iostream>
#include <utility>		// for pair<int, int>.
#include <vector>
using namespace std;

/*
	Answer 1
	We need compare 2*N times.
*/
void FindMaxAndMin_1(vector<int>& vec, int* array, int n)
{
	int max = array[0];
	int min = array[0];
	for(int i = 1; i < n; ++i) {
		if(max < array[i]) {
			max = array[i];
		}
		if(min > array[i]) {
			min = array[i];
		}
	}
	vec.push_back(max);
	vec.push_back(min);
}

/*
	Answer 2
	We need compare 1.5*N times.
	
	Exchange : 0.5*N
	Find Max : 0.5*N
	Find Min : 0.5*N
	---------------------------------
	FindMaxAndMin_2 function will destroy the array.
	FindMaxAndMin_3 function will not destroy the array.
*/
void FindMaxAndMin_2(vector<int>& vec, int* array, int n)
{
	// 0.5*N
	for(int i = 0; i < n; i += 2) {
		if(array[i] < array[i + 1]) {
			swap(array[i], array[i + 1]);
		}
	}

	int max = array[0];
	int min = array[1];
	// 1*N
	for(int i = 2; i < n; i += 2) {
		if(max < array[i]) {
			max = array[i];
		}
		if(min > array[i + 1]) {
			min = array[i + 1];
		}
	}

	vec.push_back(max);
	vec.push_back(min);
}

void FindMaxAndMin_3(vector<int>& vec, int* array, int n)
{
	int max = array[0];
	int min = array[0];
	for(int i = 0; i < n; i += 2) {
		if(array[i] < array[i + 1]) {
			if(max < array[i + 1]) {
				max = array[i + 1];
			}
			if(min > array[i]) {
				min = array[i];			
			}
		}
		else {
			if(max < array[i]) {
				max = array[i];
			}
			if(min > array[i + 1]) {
				min = array[i + 1];			
			}
		}
	}
	vec.push_back(max);
	vec.push_back(min);
}

/*
	Answer 3
	We need compare 1.5*N times.
*/
pair<int, int> FindMaxAndMin_4(int* array, int begin, int end)
{
	if(end - begin <= 1) {
		if(array[begin] < array[end]) {
			return make_pair(array[end], array[begin]);
		}
		else {
			return make_pair(array[begin], array[end]);
		}
	}

	pair<int, int> arrayL = FindMaxAndMin_4(array, begin, begin + (end - begin) / 2);
	pair<int, int> arrayR = FindMaxAndMin_4(array, (begin + (end - begin) / 2) + 1, end);

	int maxV;
	int minV;
	if(arrayL.first > arrayR.first) {
		maxV = arrayL.first;
	}
	else {
		maxV = arrayR.first;
	}

	if(arrayL.second < arrayR.second) {
		minV = arrayL.second;
	}
	else {
		minV = arrayR.second;
	}
	return make_pair(maxV, minV);
}

int main(int argc, char const *argv[])
{
	int n = 20;
	int array[] = {5, 6, 8, 3, 7, 9, 7, 0, 1, 2, 3, 19, 22, 33, 16, 3, 44, 32, 12, 10};
	vector<int> vec1;
	FindMaxAndMin_1(vec1, array, n);

	for(unsigned i = 0; i < vec1.size(); ++i) {
		cout << vec1[i] << " ";
	}
	cout << endl;

	vector<int> vec2;
	FindMaxAndMin_2(vec2, array, n);

	for(unsigned i = 0; i < vec2.size(); ++i) {
		cout << vec2[i] << " ";
	}
	cout << endl;

	vector<int> vec3;
	FindMaxAndMin_3(vec3, array, n);
	for(unsigned i = 0; i < vec3.size(); ++i) {
		cout << vec3[i] << " ";
	}
	cout << endl;

	pair<int, int> pair_arr = FindMaxAndMin_4(array, 0, n);
	cout << pair_arr.first << " " << pair_arr.second << endl;
	return 0;
}