/*
Question:
	Give two string s1 and s2 , and judge whether s2 can be cyclically shifted by s1 to get the string containing.
	e.g.
		s1 = AABCD
		s2 = CDAA
		return true;

		s1 = ABCD
		s2 = ACBD
		return false;
*/
#include <iostream>
#include <string>
using namespace std;

/*
	Answer one
*/
bool JudgeStringContain(string s1, string s2)
{
	int length_1 = s1.size();
	for(int i = 0; i < length_1; ++i) {
		char tempchar = s1[0];
		for(int j = 0; j < length_1 - 1; ++j) {
			s1[j] = s1[j + 1];
		}
		s1[length_1 - 1] = tempchar;
		string::size_type n = s1.find(s2);
		if(n != string::npos) {
			return true;
		}
	}
	return false;
}

int main(int argc, char const *argv[])
{
	string s1 = "AABCD";
	string s2 = "CDAA";

	if(JudgeStringContain(s1, s2)) {
		cout << "Yes" << endl;
	}
	else {
		cout << "No" << endl;
	}

	return 0;
}