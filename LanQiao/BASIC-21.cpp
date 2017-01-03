#include <iostream>
#include <string>
#include <cmath>
#include <sstream>
using namespace std;

string itos(int i) // 将int 转换成string
{
    stringstream s;
    s << i;
    return s.str();
}

string An(int n, int i)
{
	if(n == 1) {
		return "sin(1)"; 
	}
	if(i == n) {
		return itos(n);
	}
	int t = ++i;
	return "sin(" + (i < n ? itos(i) : "") + (i < n ? (i % 2 == 1? "-" : "+") : "") + An(n, t) + ")";
}

string SinePrint(int n, int i)
{
	if(n == 1) {
		return An(n, 0) + "+" + itos(++i);
	}
	int t = ++i;
	return "(" + SinePrint((n - 1), i) + ")" + An(n, 0) + "+" + itos(t);
}

int main()
{
	int n;
	cin >> n;
	cout << SinePrint(n, 0) << endl;
	return 0;
}