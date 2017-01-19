#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int arrangeCoins(int n) {
        if(n <= 1) return n;
        long left = 0, right = n;
        while(left <= right){
            long mid = left + (right - left)/2;
            long sum = ((1 + mid) * mid)/2;
            if(sum <= n){left = mid + 1;}
            else {right = mid - 1;}
        }
        return left - 1;
    }
};

int main()
{
	int n = 8;
    Solution su;
	cout << su.arrangeCoins(n) << endl;
	return 0;

}