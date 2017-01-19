#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
	int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		if(!l1 && !l2) return NULL;
		if(!l1 && l2) return l2;
		if(l1 && !l2) return l1;

		ListNode* head = NULL;
		ListNode* tail = NULL;
		ListNode* node = NULL;

		int carry = 0;
		while(l1 || l2) {
		
			int val = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + carry;
			node = new ListNode(val % 10);
		
			if(!head) {
				head = node;
				tail = node;
		    } else {
			tail->next = node;
			tail = node;
		}

		carry = val / 10;
		
		l1 = l1 ? l1->next : NULL;
		l2 = l2 ? l2->next : NULL;
	}

	if(carry != 0) {
		node = new ListNode(carry);
		tail->next = node;
		tail = node;
	} 

	return head;
}
};

int main()
{
	ListNode l1(2), l2(4), l3(3);
	l1.next = &l2;
	l2.next = &l3;
	// ListNode *t = &l1;

	ListNode l4(5);
	ListNode l5(6);
	ListNode l6(4);
	l4.next = &l5;
	l5.next = &l6;

	Solution su;

	ListNode* t = su.addTwoNumbers(&l1, &l4);

	while(t != NULL)
	{
		cout << t->val << endl;
		t = t->next;
	}

	return 0;
}