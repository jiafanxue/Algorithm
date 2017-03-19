#include <algorithm>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>
using namespace std;

int main(int argc, char const *argv[])
{
	string str;
	cin >> str;

	char ch;
	cin >> ch;

	for (string::iterator i = str.begin(); i != str.end(); ) {
		if (*i == ch) {
			i = str.erase(i);
		}
		else {
			++i;
		}
	}

	cout << str << endl;

	return 0;
}