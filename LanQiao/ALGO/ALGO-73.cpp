#include <iostream>
#include <string>
using namespace std;

int main(int argc, char const *argv[])
{
	string str;
	cin >> str;
	int times = 0;
	string pattern = "0123456789";
	for(string::iterator i = str.begin(); i != str.end(); ++i) {
		if(pattern.find(*i) != std::string::npos) {
			++times;
		}
	}
	cout << times << endl;
	return 0;
}