#include <iostream>
#include <algorithm>
using namespace std;

int find_number_nth(int* array, int length, int ix, int** lrk)
{
	int* a = new int[lrk[ix][1] - lrk[ix][0] + 1];
	for(int i = 0; i < lrk[ix][1] - lrk[ix][0] + 1; ++i) {
		a[i] = array[lrk[ix][0] + i - 1];
	}

	sort(a, a + lrk[ix][1] - lrk[ix][0] + 1);
	int num = a[lrk[ix][1] - lrk[ix][0] - lrk[ix][2] + 1];
	return num;
}

void Interval_k_large_query(int* array, int length, int m, int** lrk)
{
	int* c_arr = new int[m];
	for(int i = 0; i < m; ++i) {
		c_arr[i] = find_number_nth(array, length, i, lrk);
	}

	for(int i = 0; i < m; ++i) {
		cout << c_arr[i] << endl;
	}
}

int main(int argc, char const *argv[])
{
	int length;
	cin >> length;

	int* array = new int[length];
	for(int i = 0; i < length; ++i) {
		cin >> array[i];
	}

	int m;
	cin >> m;

	int** lrk = new int*[m];
	for(int i = 0; i < m; ++i) {
		lrk[i] = new int[3];
		for(int j = 0; j < 3; ++j) {
			cin >> lrk[i][j];
		}
	}

	Interval_k_large_query(array, length, m, lrk);

	return 0;
}