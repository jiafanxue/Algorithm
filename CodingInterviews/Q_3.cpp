/*
题目：
	在一个二维数组中，每一行都按照从左到右递增的顺序排序，
	每一列都按照从上到下递增的顺序排序。请完成一个函数，输入
	这样一个二维数组和一个整数，判断数组中是否含有该整数。
*/
#include <iostream>
using namespace std;

// 每次选取右上角
bool Find(int* matrix, int rows, int columns, int number)
{
	bool found = false;
	if(matrix != NULL && rows > 0 && columns > 0) {
		int row = 0;
		int column = columns - 1;
		while(row < rows && column >= 0) {
			if(matrix[row * columns + column] == number) {
				found = true;
				break;
			}
			else if(matrix[row * columns + column] > number){
				--column;
			}
			else {
				++row;
			}
		}
	}
	return found;
}

// 每次选取左下角
bool Find_left(int* matrix, int rows, int columns, int number)
{
	bool found = false;
	if(matrix != NULL && rows > 0 && columns > 0) {
		int row = rows;
		int column = 0;
		while(column < columns && row > 0) {
			if(matrix[column * rows + row] == number) {
				found = true;
				break;
			}
			else if(matrix[column * rows + row] < number) {
				++column;
			}
			else {
				--row;
			}
		} 
	}
	return found;
}

int main(int argc, char const *argv[])
{
	int row = 4;
   	int col = 4;
	int matrix[16] = {
		1, 2, 8, 9,
		2, 4, 9, 12,
		4, 7, 10, 13,
		6, 8, 11, 15
	};

	int number;
	cin >> number;

	if(Find(matrix, row, col, number)) {
		// Find_left(matrix, row, col, number)
		cout << "Find" << endl;
	}
	else {
		cout << "Not Find" << endl;
	}
	return 0;
}