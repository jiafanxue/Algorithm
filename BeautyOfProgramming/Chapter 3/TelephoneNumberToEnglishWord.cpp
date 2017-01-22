/*
Question:
	The telephone number corresponds to the English word.
*/
#include <iostream>
#include <vector>
#include <string>
using namespace std;

void RecursiveSearch(vector<int> number, vector<int> answer, int index, int n)
{
	if(index == n) {
		for(int i = 0; i < n; ++i) {
			cout << c[number[i]][answer[i]];
		}
		cout << endl;
		return;
	}

	for(answer[index] = 0; answer[index] < total[number[index]]; ++answer[index]) {
		RecursiveSearch(number, answer, index + 1, n);
	}
}

int main(int argc, char const *argv[])
{

	string str[10][4] = {
		"",				// 0
		"",				// 1
		"ABC",			// 2
		"DEF",			// 3
		"GHI",			// 4
		"JKL",			// 5
		"MNO",			// 6
		"PORS",			// 7
		"TUV",			// 8
		"WXYZ",			// 9
	};

	vector<int> total = {0, 0, 3, 3, 3, 3, 3, 4, 3, 4};

	int TelLength;							// The size of telephone.
	cin >> TelLength;

	vector<int> number;						// The telephone number;
	number.reserve(TelLength);

	vector<int> answer;
	answer.reserve(TelLength);
	for(int i = 0; i < TelLength; ++i) {
		answer.push_back(0);
	}

	// e.g. c[number[0]][answer[0]] = c[4][2] = 'I'

	while(true) {
		// TelLength
		for(int i = 0; i < TelLength; ++i) {
			cout << c[number[i]][answer[i]];
		}
		cout  << endl;

		int k = n - 1;
		while(k >= 0) {
			if(answer[k] < total[number[k]] - 1) {
				answer[k]++;
				break;
			}
			else {
				answer[k] = 0;
				k--;
			}
		}
		if(k < 0) {
			break;
		}
	}

	return 0;
}