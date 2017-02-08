#include <iostream>
#include <stack>
using namespace std;

void pow2Print(int num, int deep)
{
	stack<int> s;
	int cnt = 0;
	while(num) {
		if(num % 2 == 1) {
			s.push(cnt);
		}
		cnt++;
		num /= 2;
	}

	int flag = 0;
	while(!s.empty()) {
		if(flag == 0) {
			flag = 1;
		}
		else {
			cout << "+";
		} 

		if(s.top() == 1) {
			cout << "2";
		}
		else if(s.top() == 2) {
			cout << "2(2)";
		}
		else if(s.top() == 0) {
			cout << "2(0)";
		}
		else {
			cout << "2(";
			pow2Print(s.top(), deep + 1);
		}
		s.pop();
	}

	if(deep != 0) {
		cout << ")";
	}
}

int main(int argc, char const *argv[])
{
	int num;
	cin >> num;
	pow2Print(num, 0);
	return 0;
}