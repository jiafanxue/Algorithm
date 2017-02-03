#include <iostream>
#include <iomanip>
using namespace std;

struct plural
{
	double a;
	double b;
};

void add_plural(plural p1, plural p2, plural& tmp)
{
	tmp.a = p1.a + p2.a;
	tmp.b = p2.a + p2.b;
}

void sub_plural(plural p1, plural p2, plural& tmp)
{
	tmp.a = p1.a - p2.a;
	tmp.b = p1.b - p2.b;
}

void mul_plural(plural p1, plural p2, plural& tmp)
{
	tmp.a = p1.a * p2.a - p1.b * p2.b;
	tmp.b = p1.b * p2.a + p1.a * p2.b;
}

plural div_plural(plural p1, plural p2)
{
	plural tmp;
	tmp.a = (p1.a * p2.a + p1.b * p2.b) / (p2.a * p2.a + p2.b * p2.b);
	tmp.b = (p1.b * p2.a - p1.a * p2.b) / (p2.a * p2.a + p2.b * p2.b);
	return tmp;
}

void print_plural(char ch, plural p1, plural p2)
{
	plural tmp;
	if(ch == '+') {
		add_plural(p1, p2, tmp);

	}
	else if(ch == '-') {
		sub_plural(p1, p2, tmp);
	}
	else if(ch == '*') {
		mul_plural(p1, p2, tmp);
	}
	else if(ch == '/') {
		tmp = div_plural(p1, p2);
	}
	cout << fixed << setprecision(2) << tmp.a << "+" << tmp.b << "i" << endl;
}

int main(int argc, char const *argv[])
{
	plural p1, p2;
	char ch;
	cin >> ch >> p1.a >> p1.b >> p2.a >> p2.b;
	print_plural(ch, p1, p2);
	return 0;
}