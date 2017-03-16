#include <iostream>
#include <cctype>
#include <algorithm>
#include <string>
using namespace std;

void DeleteStr(string& str, char ch)
{
	/*str.erase(
		remove_if(
			str.begin(), 
			str.end(), 
			[&](char x) { return x == ch; }), 
		str.end()
	);*/

	for(string::iterator iter = str.begin(); iter != str.end(); ) {
		if(*iter == ch) {
			iter = str.erase(iter);
			break;
		}
		++iter;
	}
}

void InsertStr(string& str, char ch1, char ch2)
{
	string::size_type pos = str.find_last_of(ch1);
	str.insert(pos, 1, ch2);
}

void ReplaceStr(string& str, char ch1, char ch2)
{
	bool flag = true;
	for(string::iterator iter = str.begin(); iter != str.end(); ++iter) {
		if(*iter == ch1) {
			*iter = ch2;
			flag = false;
		}
	}
	if(flag) {
		cout << "The ch1 is not exist" << endl;
	}
}


int main(int argc, char const *argv[])
{
	string str;
	getline(cin, str);
	char choice;
	cin >> choice;
	switch(choice) {
		case 'D':
		{
			char ch;
			cin >> ch;
			DeleteStr(str, ch);
			break;
		}
		case 'I':
		{
			char ch1, ch2;
			cin >> ch1 >> ch2;
			InsertStr(str, ch1, ch2);
			break;
		}
		case 'R':
		{
			char ch1, ch2;
			cin >> ch1 >> ch2;
			ReplaceStr(str, ch1, ch2);
			break;
		}
		default:
			break;
	}
	cout << str << endl;
	return 0;
}