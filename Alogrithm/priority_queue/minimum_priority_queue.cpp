/*
	最小优先队列（最小堆实现）

	操作：
		1. heap_insert : 插入元素
		2. heap_minimum : 返回最小元素
		3. heap_extract_min : 去掉最小元素
		4. heap_increase_key : 将关键字增加到k
*/
#include <algorithm>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>
using namespace std;

// 获取当前下标的父节点
inline const int parent(int index)
{
	return index / 2;
}

// 获取当前下标的左节点
inline const int left(int index)
{
	return index * 2;
}

// 获取当前下标的右节点
inline const int right(int index)
{
	return index * 2 + 1;
}

// 维护最小堆的性质，即父节点比子节点小
void min_heapify(vector<int>& vec, int index, int length)
{
	int l_index = left(index);
	int r_index = right(index);
	int smallest_index;
	if (l_index <= length && vec[l_index] < vec[index]) {
		smallest_index = l_index;
	}
	else {
		smallest_index = index;
	}

	if (r_index <= length && vec[r_index] < vec[smallest_index]) {
		smallest_index = r_index;
	}

	if (smallest_index != index) {
		std::swap(vec[index], vec[smallest_index]);
		min_heapify(vec, smallest_index, length);
	}
}

// 创建最小堆
// 自底向上
void build_min_heap(vector<int>& vec)
{
	int size = vec.size() - 1;
	for (int i = size / 2; i > 0; --i) {
		min_heapify(vec, i, size);
	}
}

// 返回最小的元素
int heap_minimum(const vector<int>& vec)
{
	return vec[1];
}

// 去掉最小的元素
int heap_extract_min(vector<int>& vec)
{
	int size = vec.size();
	if (size < 1) {
		cerr << "heap underflow" << endl;
		exit(1);
	}

	int min = vec[1];
	vec[1] = vec[size - 1];
	min_heapify(vec, 1, size - 1);
	return min;
}

// 将关键字减小到key
void heap_increase_key(vector<int>& vec, int index, int key)
{
	if (key > vec[index]) {
		cerr << "new key is larger than current key" << endl;
		exit(1);
	}
	vec[index] = key;
	while (index > 1 && vec[parent(index)] > vec[index]) {
		std::swap(vec[parent(index)], vec[index]);
		index = parent(index);
	}
}

int main(int argc, char const *argv[])
{
	// 下标从1开始，这样获取左右节点下标的函数不会出错
	vector<int> vec = { 0, 4, 1, 3, 2, 16, 9, 10, 14, 8, 7 };
	// 建立一个最小堆
	build_min_heap(vec);
	for (const auto& i : vec) {
		cout << i << " ";
	}
	cout << endl;

	// 输出最小值
	cout << heap_minimum(vec) << endl;

	// 去掉最小值
	cout << heap_extract_min(vec) << endl;
	for (const auto& i : vec) {
		cout << i << " ";
	}
	cout << endl;

	// 增加元素的值
	heap_increase_key(vec, 4, 1);
	for (const auto& i : vec) {
		cout << i << " ";
	}
	cout << endl;

	return 0;
}