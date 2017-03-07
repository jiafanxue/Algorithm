#include <iostream>
#include <set>
using namespace std;

int main(int argc, char const *argv[])
{
	int num;
	set<int> s;
	for(int i = 0; i < 10; ++i) {
		cin >> num;
		s.insert(num);
	}
	
	for(set<int>::iterator it = s.begin(); it != s.end(); ++it)	{
		cout << *it << endl;
	}
	
	return 0;
}