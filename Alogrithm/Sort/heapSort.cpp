/*
	堆排序(此处用得是最大堆)
	时间复杂度：O(N*log2(N))
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

// 堆排序
void heapSort(int array[], int length)
{
	build_max_heap(array, length);
	for(int i = length; i >= 0; --i) {
		std::swap(array[0], array[i]);
		--length;
		max_heapify(array, 0, length);
	}
}

int main(int argc, char const *argv[])
{
	// 下标从1开始，这样获取左右节点下标的函数不会出错
	vector<int> vec = {0, 4, 1, 3, 2, 16, 9, 10, 14, 8, 7};
	for(auto i : vec) {
		cout << i << " ";
	}
	cout << endl;

	heapSort(&*vec.begin(), vec.size() - 1);

	for(auto i : vec) {
		cout << i << " ";
	}
	cout << endl;

	return 0;
}