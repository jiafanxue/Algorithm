/*
	翻硬币（贪心）
*/
#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

int TurnCoin(string initial, string target)
{
	int times = 0;
	int length = initial.size();
	while (initial != target) {
		for (int i = 0; i < length - 1; ++i) {
			if (initial[i] != target[i]) {
				initial[i] == '*' ? initial[i] = 'o' : initial[i] = '*';
				initial[i + 1] == 'o' ? initial[i + 1] = '*' : initial[i + 1] = 'o';
				times++;
			}
		}
	}
	return times;
}

int main(int argc, char const *argv[])
{
	string initial, target;
	cin >> initial >> target;
	cout << TurnCoin(initial, target) << endl;
	return 0;
}