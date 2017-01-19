#include <iostream>
#include <string>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    	if(root == NULL)
    		return NULL;
        TreeNode* tmp = root;
        if(((p->val <= tmp->val) && (q->val >= tmp->val))||((p->val >= tmp->val) && (q->val <= tmp->val)))
        	return root;
        if(p->val < tmp->val && q->val < tmp->val) {
        	return lowestCommonAncestor(tmp->left, p, q);
        }
        else if(p->val > tmp->val && q->val > tmp->val) {
        	return lowestCommonAncestor(tmp->right, p, q);
        }
       	return NULL;
    }
};

/*class Solution {
public:
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		if(root==NULL) 
			return NULL;
		if((p->val<=root->val && root->val<=q->val) || (q->val<=root->val && root->val<=p->val)) 
			return root;
		if (root->val < p->val) 
			return lowestCommonAncestor(root->right,p,q);
		return lowestCommonAncestor(root->left,p,q);
    }
};*/

int main()
{
	TreeNode* first = new TreeNode(6);
	TreeNode* second = new TreeNode(2);
	TreeNode* third = new TreeNode(8);
	TreeNode* four = new TreeNode(0);
	TreeNode* five = new TreeNode(4);
	TreeNode* six = new TreeNode(7);
	TreeNode* seven = new TreeNode(9);
	TreeNode* eight = new TreeNode(3);
	TreeNode* nine = new TreeNode(5);

	first->left = second;
	first->right = third;
	second->left = four;
	second->right = five;
	third->left = six;
	third->right = seven;
	five->left = eight;
	five->right = nine;

	Solution su;

	cout << su.lowestCommonAncestor(first, third, four)->val << endl;


	return 0;
}