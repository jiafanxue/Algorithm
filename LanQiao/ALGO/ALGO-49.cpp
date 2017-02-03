#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<int> vec;
	vec.reserve(n);
	for(int i = 0; i < n; ++i) {
		int a;
		cin >> a;
		vec.push_back(a);
	}

	vector<int>::iterator iter = max_element(vec.begin(), vec.end());
	cout << *iter << " " << distance(vec.begin(), iter) << endl;

	return 0;
}