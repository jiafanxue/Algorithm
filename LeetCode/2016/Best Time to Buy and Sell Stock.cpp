#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxofit;;
        int temp = 0;
        vector<int>::iterator ite = prices.begin();
        for(ite; ite!=prices.end(); ++ite)
        {

        	if(*ite)
        }
        return maxofit;
    }
};

int main()
{
	Solution su;

	vector<int> iv = {7, 1, 5, 3, 6, 4};

	cout << su.maxProfit(iv) << endl;

	return 0;
}