/*
	打印十字图
*/
#include <iostream>
using namespace std;

void PrintCrossFigure(int n)
{
	int x, y;
	x = y = 9 + 4 * (n - 1);
	int center = (x - 1) / 2;
	char arr[x][y];
	for(int i = 0; i < x; ++i) {
		for(int j = 0; j < y; ++j) {
			arr[i][j] = '.';
		}
	}

	//摆放中心十字图
	for(int i = center - 1; i <= center; ++i) {
		arr[center][i] = '$';
		arr[i][center] = '$';
	}

	// 打印A区域,C区域
	int space = center;
	int t = 1;
	int num_s = 1;
	for(int i = center - 2; i >= 0; i -= 2) {
		for(int j = space; t > 0; ++j) {
			arr[i][j] = '$';
			arr[j][i] = '$';
			--t;
		}
		space -= 2;
		t = num_s += 2;
	}

	// 打印B区域
	for(int i = 1; i < center - 1; i += 2) {
		arr[i][i + 1] = '$';
	}

	for(int i = 2; i < center; i += 2) {
		arr[i][i] = '$';
	}

	for(int i = 2; i < center - 1; i += 2) {
		arr[i][i - 1] = '$';
	}

	// 对角线复制
	for(int i = 0; i < (x + 1) / 2; ++i) {
		for(int j = 0; j < (y + 1) / 2; ++j){
			arr[x - i - 1][y - j - 1] = arr[i][j];
		}
	}

	// 列中线复制
	for(int i = 0; i < (x + 1) / 2; ++i) {
		for(int j = 0; j < (y + 1) / 2; ++j){
			arr[i][y - j - 1] = arr[i][j];
		}
	}

	// 行中线复制
	for(int i = 0; i < (x + 1) / 2; ++i) {
		for(int j = 0; j < (y + 1) / 2; ++j){
			arr[x - i - 1][j] = arr[i][j];
		}
	}

	for(int i = 0; i < x; ++i) {
		for(int j = 0; j < y; ++j) {
			cout << arr[i][j];
		}
		cout << endl;
	}
}

int main(int argc, char const *argv[])
{
	int n;
	cin >> n;
	PrintCrossFigure(n);
	return 0;
}