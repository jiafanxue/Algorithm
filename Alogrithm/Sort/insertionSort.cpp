/*
	插入排序
	时间复杂度：O(N^2)
*/
#include <iostream>
using namespace std;

/*
	升序排列
*/
void insertion_sort(int Array[], int length)
{
	for(int i = 1; i < length; ++i) {
		int key = Array[i];
		int j = i - 1;						// 第一次的时候j=0
		while(j >= 0 && Array[j] > key) {  	// key = Array[j + 1]
			Array[j + 1] = Array[j];
			j--;
		}
		Array[j + 1] = key;
	}
}

/*
	降序排列
*/
void insertion_desort(int Array[], int length)
{
	for(int i = 1; i < length; ++i) {
		int key = Array[i];
		int j = i - 1;
		while(j >= 0 && Array[j] < key) { 	// key = Array[j + 1]
			Array[j + 1] = Array[j];
			j--;
		}
		Array[j + 1] = key;
	}
}

int main(int argc, char const *argv[])
{
	int length = 6;
	int Array[] = {5, 2, 4, 6, 1, 3};

	/* 升序排序 */
	insertion_sort(Array, length);

	for(int i = 0; i < length; ++i) {
		cout << Array[i] << " ";
	}
	cout << endl;


	/* 降序排序 */
	insertion_desort(Array, length);

	for(int i = 0; i < length; ++i) {
		cout << Array[i] << " ";
	}
	cout << endl;

	return 0;
}