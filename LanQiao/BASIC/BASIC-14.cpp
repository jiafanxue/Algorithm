#include <iostream>
using namespace std;

int main()
{
	int times;
	cin >> times;
	int base = times / 3600;
	int hours = base > 0 ?  times / 3600 : 0;
	int base2 = times - 3600 * hours;
	int minutes = base2 > 0 ? base2 / 60 : 0;
	int base3 = times - 3600 * hours - 60 * minutes;
	int seconds = base3 > 0 ? base3 : 0;
	cout << hours << ":" << minutes << ":" << seconds << endl;
	return 0;
}