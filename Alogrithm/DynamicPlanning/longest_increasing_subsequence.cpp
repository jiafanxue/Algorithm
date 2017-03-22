/*
	最长递增子序列/最长递减子序列
*/
#include <algorithm>
#include <iostream>
#include <vector>
#include <utility>
using namespace std;

// 解法一 ： 将问题转换为最长公共子序列问题
int lcs_length(const vector<int>& x_str, const vector<int>& y_str)
{
	int x_str_size = x_str.size();
	int y_str_size = y_str.size();

	vector<vector<int>> vv_num(x_str_size + 1, vector<int>(y_str_size + 1));	// 用来存放“数字”

	for (int i = 1; i <= x_str_size; ++i) {
		vv_num[i][0] = 0;
	}
	for (int j = 0; j <= y_str_size; ++j) {
		vv_num[0][j] = 0;
	}

	for (int i = 0; i < x_str_size; ++i) {
		for (int j = 0; j < y_str_size; ++j) {
			if (x_str[i] == y_str[j]) {
				vv_num[i + 1][j + 1] = vv_num[i][j] + 1;
			}
			else if (vv_num[i][j + 1] >= vv_num[i + 1][j]) {
				vv_num[i + 1][j + 1] = vv_num[i][j + 1];
			}
			else {
				vv_num[i + 1][j + 1] = vv_num[i + 1][j];
			}
		}
	}
	return vv_num[x_str_size][y_str_size];
}

// 解法二：直接在原问题上采用动态规划法
int longest_increasing_subsequence(const vector<int>& v_vec)
{
	int len = v_vec.size();
	int* lis = new int[len];
	for (int i = 0; i < len; ++i) {
		lis[i] = 1;
	}

	for (int i = 1; i < len; ++i) {
		for (int j = 0; j < i; ++j) {
			if (v_vec[i] <= v_vec[j] && lis[i] < lis[j] + 1) {
				lis[i] = lis[j] + 1;
			}
		}
	}

	int max = 0;
	for (int i = 0; i < len; ++i) {
		if (max < lis[i]) {
			max = lis[i];
		}
	}
	return max;
}

int main(int argc, char const *argv[])
{
	int n;
	vector<int> vec;
	while (cin >> n) {
		vec.push_back(n);
	}

	vector<int> svec(vec.begin(), vec.end());
	sort(svec.begin(), svec.end(), greater<int>());
	cout << lcs_length(vec, svec) << endl;
	cout << longest_increasing_subsequence(vec) << endl;
	return 0;
}