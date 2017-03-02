/*
	快速排序
	时间复杂度：O(N^2)  
	最好期望：O(N*log2(N))
*/
#include <iostream>
#include <vector>
using namespace std;

int partition(int array[], int begin, int end)
{
	int temp_val = array[end];
	int i = begin - 1;
	for(int j = begin; j < end; ++j) {
		if(array[j] <= temp_val) {
			++i;
			std::swap(array[i], array[j]);
		}
	} 
	std::swap(array[i + 1], array[end]);
	return i + 1;
}

void quickSort(int array[], int begin, int end)
{
	if(begin < end) {
		int mid = partition(array, begin, end);
		quickSort(array, begin, mid - 1);
		quickSort(array, mid + 1, end);
	}
}

int main(int argc, char const *argv[])
{
	vector<int> vec = {1, 3, 4, 2, 9, 8, 6, 5, 0, 7, -1, 6};
	for(const auto& i : vec) {
		cout << i << " ";
	}
	cout << endl;
	quickSort(&*vec.begin(), 0, vec.size() - 1);

	for(const auto& i : vec) {
		cout << i << " ";
	}
	cout << endl;
	return 0;
}