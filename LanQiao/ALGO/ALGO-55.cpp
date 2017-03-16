#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	int N, M;
	cin >> N >> M;
	int a[N][M];
	int b[N][M];
	for(int i = 0; i < N; ++i) {
		for(int j = 0; j < M; ++j) {
			cin >> a[i][j]; 
		}
	}
	for(int i = 0; i < N; ++i) {
		for(int j = 0; j < M; ++j) {
			cin >> b[i][j]; 
		}
	}
	for(int i = 0; i < N; ++i) {
		for(int j = 0; j < M; ++j) {
			cout << a[i][j] + b[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}