/*
Question:
	Accurately express floating point numbers.
	e.g.
		0.9 = 9/10
		0.333(3) = 1/3
	Give a finite or infinite decimal, return the fraction with the smallest denominator of the fraction.
	llke. 0.3, 0.30, 0.3(000), 0.3333(3333), ......
*/
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <string>
using namespace std;

/*
	number = 0.a1a2a3...an(b1b2b3...bm)
	X = ((a1a2a3...an) * (10^m - 1) + (b1b2b3...bm)) / ((10^m - 1) * 10^n)
	  = A / B
	
	A = (a1a2a3...an) * (10^m - 1) + (b1b2b3...bm))
	B = (10^m - 1) * 10^n
	
	X = (A/Gcd(A,B)) / (B/Gcd(A,B))
*/
void accurate_express_float(string s)
{
	string search_str_point = std::string(".");
	string search_str_brackets_left = std::string("(");
	string search_str_brackets_right = std::string(")");

	string str_A_a;
	string str_A_b;
	int iPoint = s.find_first_of(search_str_point);
	int iBracketLeft = s.find_first_of(search_str_brackets_left);
	int iBracketRight = s.find_first_of(search_str_brackets_right);

	int size_s = s.size();
	double istr_A;
	double istr_B;
	if(iBracketLeft != -1 && iBracketRight != -1) {
		int size_a = iBracketLeft - iPoint - 1;
		int size_b = iBracketRight - iBracketLeft - 1;
		str_A_a = s.substr(iPoint + 1, size_a);
		str_A_b = s.substr(iBracketLeft + 1, size_b);
		istr_A = (atoi(str_A_a.c_str()) * (pow(10, size_b) - 1) + atoi(str_A_b.c_str()));
		istr_B = (pow(10, size_b) - 1) * pow(10, size_a);
		cout << istr_A << "/" << istr_B << endl;
	}
	else {
		int size_a = size_s - iPoint - 1;
		str_A_a = s.substr(iPoint + 1, size_a);
		istr_A = atoi(str_A_a.c_str());
		istr_B = pow(10, size_a);
		cout << istr_A << "/" << istr_B << endl;
	}
}

int main(int argc, char const *argv[])
{
	string s;
	cin >> s;
	accurate_express_float(s);
	return 0;
}