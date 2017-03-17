/*
	全排列问题
*/
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

void FullArrangement(vector<char>& vec, int begin, int end)
{
	// 达到递归结束条件
	if (begin == end) {
		for (int i = 0; i <= end; ++i) {
			cout << vec[i] << " ";
		}
		cout << endl;
	}
	else {
		for (int i = begin; i <= end; ++i) {
			std::swap(vec[begin], vec[i]);
			FullArrangement(vec, begin + 1, end);
			std::swap(vec[begin], vec[i]);
		}
	}
}

int main(int argc, char const *argv[])
{
	vector<char> vec = {'a', 'b', 'c'};
	FullArrangement(vec, 0, vec.size() - 1);
	return 0;
}