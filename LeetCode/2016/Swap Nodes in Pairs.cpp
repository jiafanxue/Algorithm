#include <iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
  		ListNode** result = &head, *a, *b;
  		while((a = *result) && (b = a->next)) {
  			a->next = b->next;
  			b->next = a;
  			*result = b;
  			result = &(a->next);
  		}
  		return head;
    }
};

int main()
{

	ListNode* first = new ListNode(1);
	ListNode* second = new ListNode(2);
	ListNode* three = new ListNode(3);
	ListNode* four = new ListNode(4);
	ListNode* five = new ListNode(5);
	ListNode* six = new ListNode(6);
	first->next = second;
	second->next = three;
	three->next = four;
	four->next = five;
	five->next = six;

	ListNode* tmp1 = first;
	while(tmp1) {
		cout << tmp1->val << "->";
		tmp1 = tmp1->next;
	}
	cout << endl;

	Solution su;

	ListNode* head = su.swapPairs(first);

	ListNode* tmp2 = head;
	while(tmp2) {
		cout << tmp2->val << "->";
		tmp2 = tmp2->next;
	}
	cout << endl;

	return 0;
}


