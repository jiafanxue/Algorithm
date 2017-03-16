#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
using namespace std;

int main(int argc, char const *argv[])
{
	int num, b;
	cin >> num >> b;
	int t;
	vector<int> vec;
	for(int i = 0; i < num; ++i) {
		cin >> t;
		vec.push_back(t);
	}

	for(vector<int>::iterator i = vec.begin(); i != vec.end(); ) {
		if(!(*i % 2)) {
			i = vec.erase(i);
		}
		else {
			++i;
		}
	}

	sort(vec.begin(), vec.end());

	for(vector<int>::iterator i = vec.begin(); i != vec.end(); ++i) {
		if(*i >= 'A' && *i <= 'Z') {
			char ch = *i;
			cout << ch << " ";	
		}
		else {
			cout << *i << " ";
		}
	}
	cout << endl;
	return 0;
}