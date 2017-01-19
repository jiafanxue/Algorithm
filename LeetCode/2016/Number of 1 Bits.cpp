#include <iostream>
#include <vector>
#include <cstdint>
using namespace std;

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int a =0;
        for(;n;n>>=1)
            if(n & 1)
                a++;
        return a;
    }
};

int main()
{
	Solution su;

	uint32_t n=100;

	cout << su.hammingWeight(n) << endl;

	return 0;
}