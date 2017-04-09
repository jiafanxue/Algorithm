/*
	0-1背包问题
*/
#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>
using namespace std;

int memorized_oneZeroBackpack_aux(vector<std::pair<int, int>> commodity,
                                  int bag_capacity, int commodity_size,
                                  vector<vector<int>>& memorandum);
int memorized_oneZeroBackpack(vector<std::pair<int, int>> commodity, int bag_capacity)
{
	// memorandum[i][w] 表示物品为i，容量为w时，它的最大价值
	vector<vector<int>> memorandum(commodity.size() + 1, vector<int>(bag_capacity + 1, INT_MIN));
	return memorized_oneZeroBackpack_aux(commodity, bag_capacity, commodity.size(), memorandum);
}

int memorized_oneZeroBackpack_aux(vector<std::pair<int, int>> commodity,
                                  int bag_capacity, int commodity_size,
                                  vector<vector<int>>& memorandum)
{
	for (int w = 1; w <= bag_capacity; ++w) {
		memorandum[0][w] = 0;
	}

	for (int i = 1; i <= commodity_size; ++i) {
		memorandum[i][0] = 0;
		for (int w = 1; w <= bag_capacity; ++w) {
			if (commodity[i].second <= w) {
				if (commodity[i].first + memorandum[i - 1][w - commodity[i].second] > memorandum[i - 1][w]) {
					memorandum[i][w] = commodity[i].first + memorandum[i - 1][w - commodity[i].second];
				}
				else {
					memorandum[i][w] = memorandum[i - 1][w];
				}
			}
			else {
				memorandum[i][w] = memorandum[i - 1][w];
			}
		}
	}
	return memorandum[commodity_size][bag_capacity];
}

int main(int argc, char const *argv[])
{
	int n, m;
	cin >> n >> m;

	vector<int> w;
	vector<int> v;
	for (int i = 0; i < n; ++i) {
		int wi, vi;
		cin >> wi >> vi;
		w.push_back(wi);
		v.push_back(vi);
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n - 1; j++) {
			if ((double)(v[j]) / w[j] < (double)(v[j + 1]) / w[j + 1]) {
				std::swap(v[j], v[j + 1]);
				std::swap(w[j], w[j + 1]);
			}
		}
	}

	std::vector<std::pair<int, int>> commodity;
	commodity.push_back({0, 0});
	for (int i = 0; i < n; ++i) {
		pair<int, int> tmp(v[i], w[i]);
		commodity.push_back(tmp);
	}

	for(auto i : commodity) {
		cout << i.first << " " << i.second << " ";
	}
	cout << endl;

	cout << memorized_oneZeroBackpack(commodity, m) << endl;

	return 0;
}

