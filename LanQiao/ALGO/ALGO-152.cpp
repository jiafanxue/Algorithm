#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	int sum = 0;
	for(int k = 2; k <= 9999; ++k) {
		sum = 0;
		for(int j = 1; j < k; ++j) {
			if(k % j == 0) {
				sum += j;
			}
		}

		if(sum == k) {
			cout << k << endl;
		}
	}
	return 0;
}