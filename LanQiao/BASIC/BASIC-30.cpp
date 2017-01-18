#include <iostream>
#include <vector>
using namespace std;

void factorial(int n)
{
	if(n == 0) {
		int temp = 1;
		cout << temp << endl;
		return;
	}

	vector<int> vec;
	vector<int> tvec;
	int carry = 0;
	for(int i = 1; i <= n; ++i) {
		int size = vec.size();
		for(int j = 0; j < size; ++j) {
			if(carry == 0) {
				int tmp = vec[j] * i;
				carry = tmp / 10;
				int t = tmp % 10;
				vec[j] = t;
				tvec[j] = t;
			}
			else {
				int tmp = vec[j] * i;
				int recarry = tmp % 10;
				recarry += carry;
				int t = recarry % 10;
				vec[j] = t;
				tvec[j] = t;
				carry = tmp / 10;
				carry += recarry / 10;
			}
		}

		if(size == 0) {
			vec.push_back(1);
			tvec.push_back(1);
		}
		if(carry != 0) {
			vec.push_back(carry);
			tvec.push_back(carry);
			carry = 0;
		}
	}

	for(int i = tvec.size() - 1; i >= 0; --i) {
		cout << tvec[i];
	}
	cout << endl;
}

int main(int argc, char const *argv[])
{
	int n;
	cin >> n;
	factorial(n);
	return 0;
}