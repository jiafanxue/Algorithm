/*
	连号区间数（并查集）
	超时！
*/
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

bool checkifok(vector<int> tmp)
{
	sort(tmp.begin(), tmp.end());

	for(unsigned i = 0; i < tmp.size() - 1; ++i) {
		if(tmp[i] + 1 != tmp[i + 1]) {
			return false;
		}
	}

	return true;
}

int EvenNumber(vector<int> vec, int N)
{
	int num = N;

	for(int i = 2; i <= N; ++i) {
		for(int j = 0; j < N; ++j) {
			vector<int> tmp(vec.begin() + j, vec.begin() + j + i);
			if(checkifok(tmp)) {
				num++;
			}
		}
	}

	return num;
}

int main(int argc, char const *argv[])
{
	int N;
	cin >> N;
	vector<int> vec;
	vec.reserve(N);
	int num;
	for(int i = 0; i < N; ++i) {
		cin >> num;
		vec.push_back(num);
	} 
	cout << EvenNumber(vec, N) << endl; 
	return 0;
}