#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(int argc, char const *argv[])
{
	vector<int> vec;
	for(int i = 0; i < 3; ++i) {
		int a;
		cin >> a;
		vec.push_back(a);
	}
	sort(vec.begin(), vec.end(), greater<int>());
	for(int i = 0; i < 3; ++i) {
		cout << vec[i] << " ";
	}
	cout << endl;
	return 0;
}