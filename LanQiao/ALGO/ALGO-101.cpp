#include <iostream>
using namespace std;

void printGrapical(int n)
{
	if(n <= 0) {
		return;
	}
	if(n == 1) {
		cout << "*" << endl;
		return;
	}

	for(int i = 0; i < n; ++i) {
		cout << "*" << " ";
	}
	cout << endl;

	printGrapical(n - 1);
}

int main(int argc, char const *argv[])
{
	int n;
	cin >> n;
	printGrapical(n);
	return 0;
}