/*
Question:
	Given a binary tree and a sum, determine if t he tree has a root-to-leaf path such that adding up
	all up t he values along the path equals the given sum.
	
	For example:
		Given the below binary tree and sum = 22
					5
				   / \
				  4	  8
				 /   / \
				11  13  4
			   /  \      \
			  7    2      1
		return true, as there exist a root-to-leaf path 5->4->11->2 which sum is 22.
*/

#include <iostream>
using namespace std;

struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	bool hasPathSum(TreeNode* root, int sum) {
		if(root == NULL) {
			return false;
		}
		if(root->val == sum && root->left == NULL && root->right == NULL)
			return true;
		return hasPathSum(root->left, sum - root->val) || hasPathSum(root->right, sum - root->val);
	}
};

void print(TreeNode* root)
{
	if(root) {
		print(root->left);
		cout << root->val << " ";
		print(root->right);
	}
}

int main(int argc, char const *argv[])
{
	TreeNode* first = new TreeNode(5);
	TreeNode* second = new TreeNode(4);
	TreeNode* third = new TreeNode(8);
	TreeNode* four = new TreeNode(11);
	TreeNode* five = new TreeNode(13);
	TreeNode* six = new TreeNode(4);
	TreeNode* seven = new TreeNode(7);
	TreeNode* eight = new TreeNode(2);
	TreeNode* nine = new TreeNode(1); 

	first->left = second;
	first->right = third;
	second->left = four;
	third->left = five;
	third->right = six;
	four->left = seven;
	four->right = eight;
	six->right = nine;

	TreeNode* tmp1 = first;
	Solution su;

	int n;
	cin >> n;
	if(su.hasPathSum(tmp1, n)) {
		cout << "Yes" << endl;
	}
	else {
		cout << "No" << endl;
	}

	return 0;
}