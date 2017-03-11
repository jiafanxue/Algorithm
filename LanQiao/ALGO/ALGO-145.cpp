#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	int n;
	cin >> n;

	for(int i = 1; i <= n; ++i) {
		for(int j = 0; j < n - i; ++j) {
			cout << " ";
		}
		for(int k = 0; k < 2 * (i - 1) + 1; ++k) {
			cout << "*";
		}
		cout << endl;
	}
	return 0;
}