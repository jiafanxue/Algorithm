/*
Question:
	Given a singly linked list, determine if it is a palindrome.

	Could you do it in O(n) time and O(1) space?
*/

#include <iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    bool isPalindrome(ListNode* head) {
    	if(head == NULL || head->next == NULL) {
    		return true;
    	}

        bool isPalind = true;
        
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast->next != NULL && fast->next->next != NULL) {
        	slow = slow->next;
        	fast = fast->next->next;
        }

        slow->next = reverseList(slow->next);
        slow = slow->next;
        while(slow != NULL) {
        	if(head->val != slow->val) {
        		isPalind = false;
        		break;
        	}
        	head = head->next;
        	slow = slow->next;
        }

        return isPalind;
    }

    ListNode* reverseList(ListNode* head) {
    	ListNode* next = NULL;
    	ListNode* pre = NULL;
    	while(head != NULL) {
    		next = head->next;
    		head->next = pre;
    		pre = head;
    		head = next;
    	}
    	return pre;
    }
};


int main(int argc, char const *argv[])
{
	ListNode* first = new ListNode(1);
	ListNode* second = new ListNode(2);
	ListNode* third = new ListNode(3);
	ListNode* four = new ListNode(2);
	ListNode* five = new ListNode(1);
	first->next = second;
	second->next = third;
	third->next = four;
	four->next = five;

	Solution su;

	if(su.isPalindrome(first)) {
		cout << "Yes" << endl;
	}
	else {
		cout << "No" << endl;
	}

	return 0;
}