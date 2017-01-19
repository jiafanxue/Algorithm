/*
Question:
	Design a algorithm, Rotate an array containing N elements right by K bits.
	Time complexity: O(N)
*/
#include <iostream>
#include <string>
using namespace std;

/*
	Answer one
	Time complexity: O(K * N)
*/
// void RightShift(int* arr, int N, int K)
void RightShift_1(string& s_arr, int N, int K)
{
	while(K--) {
		int t = s_arr[N - 1];
		for(int i = N - 1; i > 0; --i) {
			s_arr[i] = s_arr[i - 1];
		}
		s_arr[0] = t;
	}
}

/*
	Anwser two
	Time complexity: O(N^2)
*/
void RightShift_2(string& s_arr, int N, int K)
{
	K %= N;
	while(K--) {
		int t = s_arr[N - 1];
		for(int i = N - 1; i > 0; --i) {
			s_arr[i] = s_arr[i - 1];
		}
		s_arr[0] = t;
	}
}

/*
	Answer three
	Time complexity: O(N)
*/
void Reverse(string& s_arr, int b, int e)
{
	for(; b < e; ++b, --e) {
		swap(s_arr[b], s_arr[e]);
	}
}

void RightShift_3(string& s_arr, int N, int K)
{
	K %= N;
	Reverse(s_arr, 0, N - K - 1);
	Reverse(s_arr, N - K, N - 1);
	Reverse(s_arr, 0, N - 1);
}


int main(int argc, char const *argv[])
{
	int N = 8;
	int K = 4;
	// int arr[N] = {'a', 'b', 'c', 'd', 1, 2, 3, 4};
	string s_arr = "abcd1234";
	for(int i = 0; i < N; ++i) {
		cout << s_arr[i];
	}
	cout << endl;

	RightShift_1(s_arr, N, K);

	for(int i = 0; i < N; ++i) {
		cout << s_arr[i];
	}
	cout << endl;

	RightShift_2(s_arr, N, K);

	for(int i = 0; i < N; ++i) {
		cout << s_arr[i];
	}
	cout << endl;

	RightShift_3(s_arr, N, K);

	for(int i = 0; i < N; ++i) {
		cout << s_arr[i];
	}
	cout << endl;

	return 0;	
}