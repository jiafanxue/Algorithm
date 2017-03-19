#include <algorithm>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>
using namespace std;

struct complexNode
{
	int a;
	int b;
	complexNode* next;
	complexNode() : a(0), b(0), next(nullptr) { }
	complexNode(int a_, int b_) : a(a_), b(b_), next(nullptr) { }
};

void createList(complexNode* head, complexNode* data)
{
	complexNode* p = head;
	while (p->next != nullptr) {
		p = p->next;
	}
	p->next = data;
	head = p;
}

void Sum_of_complex(complexNode* head)
{
	complexNode* p = head;
	int a = 0, b = 0;
	while (p != nullptr) {
		a += p->a;
		b += p->b;
		p = p->next;
	}
	cout << a << "+" << b << "i" << endl;
}

int main(int argc, char const *argv[])
{
	complexNode* p = new complexNode(0, 0);
	int a, b;
	while (cin >> a >> b) {
		complexNode* tmp = new complexNode(a, b);
		createList(p, tmp);
	}
	Sum_of_complex(p);
	return 0;
}