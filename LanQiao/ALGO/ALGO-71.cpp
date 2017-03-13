#include <iostream>
#include <string>
using namespace std;

int main(int argc, char const *argv[])
{
	string s1, s2;
	cin >> s1 >> s2;
	for(string::iterator i = s1.begin(), j = s2.begin(); i != s1.end() && j != s2.end(); ++i, ++j) {
		if(*i != *j) {
			cout << *i - *j << endl;
			break;
		}
		if((i == s1.end() -1) && (j == s2.end() - 1) && *i == *j) {
			cout << 0 << endl;
			break;
		}
	}
	return 0;
}
