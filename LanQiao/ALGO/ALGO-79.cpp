#include <iostream>
#include <iterator>
#include <algorithm>
#include <vector>
using namespace std;

void CompactIntegers(vector<int> vec)
{
	vec.erase(
		remove(
			vec.begin(),
			vec.end(),
			0),
		vec.end()
	);

	cout << vec.size() << endl;
	if(!vec.empty()) {
		copy(vec.begin(), vec.end(), ostream_iterator<int>(cout, " "));
		cout << endl;
	}
}

int main(int argc, char const *argv[])
{
	int n;
	cin >> n;
	vector<int> vec;
	vec.reserve(n);
	int a;
	for(int i = 0; i < n; ++i) {
		cin >> a;
		vec.push_back(a);
	}
	CompactIntegers(vec);
	return 0;
}