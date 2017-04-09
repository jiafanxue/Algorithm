/*
	错误票据
*/
#include <algorithm>
#include <iostream>
#include <iterator>
#include <string>
#include <memory>
#include <vector>
using namespace std;

void ErrorBill(vector<int> vec)
{
	// length
	int length = vec.size();

	// range
	int begin = vec[0];

	// find
	int less, repeat;
	for (int i = 1; i < length; ++i) {
		if (begin + 1 != vec[i] && begin != vec[i]) {
			less = begin + 1;
		}
		if (begin == vec[i]) {
			repeat = begin;
		}
		begin = vec[i];
	}

	cout << less << " " << repeat << endl;
}

int main(int argc, char const *argv[])
{
	int N, num;
	cin >> N;
	vector<int> vec;
	while (cin >> num) {
		vec.push_back(num);
	}

	sort(vec.begin(), vec.end());

	ErrorBill(vec);

	return 0;
}