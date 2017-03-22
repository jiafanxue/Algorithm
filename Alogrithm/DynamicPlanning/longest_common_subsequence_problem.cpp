/*
	最长公共子序列问题
		给定两个序列X=<x1, x2, x3, ... , xn>和 Y=<y1, y2, y3, ... , yn>，求X和Y长度最长的公共子序列
*/
#include <algorithm>
#include <iostream>
#include <iterator>
#include <string>
#include <utility>
#include <vector>
using namespace std;

// 动态规划求解最长公共子序列问题
std::pair<vector<vector<int>>, vector<vector<char>>> lcs_length(const string& x_str, const string& y_str)
{
	int x_str_size = x_str.size();
	int y_str_size = y_str.size();

	vector<vector<int>> vv_num(x_str_size + 1, vector<int>(y_str_size + 1));	// 用来存放“数字”
	vector<vector<int>> vv_ch(x_str_size + 1, vector<int>(y_str_size + 1)); 	// 用来存放“箭头”

	for (int i = 1; i <= x_str_size; ++i) {
		vv_num[i][0] = 0;
		vv_ch[i][0] = ' ';
	}
	for (int j = 0; j <= y_str_size; ++j) {
		vv_num[0][j] = 0;
		vv_ch[0][j] = ' ';
	}

	for (int i = 0; i < x_str_size; ++i) {
		for (int j = 0; j < y_str_size; ++j) {
			if (x_str[i] == y_str[j]) {
				vv_num[i + 1][j + 1] = vv_num[i][j] + 1;
				vv_ch[i + 1][j + 1] = '1';
			}
			else if (vv_num[i][j + 1] >= vv_num[i + 1][j]) {
				vv_num[i + 1][j + 1] = vv_num[i][j + 1];
				vv_ch[i + 1][j + 1] = '2';
			}
			else {
				vv_num[i + 1][j + 1] = vv_num[i + 1][j];
				vv_ch[i + 1][j + 1] = '3';
			}
		}
	}
	return std::make_pair(vv_num, vv_ch);
}

void print_lcs(const vector<vector<char>>& vv_ch, const string& x_str, int i, int j)
{
	if (i == 0 || j == 0) {
		return;
	}
	if (vv_ch[i][j] == '1') {
		print_lcs(vv_ch, x_str, i - 1, j - 1);
		cout << x_str[i - 1];
	}
	else if (vv_ch[i][j] == '2') {
		print_lcs(vv_ch, x_str, i - 1, j);
	}
	else {
		print_lcs(vv_ch, x_str, i, j - 1);
	}
}

int main(int argc, char const *argv[])
{
	string x_str, y_str;
	cin >> x_str >> y_str;
	auto result = lcs_length(x_str, y_str);

	/*for (auto i : result.first) {
		for (auto j : i) {
			cout << j << ' ';
		}
		cout << endl;
	}*/

	print_lcs(result.second, x_str, x_str.size(), y_str.size());
	return 0;
}
