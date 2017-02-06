#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(int argc, char const *argv[])
{
	// int n;
	// while(cin >> n) {
	// 	// 数据输入
	// 	vector<vector<int>> d(n, vector<int>(n));
	// 	for(int i = 0; i < n; ++i) {
	// 		for(int j = 0; j <= i; ++j) {
	// 			cin >> d[i][j];
	// 		}
	// 	}

	// 	// 初始化f数组
	// 	vector<vector<int>> f(n, vector<int>(n));
	// 	for(int i = 0; i < n; ++i) {
	// 		for(int j = 0; j < n; ++j) {
	// 			f[i][j] = 0;
	// 		}
	// 	}
	// 	f[0][0] = d[0][0];

	// 	// 从上往下迭代计算 - 标准动态规划
	// 	for(int i = 0; i < n - 1; ++i) {
	// 		for(int j = 0; j <= i; ++j) {
	// 			f[i + 1][j] = max(f[i + 1][j], f[i][j] + d[i + 1][j]);
	// 			f[i + 1][j + 1] = max(f[i + 1][j + 1], f[i][j] + d[i + 1][j + 1]);
	// 		}
	// 	}

	// // 	sort(f[n - 1].begin(), f[n - 1].end());
	// // 	cout << f[n - 1][n - 1] << endl;
	// }

	int n;
	cin >> n;
	int** d = new int*[n];
	for(int i = 0; i < n; ++i) {
		d[i] = new int[n];
	}

	for(int i = 0; i < n; ++i) {
		for(int j = 0; j <= i; ++j) {
			cin >> d[i][j];
		}
	}

	int** f = new int*[n];
	for(int i = 0; i < n; ++i) {
		f[i] = new int[n];
	}

	for(int i = 0; i < n; ++i) {
		for(int j = 0; j <= i; ++j) {
			f[i][j] = 0;
		}
	}

	f[0][0] = d[0][0];

	for(int i = 0; i < n - 1; ++i) {
		for(int j = 0; j <= i; ++j) {
			f[i + 1][j] = max(f[i + 1][j], f[i][j] + d[i + 1][j]);
			f[i + 1][j + 1] = max(f[i + 1][j + 1], f[i][j] + d[i + 1][j + 1]);
		}
	}

	sort(f[n - 1], f[n - 1] + n);

	cout << f[n - 1] << endl;
	return 0;
}