/*
Question:
	Find the maximum number of Ks from the array.

	从数组中找到最大的K个数
*/

#include <iostream>
#include <utility>
#include <vector>
using namespace std;

int partition_1(vector<int>& vec, int r, int q)
{
	int x = vec[q];
	int i = r - 1;
	for(int j = r; j < q; ++j) {
		if(vec[j] <= x) {
			i += 1;
			swap(vec[i], vec[j]);
		}
	}
	swap(vec[i + 1], vec[q]);
	return i + 1;
}

void quicksort(vector<int>& vec, int r, int q)
{
	if(r < q) {
		int p = partition_1(vec, r, q);
		quicksort(vec, r, p - 1);
		quicksort(vec, p + 1, q);
	}
}

/*
	Answer 1
*/
vector<int> FindTheMaxNumber_1(vector<int> vec, const int k)
{
	if(k <= 0) {
		return vector<int>();
	}

	int size = vec.size();
	if(size <= k) {
		return vec;
	}

	vector<int> temp;
	quicksort(vec, 0, (size - 1));

	for(int i = 0; i < k; ++i) {
		temp.push_back(vec[vec.size() - 1 - i]);
	}

	return temp;
}


/*
	Answer 2
*/
// pair<vector<int>, vector<int>> partition_2(vector<int>& vec, int r, int q)
// {
// 	vector<int> veca;
// 	vector<int> vecb;

// 	int x = vec[0];
// 	for(int i = 0; i < )


// 	return make_pair(veca, vecb);
// }

// vector<int> FindTheMaxNumber_2(vector<int> vec, const int k)
// {
// 	if(k <= 0) {
// 		return vector<int>();
// 	}

// 	int size = vec.size();
// 	if(size <= k) {
// 		return vec;
// 	}

// 	pair<vector<int>, vector<int>> array;
// 	vector<int> temp;
// 	vector<int> veca;
// 	vector<int> vecb; 
// 	array = partition_2(vec, 0, (size - 1));

// 	veca = array.first;
// 	vecb = array.second;

// 	for(unsigned i = 0; i < veca.size(); ++i) {
// 		temp.push_back(veca[i]);
// 	}
// 	for(unsigned i = 0; i < vecb.size(); ++i) {
// 		temp.push_back(vecb[i]);
// 	}
// 	return FindTheMaxNumber_2(temp, k);
// }

/*
	Answer 3
	binary search
*/
// vector<int> FindTheMaxNumber_3(vector<int> vec, const int k)
// {	
// 	vector<int> temp;

	


// 	return temp;
// }

int main()
{
	int K = 4;
	vector<int> vec = {1,13,35,61,2,3,15,16,8,98,88,45,22,14,16,17,10,97,76};
	vector<int> temp = FindTheMaxNumber_1(vec, K);
	for(unsigned i = 0; i < temp.size(); ++i) {
		cout << temp[i] << ' ';
	}
	cout << endl;

	return 0;
}