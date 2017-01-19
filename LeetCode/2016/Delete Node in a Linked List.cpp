#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    void deleteNode(ListNode* node) {
    	if(node == NULL)
    		return;
    	if(node->next == NULL)
    		return;
    	*node = *node->next;
    }
};


int main()
{
	ListNode l1(1), l2(2), l3(3),l4(4);
	l1.next = &l2;
	l2.next = &l3;
	l3.next = &l4;

	ListNode* temp = &l1;
	while(temp != NULL)
	{
		cout << temp->val << " ";
		temp = temp->next;
	}
	cout << endl;

	Solution su;
	su.deleteNode(&l4);
	ListNode* temp2 = &l1;
	while(temp2 != NULL)
	{
		cout << temp2->val << " ";
		temp2 = temp2->next;
	}
	cout << endl;


	return 0;
}