/*
Question:
	Fibonacci.
*/

#include <iostream>
using namespace std;


/*
			0, x <= 0
	F(n) =	1, x == 1
			F(n - 1) + F(n - 2), x > 1
*/
int Fibonacci_1(int n)
{
	if(n <= 0) {
		return 0;
	}
	else if(n == 1) {
		return 1;
	}
	else {
		return Fibonacci(n - 1) + Fibonacci(n - 2);
	}
}

int main()
{
	int n;
	cin >> n;
	cout << Fibonacci(n) << endl;
	return 0;
}