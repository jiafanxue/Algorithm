#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char const *argv[])
{
	int num;
	cin >> num;
	vector<int> vec;
	while(num) {
		int tmp = num % 8;
		vec.push_back(tmp);
		num /= 8;
	}
	for(vector<int>::reverse_iterator i = vec.rbegin(); i != vec.rend(); ++i) {
		cout << *i;
	}
	cout << endl;
	return 0;
}