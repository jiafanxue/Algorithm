#include <iostream>
using namespace std;

void MatrixMulti(int** c1, int** c2, int** c3, int m, int s, int n)
{
	for(int i = 0; i < m; ++i) {
		for(int j = 0; j < n; ++j) {
			int sum = 0;
			for(int k = 0; k < s; ++k) {
				sum += c1[i][k] * c2[k][j]; 
			}
			c3[i][j] = sum;
		}
	}

	for(int i = 0; i < m; ++i) {
		for(int j = 0; j < n; ++j) {
			cout << c3[i][j] << " ";
		}
		cout << endl;
	}
}

int main(int argc, char const *argv[])
{
	int m, s, n;
	cin >> m >> s >> n;

	int** c1 = new int*[m];
	int** c2 = new int*[s];
	int** c3 = new int*[m];
	for(int i = 0; i < m; ++i) {
		c1[i] = new int[s];
	}
	for(int i = 0; i < s; ++i) {
		c2[i] = new int[n];
	}
	for(int i = 0; i < m; ++i) {
		c3[i] = new int[n];
	}

	for(int i = 0; i < m; ++i) {
		for(int j = 0; j < s; ++j) {
			cin >> c1[i][j];
		}
	}

	for(int i = 0; i < s; ++i) {
		for(int j = 0; j < n; ++j) {
			cin >> c2[i][j];
		}
	}
	MatrixMulti(c1, c2, c3, m, s, n);
	return 0;
}