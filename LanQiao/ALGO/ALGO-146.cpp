#include <iostream>
using namespace std;

bool find_gcd(int num)
{
	if(num % 11 == 0 && num % 17 == 0) {
		return true;
	}
	return false;
}

int main(int argc, char const *argv[])
{
	for(int i = 1; i <= 1000; ++i) {
		if(find_gcd(i)) {
			cout << i << endl;
		}
	}
	return 0;
}