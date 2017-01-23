/*
Question:
	Removes a node from headless single-linked list

	e.g.
		.... --> 2 --> 3 --> 4 --> 5 --> .....
					   | 删除3
*/
#include <iostream>
#include <cassert>
using namespace std;

struct Node
{
	int val;
	Node* next;
	Node(int Val) : val(Val), next(NULL) {}
};

void printList(Node* root)
{
	while(root) {
		cout << root->val << "->";
		root = root->next;
	}
	cout << endl;
}

void DeleteFromSingleLinkedList(Node* pCurrent)
{
	assert(pCurrent != NULL);
	Node* pNext = pCurrent->next;
	if(pNext != NULL) {
		pCurrent->next = pNext->next;
		pCurrent->val = pNext->val;
		delete pNext;
	}
}

int main(int argc, char const *argv[])
{
	Node* first = new Node(1);
	Node* second = new Node(2);
	Node* third = new Node(3);
	Node* four = new Node(4);
	Node* five = new Node(5);
	first->next = second;
	second->next = third;
	third->next = four;
	four->next = five;

	Node* pCurrent = third;

	DeleteFromSingleLinkedList(pCurrent);
	printList(first);
	return 0;
}