#include <iostream>
using namespace std;

int main()
{
	long long n, max;
	cin >> n;
	if(n <= 2) {
		max = n;
	}
	else if(n % 2 == 1) {
		max = n * (n - 1) * (n - 2);
	}
	else {
		if(n % 3 == 0) {
			max = (n - 1) * (n - 2) * (n - 3);
		}
		else {
			max = n * (n - 1) * (n - 3);
		}
	}
	cout << max << endl;
	return 0;
}