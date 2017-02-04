#include <iostream>
#include <string>
using namespace std;

void conversion(string& str)
{
	char ch;
	for(unsigned i = 0; i < str.size(); ++i) {
		if(str[i] >= 'a' && str[i] <= 'z') {
			ch = str[i];
			ch -= 32;
			str[i] = ch;
		}
		else if(str[i] >= 'A' && str[i] <= 'Z') {
			ch = str[i];
			ch += 32;
			str[i] = ch;
		}
		else {
			continue;
		}
	}
}

int main(int argc, char const *argv[])
{
	string str;
	cin >> str;
	conversion(str);
	cout << str;	
	return 0;
}