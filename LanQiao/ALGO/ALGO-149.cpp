#include <iostream>
#include <cmath>
using namespace std;

int main(int argc, char const *argv[])
{
	int n, m;
	cin >> n >> m;
	int times = 0;
	for(int i = 1; i <= m; ++i) {
		++times;
		int result = pow(n, i);
		cout << "     " << result;
		if(times == 5) {
			cout << endl;
			times = 0;
		}
	}
	return 0;
}