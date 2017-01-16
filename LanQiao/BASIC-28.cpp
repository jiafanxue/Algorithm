#include <iostream>
#include <vector>
using namespace std;

int HuffumanTree(vector<int> arrayTree)
{
	int HaffSum = 0;
	int n = arrayTree.size();
	while(n >= 2) {
		int pA = arrayTree[0];
		vector<int>::iterator arriter = arrayTree.begin();
		for(vector<int>::iterator iter = arrayTree.begin(); iter != arrayTree.end(); ++iter) {
			 if(pA > *iter) {
			 	pA = *iter;
			 	arriter = iter;
			 }
		}
		arrayTree.erase(arriter);
		n--;
		int pB = arrayTree[0];
		vector<int>::iterator arriter2 = arrayTree.begin();
		for(vector<int>::iterator iter = arrayTree.begin(); iter != arrayTree.end(); ++iter) {
			if(pB > *iter) {
				pB = *iter;
				arriter2 = iter;
			}
		}
		arrayTree.erase(arriter2);
		n--;
		int sum = pA + pB;
		HaffSum += pA + pB;
		arrayTree.push_back(sum);
		n++;
	}
	return HaffSum;
}


int main()
{
	int n;
	cin >> n;

	vector<int> arrayTree;
	for(int i = 0; i < n; ++i) {
		int a;
		cin >> a;
		arrayTree.push_back(a);
	}
	cout << HuffumanTree(arrayTree) << endl;
	return 0;
}