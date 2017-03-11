#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	int num;
	cin >> num;
	int count = 0;
	while(num) {
		num /= 2;
		++count;
	}
	cout << count << endl;
	return 0;
}