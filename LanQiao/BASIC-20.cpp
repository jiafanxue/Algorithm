#include <iostream>
#include <string>
using namespace std;

void ConversionUnit(int num)
{
	string str[20];
	string digitalStr[10] = {"ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"};
	string unitStr[6] = {"shi", "bai", "qian", "wan", "yi"};
	int i = 0; 
	int j = 0;
	int k;
	int l[2] = {0};
	while(num) {
		k = num % 10;
		num /= 10;
		if(k > 0) {
			if(i > 0) {
				if(i >= 4 && !l[i / 4 - 1]) {
					l[i / 4 - 1] = 1;
					str[j++] = unitStr[i / 4 + 2];
				}
				if(i % 4 != 0) {
					str[j++] = unitStr[i % 4 - 1];
				}
			}
			str[j++] = digitalStr[k];
		}
		else if(j > 0 && str[j - 1] != digitalStr[0]) {
			str[j++] = digitalStr[0];
		}
		i++;
	}

	if(!(str[j - 1] == "yi" && j > 1 && str[j - 2] == "shi")) {
		cout << str[j - 1] << ' ';
	}
	for(int i = j - 2; i >= 0; i--) {
		if(i != 0) {
			cout << str[i] << ' ';
		}
		else {
			cout << str[i];
		}
	}
}

int main()
{
	int num;
	cin >> num;
	ConversionUnit(num);
	cout << endl;
	return 0;
}