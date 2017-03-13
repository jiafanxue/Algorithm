#include <iostream>
using namespace std;

int Factorial_not_zero(int num)
{
	int sum = 1;
	for(int i = num; i >= 1; --i) {
		sum = sum * i;
		while(sum % 10 == 0) {
			sum /= 10;
		}
		if(sum /100 > 0) {
			sum %= 100;
		}
	}
	return sum % 10;
}

int main(int argc, char const *argv[])
{
	int num;
	cin >> num;
	cout << Factorial_not_zero(num) << endl;
	return 0;
}