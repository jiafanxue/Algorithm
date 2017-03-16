#include <iostream>
#include <cctype>
using namespace std;

int main(int argc, char const *argv[])
{
	char str;
	cin >> str;
	if(isdigit(str)) {
		cout << "yes" << endl;
	}
	else {
		cout << "no" << endl;
	}
	return 0;
}