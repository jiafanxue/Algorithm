#include <iostream>
#include <string>
using namespace std;


class Solution {
public:
    string addStrings(string num1, string num2) {
        int n1 = num1.size(), i = n1 -1;
        int n2 = num2.size(), j = n2 -1;
        int carry =0;
        string res = "";
        while(i >= 0 || j >= 0 || carry)
        {
        	long sum = 0;
        	if(i>=0) 
        	{
        		sum += (num1[i] - '0');
        		i--;
        	}
        	if(j >= 0)
        	{
        		sum += (num2[j] - '0');
        		j--;
        	}
        	sum += carry;
        	carry = sum / 10;
        	sum = sum % 10;
        	res = to_string(sum) + res;
        }
        return res;
    }
};

int main()
{
	Solution su;

	string str1("123");
	string str2("456");

	cout << su.addStrings(str1, str2) << endl;

	return 0;
}