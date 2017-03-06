#include <iostream>
#include <set>
using namespace std;

// The first line according to the order from small to large output A, B all elements of the intersection.
void intersection(int* A, int n, int* B, int m)
{
	set<int> sets;
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < m; ++j) {
			if(A[i] == B[j]) {
				sets.insert(A[i]);
			}
		}
	}

	if(!sets.empty()) {
		for(set<int>::iterator i = sets.begin(); i != sets.end(); ++i) {
			cout << *i << " ";
		}
		cout << endl;
	}
}

// The second lines in accordance with the order from small to large output A, B and all elements of the concentration.
void Union(int* A, int n, int* B, int m)
{
	set<int> sets;
	for(int i = 0; i < n; ++i) {
		sets.insert(A[i]);
	}

	for(int i = 0; i < m; ++i) {
		sets.insert(B[i]);
	}

	if(!sets.empty()) {
		for(set<int>::iterator i = sets.begin(); i != sets.end(); ++i) {
			cout << *i << " ";
		}
		cout << endl;
    }
}

// The third line in accordance with the order from small to large output of all elements of the B in the A.
void Complement(int* A, int n, int* B, int m)
{
	set<int> sets_1;
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < m; ++j) {
			if(A[i] == B[j]) {
				sets_1.insert(A[i]);
			}
		}
	}

	set<int> sets_2;
	for(int i = 0; i < n; ++i) {
		if(sets_1.find(A[i]) == sets_1.end()) {
			sets_2.insert(A[i]);
		}
	}

	if(!sets_2.empty()) {
		for(set<int>::iterator i = sets_2.begin(); i != sets_2.end(); ++i) {
			cout << *i << " ";
		}	
		cout << endl;
	}
}

int main(int argc, char const *argv[])
{
	int n;
	cin >> n;
	int* A = new int[n];
	for(int i = 0; i < n; ++i) {
		cin >> A[i];
	}
	int m;
	cin >> m;
	int* B = new int[m];
	for(int i = 0; i < m; ++i) {
		cin >>B[i];
	}
	intersection(A, n, B, m);
	Union(A, n, B, m);
	Complement(A, n, B, m);
	return 0;
}