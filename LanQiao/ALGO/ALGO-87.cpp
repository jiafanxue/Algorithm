#include <iostream>
#include <string>
using namespace std;

void FindSubString(string str, int L)
{
	int len = 0;
	int Max_index = 0;
	for(unsigned i = 0; i < str.size() - L + 1; ++i) {
		string pattern = str.substr(i, L);
		int tmplen = 0;
		for(unsigned j = i + 1; j < str.size() - L + 1; ++j) {
			string tmp = str.substr(j, L);
			if(!pattern.compare(tmp)) {
				tmplen++;
			}
		}
		if(tmplen > len) {
			len = tmplen;
			Max_index = i;
		}
	}
	cout << str.substr(Max_index, L) << endl;
}

int main(int argc, char const *argv[])
{
	int L;
	cin >> L;
	string str;
	cin >> str;
	FindSubString(str, L);
	return 0;
}