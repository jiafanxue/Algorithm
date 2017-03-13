#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	int x1, y1, x2, y2;
	cin >> x1 >> y1;
	cin >> x2 >> y2;

	if(x1 == x2) {
		cout << "INF" << endl;
	}
	else {
		cout << (y1 - y2) / (x1 - x2) << endl;
	}
	return 0;
}