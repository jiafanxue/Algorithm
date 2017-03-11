#include <iostream>
#include <cmath>
using namespace std;

int main(int argc, char const *argv[])
{
	int bit, ten, hundred;
	for(int i = 100; i <= 999; ++i) {
		hundred = i / 100;
		ten = i / 10 % 10; 
		bit = i % 10;
		int result = pow(hundred, 3) + pow(ten, 3) + pow(bit, 3);
		if(result == i) {
			cout << result << endl;
		}
	}
	return 0;
}