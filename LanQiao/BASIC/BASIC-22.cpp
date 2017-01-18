#include <iostream>
#include <string>
using namespace std;

string FJprint(int n)
{
	if(n == 1) {
		return "A";
	}
	return FJprint(n - 1) + char(n + 'A' - 1) + FJprint(n - 1);
}

int main()
{
	int n;
	cin >> n;
	cout << FJprint(n) << endl;
	return 0;
}