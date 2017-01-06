#include <iostream>
#include <string>
using namespace std;

string TimePrint(int h, int m)
{
	string theTime = "";
	string ConvertArray[24] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine",
		"ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen",
		"nineteen", "twenty", "thirty", "forty", "fifty"};

	if(m == 0) {
		if(h > 20) {
			theTime += ConvertArray[20] + " " + ConvertArray[h - 20] + " o'clock";
		}
		else {
			theTime += ConvertArray[h] + " o'clock";
		}
	}
	else {
		if(h > 20) {
			theTime += ConvertArray[20] + " " + ConvertArray[h - 20] + " ";
		}
		else {
			theTime += ConvertArray[h] + " ";
		}

		if(m <= 20) {
			theTime += ConvertArray[m]; 
		}
		else if(m > 20 && m < 30) {
			theTime += ConvertArray[20] + " " + ConvertArray[m - 20];
		}
		else if(m == 30) {
			theTime += ConvertArray[21];
		}
		else if(m > 30 && m < 40) {
			theTime += ConvertArray[21] + " " + ConvertArray[m - 30];
		}
		else if(m == 40) {
			theTime += ConvertArray[22];
		}
		else if(m > 40 && m < 50) {
			theTime += ConvertArray[22] + " " + ConvertArray[m - 40];
		}
		else if(m == 50) {
			theTime += ConvertArray[23];
		}
		else if(m > 50 && m < 60) {
			theTime += ConvertArray[23] + " " + ConvertArray[m - 50];
		}
	}
	return theTime;
}

int main()
{
	int h, m;
	cin >> h >> m;
	cout << TimePrint(h, m) << endl;
	return 0;
}