#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	double x;
	while((cin >> x) && (x >= 0.01) && (x <= 5.20))	{
		int count = 1;
		double sum = 1 / 2;
		while(sum < x) {
			sum += (double)1 / (count + 1);
			++count;
		}
		cout << count - 1 << " card(s)" << endl;
	}
	return 0;
}