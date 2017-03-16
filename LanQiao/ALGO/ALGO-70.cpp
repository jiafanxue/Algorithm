#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(int argc, char const *argv[])
{
	vector<string> vec;
	string str;
	for(int i = 0; i < 5; ++i) {
		cin >> str;
		vec.push_back(str);
	}

	int max_index = 0;
	int max_count = 0;
	for(int i = 0; i < 5; ++i) {
		int size = vec[i].size();
		if(size > max_count) {
			max_index = i;
			max_count = size;
		}
	}
	cout << vec[max_index] << endl;
	return 0;
}