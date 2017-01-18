#include <iostream>
#include <string>
using namespace std;

int Selection(string str1, string str2)
{
	bool boolen = true;
	int type;
	int str1_length = str1.size();
	int str2_length = str2.size();
	if(str1_length != str2_length) {
		return 1;
	}
	else {
		for(int i = 0; i < str1_length; ++i) {
			if(str1[i] != str2[i]) {
				if(((str1[i] & 0xDF) == str2[i]) || (str1[i] == (str2[i] & 0xDF))) {
					boolen = false;
					type = 3;
				}
				else {
					type = 4;
					break;
				}
			}
			if((i == str1_length - 1) && boolen) {
				type = 2;
			}
		}
	}
	return type;
}

int main()
{
	string str1, str2;
	cin >> str1;
	cin >> str2;
	cout << Selection(str1, str2) << endl;
	return 0;
}