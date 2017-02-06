#include <iostream>
using namespace std;

string pow2Print(int num)
{
	if(num == 1) {
		return " 2(0)";
	}
	while(num) {
		if(num % 2 == 1) {
			return pow2Print(num % 2);
		}
		num /= 2;
	}
}

int main(int argc, char const *argv[])
{
	int num;
	cin >> num;
	cout << pow2Print(num);
	return 0;
}