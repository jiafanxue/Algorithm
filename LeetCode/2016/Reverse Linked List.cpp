#include <iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
    	if(head == NULL || head->next == NULL)
    		return head;
        ListNode* prev = NULL;
        ListNode* nextNode = NULL;
        while(head)
        {
        	nextNode = head->next;
        	head->next = prev;
        	prev = head;
        	head = nextNode;
        }
        return prev;
    }
};


int main(int argc, char const *argv[])
{
	ListNode* first = new ListNode(1);
	ListNode* second = new ListNode(2);
	ListNode* third = new ListNode(3);
	ListNode* four = new ListNode(4);

	first->next = second;
	second->next = third;
	third->next = four;

	Solution su;

	first = su.reverseList(first);

	ListNode* theNode = first;

	while(theNode != NULL)
	{
		cout << theNode->val << "->";
		theNode = theNode->next;
	}

	return 0;
}