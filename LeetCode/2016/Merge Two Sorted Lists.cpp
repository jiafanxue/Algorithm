#include <iostream>
#include <string>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    	if(l1 == NULL)
    		return l2;
    	if(l2 == NULL)
    		return l1;
        ListNode* result = new ListNode(0);
		ListNode* tmp = result;        
        while(l1 && l2) {
        	if(l1->val <= l2->val) {
        		tmp->next = l1;
        		l1 = l1->next;
        	}
        	else {
        		tmp->next = l2;
        		l2 = l2->next;
        	}
        	tmp=tmp->next;
        }
        tmp->next = l1 ? l1 : l2;
        return result->next;
    }
};

int main()
{
	ListNode* l1 = new ListNode(2);
	ListNode* l12 = new ListNode(3);
	ListNode* l13 = new ListNode(6);
	ListNode* l14 = new ListNode(9);
	ListNode* l15 = new ListNode(12);
	ListNode* l16 = new ListNode(22);

	ListNode* l2 = new ListNode(1);
	ListNode* l22 = new ListNode(4);
	ListNode* l23 = new ListNode(5);
	ListNode* l24 = new ListNode(7);
	ListNode* l25 = new ListNode(8);
	ListNode* l26 = new ListNode(10);

	l1->next = l12;
	l12->next = l13;
	l13->next = l14;
	l14->next = l15;
	l15->next = l16;

	l2->next = l22;
	l22->next = l23;
	l23->next = l24;
	l24->next = l25;
	l25->next = l26;

	Solution su;

	ListNode* result = su.mergeTwoLists(l1,l2);

	ListNode* t = result;
	while(t)
	{
		cout << t->val << ' ';
		t=t->next;
	}
	return 0;
}