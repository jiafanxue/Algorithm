/*
	钢条切割问题：
		某公司购买了长钢条板，将其切割为短钢条出售。价格表如下：

			长度：	1 ---- 2 ---- 3 ---- 4 ---- 5 ----  6 ----  7 ----  8 ----  9 ----  10
			价格：	1 ---- 5 ---- 8 ---- 9 ---- 10 ---- 17 ---- 17 ---- 20 ---- 24 ---- 30

		问题：给定长度为n的钢条和一个价格表，求切割方案，使得销售收益最大？
*/
#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>
using namespace std;

// 自顶向下递归实现
// 效率相当差：T(n) = 2^n
// 导致效率很差的原因是因为它反复求解相同的子问题
int cut_rod(const vector<int>& price_list, int steel_length)
{
	if (steel_length == 0) {
		return 0;
	}
	int max_profit = INT_MIN;
	for (int i = 0; i < steel_length; ++i) {
		max_profit = std::max(max_profit,
		                      price_list[i] + cut_rod(price_list, steel_length - i - 1));
	}
	return max_profit;
}

// 动态规划求解
// 方法一：带备忘录的自顶向下法
int memorized_cut_rod_aux(const vector<int>&, int, vector<int>&);
int memorized_cut_rod(const vector<int>& price_list, int steel_length)
{
	// 备忘录
	vector<int> memorandum(steel_length + 1, INT_MIN);
	return memorized_cut_rod_aux(price_list, steel_length, memorandum);
}

int memorized_cut_rod_aux(const vector<int>& price_list, int steel_length, vector<int>& memorandum)
{
	if (memorandum[steel_length] >= 0) {
		return memorandum[steel_length];
	}

	int max_profit = INT_MIN;
	if (steel_length == 0) {
		max_profit = 0;
	}
	else {
		for (int i = 0; i < steel_length; ++i) {
			max_profit = std::max(max_profit,
			                      price_list[i] + memorized_cut_rod_aux(price_list, steel_length - i - 1, memorandum));
		}
	}
	memorandum[steel_length] = max_profit;
	return max_profit;
}

// 方法二：自底向上法
int bottom_up_cut_rod(const vector<int>& price_list, int steel_length)
{
	int * memorandum = new int[steel_length + 1];
	memorandum[0] = 0;
	for (int i = 1; i < steel_length; ++i) {
		int max_profit = INT_MIN;
		for (int j = 1; j < i; ++j) {
			max_profit = std::max(max_profit, price_list[j] + memorandum[i - j]);
		}
		memorandum[i] = max_profit;
	}
	return memorandum[steel_length];
}

int main(int argc, char const *argv[])
{
	vector<int> price_list = {1, 5, 8, 9, 10, 17, 17, 20, 24, 30};
	int steel_length;
	cin >> steel_length;
	// 自顶向下递归法
	cout << cut_rod(price_list, steel_length) << endl;
	// 自顶向下动态规划法
	cout << memorized_cut_rod(price_list, steel_length) << endl;
	// 自底向上动态规划法
	cout << bottom_up_cut_rod(price_list, steel_length) << endl;
	return 0;
}
