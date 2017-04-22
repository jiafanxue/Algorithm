#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

// 解法一 ： 将问题转换为最长公共子序列问题
int lcs_length(const vector<int>& x_vec, const vector<int>& y_vec)
{
	int x_vec_size = x_vec.size();
	int y_vec_size = y_vec.size();
	vector<vector<int>> vv_num(x_vec_size + 1, vector<int>(x_vec_size + 1));

	for (int i = 1; i <= x_vec_size; ++i) {
		vv_num[i][0] = 0;
	}
	for (int i = 0; i <= y_vec_size; ++i) {
		vv_num[0][i] = 0;
	}

	for (int i = 0; i < x_vec_size; ++i) {
		for (int j = 0; j < y_vec_size; ++j) {
			if (x_vec[i] == y_vec[j]) {
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
	return vv_num[x_vec_size][y_vec_size];
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
	return 0;
}