#include <iostream>
using namespace std;

int Tile_laying(int n)
{
	if(n == 1) {
		return 1;
	}
	if(n == 2) {
		return 2;
	}
	return Tile_laying(n - 1) + Tile_laying(n - 2);
}

int main(int argc, char const *argv[])
{
	int N;
	cin >> N;
	cout << Tile_laying(N) << endl;
	return 0;
}