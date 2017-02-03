#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Sum
{
public:
	Sum() : sum(0) {}
	void operator()(int n)
	{
		sum += n;
	}
	int sum;
};

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

	int sum = 0;
	for_each(vec.begin(), vec.end(), [&sum](int n){ sum += n; });
	cout << sum << " " << sum / n << endl;

	// Sum s = for_each(vec.begin(), vec.end(), Sum());
	// cout << s.sum << " " << s.sum / n << endl;
	return 0;
}