#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;

struct prut	
{
	string mc;
	double dj;
	int sl;
};

int main(int argc, char const *argv[])
{
	int n;
	cin >> n;
	vector<prut> vec;
	for(int i = 0; i < n; ++i) {
		prut tmp;
		cin >> tmp.mc >> tmp.dj >> tmp.sl;
		vec.push_back(tmp);
	}
	
	double sum;
	for(int i = 0; i < n; ++i) {
		sum += vec[i].dj * vec[i].sl;
	}
	cout << fixed << setprecision(6) << sum << endl;
	return 0;
}