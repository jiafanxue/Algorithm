#include <iostream>
#include <string>
#include <cmath>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
    	if(head==NULL || head->next == NULL)
    		return head;
        ListNode* tmp = head;
        ListNode* post = head->next;
        while(tmp && post)
        {
        	if(tmp->val == post->val)
        	{
        		tmp->next = post->next;
        		delete post;
        		post = tmp->next;
        	}
        	else
        	{
        		tmp = tmp->next;
        		post = post->next;
        	}
        }
        return head;
    }
};


int main()
{
	ListNode* first = new ListNode(1);
	ListNode* second = new ListNode(1);
	ListNode* thrid = new ListNode(1);
	ListNode* four = new ListNode(2);
	ListNode* five = new ListNode(3);
	ListNode* six = new ListNode(4);
	first->next = second;
	second->next = thrid;
	thrid->next = four;
	four->next = five;
	five->next = six;
	Solution su;

	ListNode* tmp = su.deleteDuplicates(first);
	while(tmp)
	{
		if(tmp->next == NULL)
			cout << tmp->val;
		else
			cout << tmp->val << "->";
		tmp = tmp->next;
	}
	cout << endl;
	return 0;
}