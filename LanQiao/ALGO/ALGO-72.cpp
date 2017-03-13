#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	int t;
	cin >> t;
	if(t >= 90 && t <= 100) {
		cout << "A" << endl;
	}
	else if(t >= 80 && t < 90) {
		cout << "B"	<< endl;
	}
	else if(t >= 70 && t< 80) {
		cout << "C" << endl;
	}
	else if(t >= 60 && t < 70) {
		cout << "D" << endl;
	}
	else {
		cout << "E" << endl;
	}
	return 0;
}