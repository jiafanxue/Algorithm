#include <iostream>
#include <string>
#include <cctype>
using namespace std;

void letter_output(string str)
{
	for(string::iterator i = str.begin(); i != str.end(); ++i) {
		*i = toupper(*i);
	} 
	cout << str << endl;
}

void lower_output(string str)
{
	for(string::iterator i = str.begin(); i != str.end(); ++i) {
		*i = tolower(*i);
	} 
	cout << str << endl;
}

void reverse_output(string str)
{
	for(string::reverse_iterator i = str.rbegin(); i != str.rend(); ++i) {
		cout << *i;
	} 
	cout << endl;
}

void contrary_output(string str)
{
	for(string::iterator i = str.begin(); i != str.end(); ++i) {
		if(isupper(*i)) {
			*i = tolower(*i);
		}
		else if(islower(*i)) {
			*i = toupper(*i);
		}
	} 
	cout << str << endl;
}

void substr_output(string str)
{
	for(string::iterator i = str.begin(); i != str.end(); ++i) {
		*i = tolower(*i);
	} 
	
	unsigned s = 0;
	while(s < str.size()) {
		unsigned j;
		for(j = s + 1; j < str.size(); ++j) {
			if(str[j] != str[j - 1] + 1) {
				break;
			}
		}
		--j;
		if(s == j || j == s + 1) {
			cout << str[s];
			s++;
			continue;
		}
		else {
			cout << str[s];
			cout << "-";
			cout << str[j];
			s = j + 1;
		}
	}
}

int main(int argc, char const *argv[])
{
	int n;
	string str;
	cin >> n >> str;

	switch(n) {
	case 1:
		letter_output(str);
		break;
	case 2:
		lower_output(str);
		break;
	case 3:
		reverse_output(str);
		break;
	case 4:
		contrary_output(str);
		break;
	case 5:
		substr_output(str);
		break;
	default:
		break;
	}
	return 0;
}