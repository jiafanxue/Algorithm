#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

bool isPrime(int a)
{
	for(int i = 2; i <= sqrt(a); i++)
		if(a % i== 0)
			return false;
	return true;
}

int main()
{
	int a, b;
	cin >> a >> b;

	vector<int> vec;
	for(int j = 2; j <= b; ++j) {
		if(isPrime(j)) {
			vec.push_back(j);
		}
	}

	for(int k = a; k <= b; ++k) {
		cout << k << "=";
		int number = k;
		for(unsigned i = 0; i < vec.size(); ++i) {
			while(number % vec[i] == 0) {
				cout << vec[i];
				if(number != vec[i]) {
					cout << "*";
				}
				number /= vec[i];
			}
		}
		cout << endl;
	}
	cout << endl;
	return 0;
}