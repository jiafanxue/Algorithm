#include <iostream>
#include <string>
using namespace std;

int main(int argc, char const *argv[])
{
	string str;
	cin >> str;
	for(string::reverse_iterator iter = str.rbegin(); iter != str.rend(); ++iter) {
		cout << *iter;
	}	
	cout << endl;
	return 0;
}