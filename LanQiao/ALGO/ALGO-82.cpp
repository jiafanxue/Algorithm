#include <iostream>
using namespace std;

int k_num(int i, int j, int num)
{
	int r;
	if(i > num / 2) {
		i = num - i - 1;
	}
	if(j > num / 2) {
		j = num - j - 1;
	}
	if(i == num / 2) {
		i = j;
	}
	if(j == num / 2) {
		j = i;
	}
	if(i == j) {
		r = i;
	}
	else {
		r = -1;
	}
	return r;
}

void print_mi(int n, char ch)
{
	int num = 2 * n - 1;
	int k;
	for(int i = 0; i < num; ++i) {
		for(int j = 0; j < num; ++j) {
			k = k_num(i, j, num);
			if(k < 0) {
				cout << ".";
			}
			else {
				char c = 'A' + k;
				cout << c;
			}
		}
		cout << endl;
	}
}

int main(int argc, char const *argv[])
{
	int n;
	cin >> n;
	print_mi(n, 'A');	
	return 0;
}