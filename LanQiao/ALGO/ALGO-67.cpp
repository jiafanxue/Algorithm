#include <iostream>
#include <vector>
using namespace std;

struct data
{
	int max;	
	int min;
};

data find_max_min(const vector<int>& vec)
{
	data tmp;
	tmp.max = tmp.min = vec[0];
	for(int i = 1; i < 11; ++i) {
		if(tmp.max < vec[i]) {
			tmp.max = vec[i];
		}
		if(tmp.min > vec[i]) {
			tmp.min = vec[i];
		}
	}
	return tmp;
}

int main(int argc, char const *argv[])
{
	vector<int> vec;
	vec.reserve(11);
	for(int i = 0; i < 11; ++i) {
		int num;
		cin >> num;
		vec.push_back(num);
	}
	data result;
	result = find_max_min(vec);
	cout << result.max << " " << result.min << endl;
	return 0;
}