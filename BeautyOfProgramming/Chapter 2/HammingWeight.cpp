/*
Question:
	If there is a byte unsigned integer variable, find the binary representation of the number of "1".
*/
#include <iostream>
using namespace std;

/*
	Answer 1
*/
int Hweight_1(int a)
{
	int count = 0;
	while(a) {
		if(a % 2 == 1) {
			count++;
		}
		a /= 2;
	}
	return count;
}

/*
	Answer 2
*/
int Hweight_2(int a)
{
	int count = 0;

	while(a) {
		count += a & 0x01;
		a >>= 1;
	}
	return count;
}

/*
	Answer 3
	a & (a - 1) : count the number of 1
	a | (a + 1) : count the number of 0
*/
int Hweight_3(int a)
{
	int count = 0;
	while(a) {
		a &= (a - 1);
		count++;
	}
	return count;
}

/*
	Anwser 4
*/
// int Hweight_4(int a)
// {
// 	int count = 0;
// 	switch(a) {
// 		case 0x0:
// 			count = 0;
// 			break;
// 		case 0x1:
// 		case 0x2:
// 		case 0x4:
// 		case 0x8:
// 		case 0x10:
// 		case 0x20:
// 		case 0x40:
// 		case 0x80:
// 			count = 1;
// 			break;
// 		//....
// 	}

// 	return count;
// }

/*
	Anwser 5
		O(1)
*/
// 将0-256的整数里的1的个数放入下列的数组里
int countTable[256] = 
{
	0,1,1,2,1,2,2,3,1,2,2,3,2,3,3,4,1,2,2,3,2,3,3,4,2,3,
	3,4,3,4,4,5,1,2,2,3,2,3,3,4,2,3,3,4,3,4,4,5,2,3,3,4,
	3,4,4,5,3,4,4,5,4,5,5,6,1,2,2,3,2,3,3,4,2,3,3,4,3,4,
	//..................
}

int Hweight_5(int a)
{
	return countTable[a];
}


int main()
{
	int a = 15;
	cout << Hweight_1(a) << endl;
	cout << Hweight_2(a) << endl;
	cout << Hweight_3(a) << endl;
	return 0;
}