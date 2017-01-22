/*
Question:
	Calculates the distance of the two strings.
*/
#include <iostream>
#include <string>
using namespace std;

int minValue(int v1, int v2, int v3)
{
	return min(min(v1, v2), v3);
}

int CalculateStringDistance(string strA, int pABegin, int pAEnd, string strB, int pBBegin, int pBEnd)
{
	if(pABegin > pAEnd) {
		if(pBBegin > pBEnd) {
			return 0;
		}
		else {
			return pBEnd - pBBegin + 1;
		}
	}

	if(pBBegin > pBEnd) {
		if(pABegin > pAEnd) {
			return 0;
		}
		else {
			return pAEnd - pABegin + 1;
		}
	}

	if(strA[pABegin] == strB[pBBegin]) {
		return CalculateStringDistance(strA, pABegin + 1, pAEnd, strB, pBBegin + 1, pBEnd);
	}
	else {
		int t1 = CalculateStringDistance(strA, pABegin, pAEnd, strB, pBBegin + 1, pBEnd);
		int t2 = CalculateStringDistance(strA, pABegin + 1, pAEnd, strB, pBBegin, pBEnd);
		int t3 = CalculateStringDistance(strA, pABegin + 1, pAEnd, strB, pBBegin + 1, pBEnd);

		return minValue(t1, t2, t3) + 1;
	}
}

int main(int argc, char const *argv[])
{
	string strA = "abcdefg";
	string strB = "abcdef";

	cout << CalculateStringDistance(strA, 1, 2, strB, 1, 2) << endl;
	return 0;
}