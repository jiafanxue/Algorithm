/*
	分数背包问题
*/
#include <algorithm>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>
using namespace std;

// 贪心算法实现
// 此算法的前提是价值高的在前面，价值低的在后面
// 例如 : price = {120, 100, 60}
//		  weight = {30, 20, 10}
// 会失效
int fractional_knapsack(const vector<int>& prices,
                        const vector<int>& weights,
                        int bag_capacity)
{
	int valueSum = 0;
	int capacitySum = 0;
	for(unsigned i = 0; i < prices.size(); ++i) {
		if(weights[i] + capacitySum >= bag_capacity) {
			valueSum += (bag_capacity - capacitySum) * (prices[i] / weights[i]);
			return valueSum;
		}
		valueSum += prices[i];
		capacitySum += weights[i];
	}
	return valueSum;
}

int main(int argc, char const *argv[])
{
	// std::vector<std::pair<int, int>> 存储是不是更好？
	vector<int> commodity_price = {60, 100, 120};
	vector<int> commodity_weight = {10, 20, 30};
	int bag_capacity = 50;
	cout << fractional_knapsack(commodity_price, commodity_weight, bag_capacity) << endl;
	return 0;
}