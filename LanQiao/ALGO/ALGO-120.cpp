#include <iostream>
using namespace std;

int first_dishes(int& a, int& b, int& c, int& d)
{
	int number = 0;
	while(a >= 2 && b >= 1 && d >= 2) {
		++number;
		a -= 2;
		b -= 1;
		d -= 2;
	} 
	return number;
}

int second_dishes(int& a, int& b, int& c, int& d)
{
	int number = 0;
	while(a >= 1 && b >= 1 && c >= 1 && d >= 1) {
		++number;
		a -= 1;
		b -= 1;
		c -= 1;
		d -= 1;
	} 
	return number;
}

int third_dishes(int& a, int& b, int& c, int& d)
{
	int number = 0;
	while(c >= 2 && d >= 1) {
		++number;
		c -= 2;
		d -= 1;
	} 
	return number;
}

int four_dishes(int& a, int& b, int& c, int& d)
{
	int number = 0;
	while(b >= 3) {
		++number;
		b -= 3;
	} 
	return number;
}

int five_dishes(int& a, int& b, int& c, int& d)
{
	int number = 0;
	while(a >= 1 && d >= 1) {
		++number;
		a -= 1;
		d -= 1;
	} 
	return number;
}


int main(int argc, char const *argv[])
{
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	cout << first_dishes(a, b, c, d) << endl;
	cout << second_dishes(a, b, c, d) << endl;
	cout << third_dishes(a, b, c, d) << endl;
	cout << four_dishes(a, b, c, d) << endl;
	cout << five_dishes(a, b, c, d) << endl;
	return 0;
}