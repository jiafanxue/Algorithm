/*
	哈夫曼算法
*/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int huffman_coding(const vector<int>& vec)
{
	std::priority_queue<int, std::vector<int>, std::greater<int>> q;
	for(auto i : vec) {
		q.push(i);
	}

	for(unsigned i = 0; i < vec.size(); ++i) {
		int left = q.top();
		q.pop();
		int right = q.top();
		q.pop();
		int z = left + right;
		q.push(z);
	}
	return q.top();
}

int main(int argc, char const *argv[])
{
	vector<int> vec = {5, 9, 12, 13, 16, 45};
	cout << huffman_coding(vec) << endl;
	return 0;
}