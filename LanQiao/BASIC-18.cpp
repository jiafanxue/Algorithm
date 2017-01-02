#include <algorithm>
#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

double RectangularArea(double* arrayX, double* arrayY)
{	
	double erae;
	sort(arrayX, arrayX + 2);
	sort(arrayY, arrayY + 2);
	sort(arrayX + 2, arrayX + 4);
	sort(arrayY + 2, arrayY + 4);
	if(arrayX[1] <= arrayX[2] || arrayX[0] >= arrayX[3] || arrayY[0] >= arrayY[3] || arrayY[1] <= arrayY[2]) {
		erae = 0;
	}
	else {
		sort(arrayX, arrayX + 4);
		sort(arrayY, arrayY + 4);
		erae = (arrayX[2] - arrayX[1]) * (arrayY[2] - arrayY[1]);
	}
	return erae; 
}

int main()
{
	double* arrayX = new double[4];
	double* arrayY = new double[4];

	for(int i = 0; i < 4; ++i) {
		cin >> arrayX[i] >> arrayY[i];
	}

	cout << fixed << setprecision(2) << RectangularArea(arrayX, arrayY) << endl;

	return 0;
}