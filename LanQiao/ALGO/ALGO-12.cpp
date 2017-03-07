#include <iostream>
#include <stack>
using namespace std;

void Power_side_decomposition(int n, int deep)
{
	stack<int> s;
	int cnt = 0;
	while(n) {
		if(n % 2 == 1) {
			s.push(cnt);
		}
		cnt++;
		n /= 2;
	}

	int flag = 0;
	while(!s.empty()) {
		if(flag == 0) {
			flag = 1;
		}
		else {
			cout << "+";
		}

		if(s.top() == 0) {
			cout << "2(0)";
		}
		else if(s.top() == 1) {
			cout << "2";
		}
		else if(s.top() == 2) {
			cout << "2(2)";
		}
		else {
			cout << "2(";
			Power_side_decomposition(s.top(), deep + 1);
		}
		s.pop();
	}

	if(deep != 0) {
		cout << ")";
	}
}

int main(int argc, char const *argv[])
{
	int n;
	cin >> n;
	Power_side_decomposition(n, 0);
	cout << endl;
	return 0;
}