/*
	核桃的数量（最小公倍数问题）
*/
#include <iostream>
using namespace std;

int The_least_common_multiple(int a, int b)
{
	int least_num;
	for(int i = 1; i <= a * b; ++i) {
		if(i % a == 0 && i % b == 0) {
			least_num = i;
			break;
		}
	}
	return least_num;
}

int Number_of_walnuts(int a, int b, int c)
{
	int a_b = The_least_common_multiple(a, b);
	int a_b_c = The_least_common_multiple(a_b, c);
	return a_b_c;
}

int main(int argc, char const *argv[])
{
	int a, b, c;
	cin >> a >> b >> c;
	cout << Number_of_walnuts(a, b, c) << endl;
	return 0;
}