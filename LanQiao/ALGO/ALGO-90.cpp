#include <iostream>
#include <vector>
using namespace std;

void FindMaxNumberOfOccur(vector<int> vec)
{
	int number = vec[0];
	int tmpnumber = vec[0];
	int len = 0;
	int tmplen = 0;
	for(unsigned i = 1; i < vec.size(); ++i) {
		if(tmpnumber == vec[i]) {
			tmplen++;
		}
		else {
			tmpnumber = vec[i];
			tmplen = 0;
		}
		if(len < tmplen) {
			len = tmplen;
			number = vec[i];
		}
	}
	cout << number << endl;
}

int main(int argc, char const *argv[])
{
	int n;
	cin >> n;
	if(n <= 0) {
		return 0;
	}
	vector<int> vec;
	vec.reserve(20);
	for(int i = 0; i < n; ++i) {
		int a;
		cin >> a;
		vec.push_back(a);
	}
	FindMaxNumberOfOccur(vec);
	return 0;
}