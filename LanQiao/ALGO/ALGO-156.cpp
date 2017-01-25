#include <iostream>
#include <string>
#include <cstdlib>
#include <stack>
#include <map>
using namespace std;

void InfixToPostfix(const string infix, string& postfix)
{
	stack<char> mark;					// 符号栈

	map<char, int> priority;
	priority['+'] = 0;
	priority['-'] = 0;
	priority['*'] = 1;
	priority['/'] = 1;

	int infix_length = infix.size();
	postfix.reserve(infix_length);
	for(int i = 0; i < infix_length; ++i) {
		switch(infix[i]) {
			case '0':
			case '1':
			case '2':
			case '3':
			case '4':
			case '5':
			case '6':
			case '7':
			case '8':
			case '9':
				postfix.push_back(infix[i]);
				break;
			case '+':
			case '-':
			case '*':
			case '/':
				if(infix[i - 1] != ')') {
					postfix.push_back('#');
				}
				if(!mark.empty()) {
					char markTop = mark.top();
					while(markTop != '(' && priority[infix[i]] <= priority[markTop]) {
						postfix.push_back(markTop);
						mark.pop();
						if(mark.empty()) {
							break;
						}
						markTop = mark.top();
					}
				}
				mark.push(infix[i]);
				break;
			case '(':
				if(infix[i - 1] >= '0' && infix[i - 1] <= '9') {
				postfix.push_back('#');
					mark.push('*');
				}
				mark.push(infix[i]);
				break;
			case ')':
			{
				if(infix[i - 1] != ')') {
					postfix.push_back('#');
				}
				char markTop = mark.top();
				while(markTop != '(') {
					postfix.push_back(markTop);
					mark.pop();
					markTop = mark.top();
				}
				mark.pop();
			}
				break;
			default:
				break;
			}
		}

	if(infix[infix_length - 1] != ')') {
		postfix.push_back('#');
	}
	while(!mark.empty()) {
		postfix.push_back(mark.top());
		mark.pop();
	}
}

float postfixComput(string postfix)
{
	stack<float> tempResult;
	string strNum;
	float currNum = 0;
	float tempNum = 0;

	for(string::iterator i = postfix.begin(); i != postfix.end(); ++i) {
		switch(*i) {
			case '0':
			case '1':
			case '2':
			case '3':
			case '4':
			case '5':
			case '6':
			case '7':
			case '8':
			case '9':
				strNum.push_back(*i);
				break;
			case '+':
				tempNum = tempResult.top();
				tempResult.pop();
				tempNum += tempResult.top();
				tempResult.pop();
				tempResult.push(tempNum);
				break;
			case '-':
				tempNum = tempResult.top();
				tempResult.pop();
				tempNum = tempResult.top() - tempNum;
				tempResult.pop();
				tempResult.push(tempNum);
				break;
			case '*':
				tempNum = tempResult.top();
				tempResult.pop();
				tempNum *= tempResult.top();
				tempResult.pop();
				tempResult.push(tempNum);
				break;
			case '/':
				tempNum = tempResult.top();
				tempResult.pop();
				tempNum = tempResult.top() / tempNum;
				tempResult.pop();
				tempResult.push(tempNum);
				break;
			case '#':
				currNum = stof(strNum);		// c++11
				strNum.clear();
				tempResult.push(currNum);
				break;
		}
	}
	return tempResult.top();
}

void Calculate(string infix)
{
	string postfix;
	InfixToPostfix(infix, postfix);
	cout << postfixComput(postfix) << endl;
}

int main(int argc, char const *argv[])
{
	string infix;
	cin >> infix;
	Calculate(infix);
	return 0;
}