#include <iostream>
#include <cctype>
using namespace std;

int main(int argc, char const *argv[])
{
	char ch;
	cin >> ch;
	if(isupper(ch)) {
		cout << "upper" << endl;
	}
	else {
		cout << "lower" << endl;
	}
	return 0;
}