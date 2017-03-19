#include <algorithm>
#include <iostream>
#include <iterator>
#include <set>
using namespace std;

int main(int argc, char const *argv[])
{
	int n;
	cin >> n;
	multiset<int> items;
	int num;
	for (int i = 0; i < n; ++i) {
		cin >> num;
		items.insert(num);
	}
	for (multiset<int>::iterator it = items.begin(); it != items.end();
	        it = items.upper_bound(*it)) {
		cout << *it << " " << items.count(*it) << endl;
	}
	return 0;
}