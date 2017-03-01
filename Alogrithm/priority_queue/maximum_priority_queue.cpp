/*
	最大优先队列（最大堆实现）
	
	操作：
		1. heap_insert : 插入元素
		2. head_maximum : 返回最大元素
		3. heap_extract_max : 去掉最大元素
		4. heap_increase_key : 将关键字增加到k 
*/
#include <iostream>
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

// 维护最大堆的性质，即父节点比左右节点大
void max_heapify(int array[], int i, int length)
{
	int l_index = left(i);
	int r_index = right(i);
	int largest_index;
	if(l_index <= length && array[l_index] > array[i]) {
		largest_index = l_index;
	}
	else {
		largest_index = i;
	}

	if(r_index <= length && array[r_index] > array[largest_index]) {
		largest_index = r_index;
	}

	// 如果最大值的下标和i的值不相等，则交换后的下三角堆，
	// 存在子节点比父节点大的可能，所以以最大值下标为i，递归往下进行维护
	if(largest_index != i) {
		std::swap(array[i], array[largest_index]);
		max_heapify(array, largest_index, length);
	}
}

// 建立最大堆
// 自底向上法
void build_max_heap(int array[], int length)
{
	for(int i = (length / 2); i > 0; --i) {
		max_heapify(array, i, length);
	}
}

// 返回最大值
int heap_maximum(int array[])
{
	return array[1];
}

// 去掉最大元素
int heap_extract_max(int array[], int length)
{
	if(length < 1) {
		cerr << "heap underflow" << endl;
		exit(1);
	}
	int max = array[1];
	array[1] = array[length];
	--length;
	max_heapify(array, 1, length);
	return max;
}

// 将关键字增加到key
void heap_increase_key(int array[], int index, int key)
{
	if(key < array[index]) {
		cerr << "new key is smaller than current key" << endl;
		exit(1);
	}
	array[index] = key;
	while(index > 1 && array[parent(index)] < array[index]) {
		std::swap(array[parent(index)], array[index]);
		index = parent(index);
	}
}

// 插入元素
void heap_insert(int array[], int key, int length)
{
	++length;
	array[length] = -10000;
	heap_increase_key(array, length, key);
}

int main(int argc, char const *argv[])
{
	// 下标从1开始，这样获取左右节点下标的函数不会出错
	vector<int> vec = {0, 4, 1, 3, 2, 16, 9, 10, 14, 8, 7};
	// 建立一个最大堆
	build_max_heap(&*vec.begin(), vec.size() - 1);
	for(const auto& i : vec) {
		cout << i << " ";
	}
	cout << endl;

	// 输出最大值
	cout << heap_maximum(&*vec.begin()) << endl;

	// 去掉最大值
	cout << heap_extract_max(&*vec.begin(), vec.size() - 1) << endl;
	for(const auto& i : vec) {
		cout << i << " ";
	}
	cout << endl;

	// 插入一个值
	heap_insert(&*vec.begin(), 16, vec.size() - 1);
	for(const auto& i : vec) {
		cout << i << " ";
	}
	cout << endl;	

	// 增加元素的值
	heap_increase_key(&*vec.begin(), 2, 20);
	for(const auto& i : vec) {
		cout << i << " ";
	}
	cout << endl;	

	return 0;
}
