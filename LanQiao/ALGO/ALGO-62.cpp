#include <iostream>
#include <cmath>
using namespace std;

int main(int argc, char const *argv[])
{
	int a, m;
	cin >> a >> m;
	double res = pow(a, 2);
	cout << (int)res % m << endl;
	return 0;
}