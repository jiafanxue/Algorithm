#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long dp[16][16] = {0};				// dp[i][j]表示前i个数中有j个乘号的最大值】
int sum[16] = {0};						// sum[i]表示前i个数之和

int main(int argc, char const *argv[])
{
	int N, K, t;
	cin >> N >> K;
	int num[16];
	for(int i = 1; i <= N; ++i) {
		cin >> num[i];
		sum[i] = sum[i - 1] + num[i];
	}

	for(int i = 1; i <= N; ++i) {
		dp[i][0] = sum[i];
	}

	//dp
	for(int i = 2; i <= N; ++i) {
		t = min(i - 1, K);
		for(int j = 1; j <= t; ++j) {
			for(int k = 2; k <= i; ++k) {	// k 为乘号所在位置
				dp[i][j] = max(dp[i][j], dp[k - 1][j - 1] * (sum[i] - sum[k - 1]));
			}
		}
	}
	cout << dp[N][K] << endl;
	return 0;
}