/*
	找出最大值和最小值
*/
#include <iostream>
#include <vector>
using namespace std;

struct data
{
	int min;
	int max;
};

// 时间复杂度O(N)，需要2(N - 1)次比较
void mininum_maxinum(const vector<int>& vec, data& ds)
{
	ds.min = vec[0];
	ds.max = vec[0];
	for(unsigned i = 1; i < vec.size(); ++i) {
		if(ds.min > vec[i]) {
			ds.min = vec[i];
		}
		if(ds.max < vec[i]) {
			ds.max = vec[i];
		}
	}
} 

// 时间复杂度为O(N)，需要3 * (n / 2)次比较
void mininum_maxinum_2(const vector<int>& vec, data& ds)	
{
	if(vec.size() % 2 == 0 && vec.size() >= 2) {
		if(vec[0] > vec[1]) {
			ds.min = vec[1];
			ds.max = vec[0];
		}

		for(unsigned i = 2; i < vec.size(); i += 2) {
			if(vec[i] > vec[i + 1]) {
				if(ds.max > vec[i]) {
					ds.max = vec[i];
				}
				if(ds.min > vec[i + 1]) {
					ds.min = vec[i + 1];
				}

			}
			else {
				if(vec[i + 1] > ds.max) {
					ds.max = vec[i + 1]; 
				}
				if(ds.min > vec[i]) {
					ds.min = vec[i];
				}
			}
		}

	} 
	else if(vec.size() % 2 == 1) {
		ds.min = ds.max = vec[0];
		for(unsigned i = 1; i < vec.size(); i += 2) {
			if(vec[i] > vec[i + 1]) {
				if(ds.max > vec[i]) {
					ds.max = vec[i];
				}
				if(ds.min > vec[i + 1]) {
					ds.min = vec[i + 1];
				}

			}
			else {
				if(vec[i + 1] > ds.max) {
					ds.max = vec[i + 1]; 
				}
				if(ds.min > vec[i]) {
					ds.min = vec[i];
				}
			}
		}
	}
}

int main(int argc, char const *argv[])
{
	vector<int> vec = {1, 8, 9, 2, 0, -3, 7, 5, 14, 6, 11, -4, 2};
	data ds1, ds2;
	mininum_maxinum(vec, ds1);
	cout << ds1.min << " " << ds1.max << endl;
	mininum_maxinum_2(vec, ds2);
	cout << ds2.min << " " << ds2.max << endl; 
	return 0;
}