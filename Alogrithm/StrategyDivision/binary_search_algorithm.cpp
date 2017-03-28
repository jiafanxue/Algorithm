/*
	二分搜索算法
*/
#include <iostream>
#include <vector>
using namespace std;

// 返回val所在的下标
int binary_search(const vector<int>& vec, int begin, int end, int val)
{
	if (begin > end) {
		return -1;
	}

	int mid = begin + (end - begin) / 2;
	if (vec[mid] > val) {
		return binary_search(vec, begin, mid - 1, val);
	}
	else if (vec[mid] < val) {
		return binary_search(vec, mid + 1, end, val);
	}

	return mid;
}

int main(int argc, char const *argv[])
{
	vector<int> vec = {1, 3, 4, 6, 7, 8, 10, 13, 14};
	cout << binary_search(vec, 0, vec.size(), 4) + 1 << endl;
	return 0;
}