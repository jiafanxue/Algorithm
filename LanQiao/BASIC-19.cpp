#include <iostream>
#include <string>
using namespace std;

bool isReturnStr(string str, int& times, int n)
{
	int flag = 0;
	int j = n - 1;
	for(int i = 0; i < j; ++i) {
		for(int k = j; k >= i; k--) {
			if(k == i) {
				if(n % 2 == 0 || flag == 1)
					return false;
				flag = 1;
				times += n / 2 - i;
			}
			else if(str[k] == str[i]) {
				for(int l = k; l < j; ++l) {
					swap(str[l], str[l + 1]);
					times++;
				}
				j--;
				break;
			}
		}
	}
	return true;
}

int main()
{
	int times = 0;
	int n;
	cin >> n;
	string str;
	cin >> str;
	if(isReturnStr(str, times, n)) {
		cout << times << endl;
	}
	else {
		cout << "Impossible" << endl;
	}
	return 0;
}

/*
	Answer 2
*/
