/*
	最大子数组问题
		方法一：暴力求解法，时间复杂度O(n^2)
		方法二：分治算法，时间复杂度O(n*lgn)

*/
#include <iostream>
#include <vector>
using namespace std;

struct data_struct
{
	int max_left;
	int max_right;
	int sum;
};

// 暴力求解
void Find_Max(const vector<int>& vec, data_struct& t_data)
{
	int low = 0;
	int high = 0;
	int sum;
	int maxSum = -1000;
	for (unsigned i = 0; i < vec.size(); ++i) {
		sum = 0;
		for (unsigned j = i; j < vec.size(); ++j) {
			sum += vec[j];
			if (sum >= maxSum) {
				low = i;
				high = j;
				maxSum = sum;
			}
		}
	}
	t_data.max_left = low;
	t_data.max_right = high;
	t_data.sum = maxSum;
}


// 分治策略
// 处理跨越中点的最大子数组，在线性时间内能够求解出来
data_struct FindMaxCrossingSubarray(const vector<int>& vec, int low, int mid, int high)
{
	int max_left_sum = -10000;
	int lsum = 0;
	int max_left;
	for (int i = mid; i >= low; --i) {
		lsum += vec[i];
		if (lsum > max_left_sum) {
			max_left_sum = lsum;
			max_left = i;
		}
	}

	int max_right_sum = -10000;
	int rsum = 0;
	int max_right;
	for (int i = mid + 1; i <= high; ++i) {
		rsum += vec[i];
		if (rsum > max_right_sum) {
			max_right_sum = rsum;
			max_right = i;
		}
	}

	data_struct temp;
	temp.max_left = max_left;
	temp.max_right = max_right;
	temp.sum = max_left_sum + max_right_sum;
	return temp;
}

data_struct FindMaximmSubarray(const vector<int>& vec, int low, int high)
{
	if (low == high) {
		data_struct temp;
		temp.max_left = low;
		temp.max_right = high;
		temp.sum = vec[low];
		return temp;
	}

	int mid = (low + high) / 2;
	data_struct left_temp, right_temp, crossing_temp;
	left_temp = FindMaximmSubarray(vec, low, mid);
	right_temp = FindMaximmSubarray(vec, mid + 1, high);
	crossing_temp = FindMaxCrossingSubarray(vec, low, mid, high);

	if (left_temp.sum >= right_temp.sum && left_temp.sum >= crossing_temp.sum) {
		return left_temp;
	}
	else if (right_temp.sum >= left_temp.sum && right_temp.sum >= crossing_temp.sum) {
		return right_temp;
	}
	else {
		return crossing_temp;
	}
}

int main(int argc, char const *argv[])
{
	vector<int> vec = {13, -3, -25, 20, -3, -16, -23, 18, 20, -7, 12, -5, -22, 15, -4, 7};
	data_struct t_data{0, 0, 0};
	// Find_Max(vec, t_data);
	t_data = FindMaximmSubarray(vec, 0, vec.size() - 1);
	cout << t_data.max_left << endl;
	cout << t_data.max_right << endl;
	cout << t_data.sum << endl;
	return 0;
}