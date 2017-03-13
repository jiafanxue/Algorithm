#include <iostream>
using namespace std;

bool friend_number(int n1, int n2)
{
	int n1_sum = 0;
	for(int i = 1; i < n1; ++i) {
		if(n1 % i == 0) {
			n1_sum += i;
		}
	}
	int n2_sum = 0;
	for(int i = 1; i < n2; ++i) {
		if(n2 % i == 0) {
			n2_sum += i;
		}
	}
	if(n2_sum == n1 && n1_sum == n2) {
		return true;
	}
	return false;
}

int main(int argc, char const *argv[])
{
	int n1, n2;
	cin >> n1 >> n2;
	if(friend_number(n1, n2)) {
		cout << "yes" << endl;
	}
	else {
		cout << "no" << endl;
	}
	return 0;
}