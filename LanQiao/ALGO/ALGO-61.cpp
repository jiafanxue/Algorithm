#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	int x;
	cin >> x;
	if(!(x % 2)) {
		cout << "even" << endl;
	}
	else {
		cout << "odd" << endl;
	}
	return 0;
}