#include <iostream>
#include <string>
using namespace std;

string str_o1_changed(int num)
{
	if(num == 0) {
		return "0";
	}
	if(num == 1) {
		return "1";
	}
	return str_o1_changed(num - 2) + str_o1_changed(num - 1);
}

int main(int argc, char const *argv[])
{
	int num;
	cin >> num;
	cout << str_o1_changed(num) << endl;
	return 0;
}