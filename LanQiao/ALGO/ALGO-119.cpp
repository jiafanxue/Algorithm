#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char const *argv[])
{
	int num;
	cin >> num;
	vector<int> vec;
	for(int i = 1; i < num; ++i) {
		int lonely_num = i;
		bool flag = true;
		int tmp, res;
		for(int j = lonely_num - 36; j < i; ++j){
			tmp = j;
			res = j;
			while(tmp) {
				res += tmp % 10;
				tmp /= 10;
			}

			if(res == lonely_num) {
				flag = false;
				break;
			}
		}
		if(flag) {
			cout << lonely_num << endl;
		}
	}
	return 0;
}