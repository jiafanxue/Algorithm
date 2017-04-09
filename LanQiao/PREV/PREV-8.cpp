/*
	买不到的数目
*/
#include <iostream>
#include <vector>
using namespace std;

void CantBuy(int a, int b)
{
	vector<int> vec(1000001, 0);
	int maxn = a * b;
	for(int i = 0; i * a <= maxn; ++i) {
		for(int j = 0; j * b <= maxn; ++j) {
			if(i * a + j * b > maxn) {
				break;
			}
			vec[i * a + j * b] = 1;
		}
	}

	for(int i = maxn; i > 0; --i) {
		if(vec[i] == 0) {
			cout << i << endl;
			break;
		}
	}
}

int main(int argc, char const *argv[])
{
	int a, b;
	cin >> a >> b;
	CantBuy(a, b);
	return 0;
}