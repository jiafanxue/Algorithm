#include <iostream>
#include <queue>
using namespace std;

int main(int argc, char const *argv[])
{
	queue<int> q;
	int N;
	cin >> N;
	int num;
	int number;
	for (int i = 0; i < N; ++i) {
		cin >> num;
		switch (num) {
		case 1: {
			cin >> number;
			q.push(number);
		}
			break;

		case 2:
		{
			if(q.size()) {
				cout << q.front() << endl;
				q.pop();
			}
			else {
				cout << "no" << endl;
				exit(0);
			}
		}
			break;


		case 3:
			cout << q.size() << endl;
			break;
		}
	}

	return 0;

}