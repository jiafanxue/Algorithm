/*
Question:
	Fino out more than half of the IDs in the presence ID.
*/

#include <iostream>
using namespace std;

/*
	Answer 1
	通过排序，出现次数超过一半的ID，中间值一定是它
*/
template <typename T>
T Find_1(T* ID, int N)
{
	for(int i = 0; i < N; ++i) {
		for(int j = i; j < N; ++j) {
			if(ID[j] > ID[j + 1]) {
				swap(ID[j], ID[j + 1]);
			}
		}
	}
	return ID[N / 2];
}

/*
	Answer 2
	由于ID出现半数，那么如果每次删除两个不同的ID（不管有没有包括出现次数最多的那个ID），那么，再剩下的ID列表
	中，出现最多的ID出现的次数任然超过总数的一半
*/
template <typename T>
T Find_2(T* ID, int N)
{
	T candidate;
	int nTimes = 0;
	for(int i = 0; i < N; ++i) {
		if(nTimes == 0) {
			candidate = ID[i];
			nTimes = 1;
		}
		else {
			if(candidate == ID[i]) {
				nTimes++;
			}
			else {
				nTimes--;
			}
		}
	}
	return candidate;
}


int main()
{
	int ID[10] = {1,2,3,2,2,4,6,2,5,2};

	cout << Find_1(ID, 10) << endl;

	cout << Find_2(ID, 10) << endl;

	return 0;
}