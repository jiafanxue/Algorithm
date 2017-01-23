#include <iostream>
using namespace std;

struct Node
{
	int val;
	Node* next;
	Node(int Val) : val(Val), next(NULL) {}
};

bool DetermineTwoListIntersect(Node* list1, Node* list2)
{

}

int main(int argc, char const *argv[])
{
	Node* first1 = new Node(1);
	Node* second2 = new Node(2);
	Node* third3 = new Node(3);
	Node* four4 = new Node(4);
	Node* five = new Node(5);
	first1->next = second;
	second2->next = third;
	third3->next = four;
	four4->next = five;
	Node* list1 = first1;

	Node* first2 = new Node(1);
	Node* second2 = new Node(2);
	Node* third2 = new Node(3);
	Node* four2 = new Node(4);
	Node* five2 = new Node(5);
	first2->next = second2;
	second2->next = third2;
	third2->next = four2;
	four2->next = five2;
	Node* list2 = first2;

	if(DetermineTwoListIntersect(list1, list2)) {
		cout << "Yes" << endl;
	}
	else {
		cout << "No" << endl;
	}
	
	return 0;
}