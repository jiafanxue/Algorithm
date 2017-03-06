#include <iostream>
#include <cmath>
using namespace std;

int main(int argc, char const *argv[])
{
	int k;
	cin >> k;
	cout << (int)(pow(2, k) - k - 1) * 2 << endl;
	return 0;
}