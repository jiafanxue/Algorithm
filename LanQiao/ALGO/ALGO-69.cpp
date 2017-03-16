#include <iostream>
#include <string>
using namespace std;

int main(int argc, char const *argv[])
{
	string str;
	cin >> str;
	for(string::reverse_iterator i = str.rbegin(); i != str.rend(); ++i) {
		cout << *i;
	}
	cout << endl;
	return 0;
}