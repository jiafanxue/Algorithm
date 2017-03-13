#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	string str = "aeiou";
	string s;
	cin >> s;
	for(unsigned i = 0; i < s.size(); ++i) {
		std::string::size_type n = str.find(s[i]);
		if(n != std::string::npos) {
			cout << i + 1 << endl;
			break;
		}
		if(i == s.size() - 1) {
			cout << 0 << endl;
		}
	}
	return 0;
}