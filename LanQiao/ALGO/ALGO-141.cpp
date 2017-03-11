#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Student
{
	string name;
	string gender;
	int age;
	int score;
};

int main(int argc, char const *argv[])
{
	int n;
	cin >> n;
	vector<Student> vec;
	for(int i = 0; i < n; ++i) {
		Student tmp;
		cin >> tmp.name >> tmp.gender >> tmp.age >> tmp.score;
		vec.push_back(tmp);
	}

	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < n - 1; ++j) {
			if(vec[j].score > vec[j + 1].score) {
				swap(vec[j], vec[j + 1]);
			}
		}
	}

	for(int i = 0; i < n; ++i) {
		cout << vec[i].name << " " << vec[i].gender << " "
			<< vec[i].age << " " << vec[i].score << endl;
	}
	return 0;
}