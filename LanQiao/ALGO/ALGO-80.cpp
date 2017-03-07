#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	int n;
	cin >> n;
	int* a = new int[n];
	for(int i = 0; i < n; ++i) {
		cin >> a[i];
	}

	int sum = 0;
	for(int i = 0; i < n; ++i) {
		sum += a[i];
	}
	cout << sum / n << endl;
	return 0;
}