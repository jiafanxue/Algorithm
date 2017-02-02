/*
Question:
		Given a string containing just the characters '(', ')', '{', '}', '[' and ']'.determine if the
	input string is valid.
		The brackets must close in the correct order. "()" and "()[]{}" ara all valid but "(]" and "([)]"
	are not.
*/
#include <iostream>
#include <stack>
#include <string>
using namespace std;

class Solution
{
public:
	bool isValid(string s) {
		stack<char> mark;
		for(unsigned i = 0; i < s.size(); ++i) {
			// switch有所消耗，可以换成if-else用法
			switch(s[i]) {
				case '(':
				case '{':
				case '[':
					mark.push(s[i]);
					break;
				case ')':
					if(mark.empty() || mark.top() != '(') {
						return false;
					}
					else {
						mark.pop();
					}
					break;
				case ']':
					if(mark.empty() || mark.top() != '[') {
						return false;
					}
					else {
						mark.pop();
					}
					break;
				case '}':
					if(mark.empty() || mark.top() != '{') {
						return false;
					}
					else {
						mark.pop();
					}
					break;
			}
		}
		return mark.empty();
	}
};

int main(int argc, char const *argv[])
{
	string str;
	cin >> str;
	Solution su;
	if(su.isValid(str)) {
		cout << "Yes" << endl;
	}
	else {
		cout << "No" << endl;
	}
	return 0;
}