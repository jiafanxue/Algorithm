#include <iostream>
#include <stack>
#include <string>
#include <cstdlib>
using namespace std;

void Calcurlate_add(string* prefix)
{
	cout << atoi(prefix[1].c_str()) + atoi(prefix[2].c_str()) << endl;
}

void Calcurlate_sub(string* prefix)
{
	cout << atoi(prefix[1].c_str()) - atoi(prefix[2].c_str()) << endl;
}

void Calcurlate_mul(string* prefix)
{
	cout << atoi(prefix[1].c_str()) * atoi(prefix[2].c_str()) << endl;
}

void Calcurlate_div(string* prefix)
{
	cout << atoi(prefix[1].c_str()) / atoi(prefix[2].c_str()) << endl;
}

void Calcurlate(string* prefix)
{
	if(prefix[0] == "+") {
	  	Calcurlate_add(prefix);
	}
	else if(prefix[0] == "-") {
		Calcurlate_sub(prefix);
	}
	else if(prefix[0] == "*") {
		Calcurlate_mul(prefix);
	}
	else if(prefix[0] == "/") {
		Calcurlate_div(prefix);
	}
}

int main(int argc, char const *argv[])
{
	string prefix[3];
	for(int i = 0; i < 3; ++i) {
		cin >> prefix[i];
	}
	Calcurlate(prefix);
	return 0;
}