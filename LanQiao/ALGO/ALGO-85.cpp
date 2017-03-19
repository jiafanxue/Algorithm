#include <cmath>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>
using namespace std;

int main(int argc, char const *argv[])
{
	string str;
	cin >> str;
	int size = str.size();
	int num = 0;
	for (int i = 1, j = 0; i <= size; ++i, ++j) {
		num += (str[j] - '0') * (int)pow(2, size - i);
	}
	cout << num << endl;
	return 0;
}