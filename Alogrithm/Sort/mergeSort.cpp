/*
	归并排序
	时间复杂度：O(N*log2(N))
*/
#include <iostream>
using namespace std;

const int MAX = 100000;

void merge(int Array[], int p, int q, int r)
{
	int n1 = q - p + 1;
	int n2 = r - q;
	int* lArray = new int[n1];
	int* rArray = new int[n2];

	for(int i = 0; i < n1; ++i) {
		lArray[i] = Array[p + i];
	}

	for(int i = 0; i < n2; ++i) {
		rArray[i] = Array[q + i + 1];
 	}

 	int i = 0;
 	int j = 0;
 	int k = p;
 	while(i < n1 && j < n2) {
 		if(lArray[i] <= rArray[j]) {
 			Array[k] = lArray[i];
 			i++;
 		}
 		else {
 			Array[k] = rArray[j];
 			j++;
 		}
 		k++;
 	}

 	while(i < n1) {
 		Array[k++] = lArray[i++];
 	}
 	
 	while(j < n2) {
 		Array[k++] = rArray[j++];
 	}

}

void mergeSort(int Array[], int p, int r)
{
	if(p < r) {
		int q = p + (r - p) / 2;
		mergeSort(Array, p, q);
		mergeSort(Array, q + 1, r);
		merge(Array, p, q, r);
	}
}

int main(int argc, char const *argv[])
{
	int length = 6;
	int Array[6] = {5, 2, 4, 6, 1, 3};

	mergeSort(Array, 0, 5);

	for(int i = 0; i < length; ++i) {
		cout << Array[i] << " ";
	}
	cout << endl;

	return 0;
}