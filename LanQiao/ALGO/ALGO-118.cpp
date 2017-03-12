#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	int num;
	cin >> num;

	for(int i = 1; i < num; ++i) {
		int sum = i;
		for(int j = i + 1; j < num; ++j) {
			sum += j;
			if(sum == num) {
				cout << i << " " << j << endl;
			}
		}
	}
	return 0;
}