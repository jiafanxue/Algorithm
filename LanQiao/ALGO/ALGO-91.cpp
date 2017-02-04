#include <iostream>
using namespace std;

bool IsAnagrams(string str1, string str2)
{
	int arr[200];
	for(int i = 0; i < 200; ++i) {
		arr[i] = 0;
	}

	for(unsigned i = 0; i < str1.size(); ++i) {
		int lc1 = tolower(static_cast<unsigned char>(str1[i]));
		arr[lc1]++;
	}

	for(unsigned i = 0; i < str2.size(); ++i) {
		int lc2 = tolower(static_cast<unsigned char>(str2[i]));
		arr[lc2]--;
	}

	for(int i = 0; i < 200; ++i) {
		if(arr[i] != 0) {
			return false;
		}
	}
	return true;
}

int main(int argc, char const *argv[])
{
	string str1;
	string str2;
	cin >> str1 >> str2;
	if((str1.size() == str2.size()) && IsAnagrams(str1, str2)) {
		cout << "Y" << endl;
	}
	else {
		cout << "N" << endl;
	}
	return 0;
}