/*
Question:
	Write a program to find the greatest common divisor of two positive integers.（GCD)

	写一个程序，找两个正整数的最大公约数。
	
*/
#include <iostream>
using namespace std;

/*
	Answer 1
		辗转相除法。缺点是取模运算开销很大。
		f(x,y) = f(y,x%y)
*/
int gcd_1(int x, int y)
{
	if(y == 0) {
		return x;
	}
	return gcd_1(y, x % y); 
}

int gcd_2(int x, int y)
{
	return (!y) ? x : gcd_2(y, x % y);
}

/*
	Answer 2
		辗转相除法的拓展版本。缺陷就是明显增加了迭代的次数
		f(x, y) = f(x - y, y)
*/
int gcd_3(int x, int y)
{
	if(x < y) {
		return gcd_3(y, x);
	}
	if(x == y) {
		return x;
	}
	return gcd_3(x - y, y);
}

/*
	Answer 3
		f(x, y) = k*f(x1, y1)  =>   x = k * x1, y = k * x2 
		取：
			p = 2
			x,y均为偶数（even）：f(x, y) = 2 * f(x / 2, y / 2)
			x为偶数，y为奇数（odd）：f(x, y) = f(x / 2, y)
			x为奇数，y为偶数：f(x, y) = f(x, y / 2)
			x,y均为奇数：f(x, y) = f(y, x - y)
*/
int gcd_4(int x, int y)
{
	if(x < y) {
		return gcd_4(y, x);
	}
	if(y == 0) {
		return x;
	}
	else {
		if(x % 2 == 0) {
			if(y % 2 == 0) {
				return (gcd_4(x >> 1, y >> 1) << 1);
			}
			else {
				return gcd_4(x >> 1, y);
			}
		}
		else {
			if(y % 2 == 0) {
				return gcd_4(x, y >> 1);
			}
			else {
				return gcd_4(y, x - y);
			}
		}
	}
}

int main(int argc, char const *argv[])
{
	int x, y;
	cin >> x >> y;
	cout << gcd_1(x, y) << endl;
	cout << gcd_2(x, y) << endl;
	cout << gcd_3(x, y) << endl;
	cout << gcd_4(x, y) << endl;
	return 0;
}