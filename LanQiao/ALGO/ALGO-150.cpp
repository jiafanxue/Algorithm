#include <iostream>
using namespace std;

int Binomial_coefficient(int k, int n)
{
	if(k == 0 || k == n) {
		return 1;
	}
	return Binomial_coefficient(k, n - 1) + Binomial_coefficient(k - 1, n - 1);
}

int main(int argc, char const *argv[])
{
	int k, n;
	cin >> k >> n;
	cout << Binomial_coefficient(k, n) << endl;
	return 0;
}